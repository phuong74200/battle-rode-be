const httpStatus = require('http-status');
const path = require('path');
const appRoot = require('app-root-path');
const sanitize = require('sanitize-filename');
const pick = require('../utils/pick');
const catchAsync = require('../utils/catchAsync');
const ApiError = require('../utils/ApiError');
const { algoService } = require('../services');
const logger = require('../config/logger');

const createAlgo = catchAsync(async (req, res, next) => {
    const algoBody = pick(req.body, ['openTime', 'closeTime', 'templateLink', 'algoId']);

    const check = await algoService.getAlgoById(algoBody.algoId);

    if (check) {
        throw new ApiError(httpStatus.CONFLICT, 'algoId existed');
    }

    const result = await algoService.createAlgo(algoBody);
    res.status(httpStatus.CREATED).json(result);
});

const getAlgo = catchAsync(async (req, res, next) => {
    const { algoId } = pick(req.params, ['algoId']);
    const { user } = req;
    const algo = await algoService.getAlgoById(algoId);

    if (!algo) {
        throw new ApiError(httpStatus.NOT_FOUND, 'Test not found');
    }

    if (user.role === 'admin') {
        return res.json(algo);
    }

    const isOpen = await algoService.isOpen(algo);

    if (!isOpen) {
        throw new ApiError(httpStatus.NOT_ACCEPTABLE, 'Test is not open');
    }

    return res.json(algo);
});

const submitAlgo = catchAsync(async (req, res, next) => {
    const algoFile = pick(req.file, ['filename']);
    const algoBody = pick(req.body, ['algoId']);
    const { user } = req;

    const algo = await algoService.getAlgoById(algoBody.algoId);

    if (!algo) {
        return next(new ApiError(httpStatus.NOT_FOUND, 'Test not found!'));
    }

    const isOpen = await algoService.isOpen(algo);

    if (isOpen) {
        const result = await algoService.createSubmit({
            code: algoFile.filename,
            user: user._id,
            algo: algo._id,
        });
        const populated = await result.populate('user').execPopulate();

        return res.status(httpStatus.CREATED).json(populated);
    }
    next(new ApiError(httpStatus.NOT_ACCEPTABLE, 'Test is not open'));
});

const getSubmits = catchAsync(async (req, res, next) => {
    const { algoId, limit } = pick(req.params, ['algoId', 'limit']);
    const submits = await algoService.getSubmitAlgo(algoId, parseInt(limit, 10));
    res.json(submits);
});

const getFile = catchAsync(async (req, res, next) => {
    const { fileId } = pick(req.params, ['fileId']);
    const sanitized = sanitize(fileId);
    const filePath = path.join(`${appRoot}/upload/algos/${sanitized}`);
    res.download(filePath, (err) => {
        if (err) {
            next(new ApiError(httpStatus.NOT_FOUND, 'File not found'));
        }
    });
});

module.exports = {
    submitAlgo,
    createAlgo,
    getAlgo,
    getSubmits,
    getFile,
};
