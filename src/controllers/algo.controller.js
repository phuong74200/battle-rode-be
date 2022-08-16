const httpStatus = require('http-status');
const pick = require('../utils/pick');
const catchAsync = require('../utils/catchAsync');
const ApiError = require('../utils/ApiError');
const { algoService } = require('../services');

const createAlgo = catchAsync(async (req, res, next) => {
    const algoBody = pick(req.body, ['openTime', 'closeTime']);
    const algoFile = pick(req.file, ['file']);

    const result = await algoService.createAlgo({
        ...algoBody,
        ...algoFile,
    });
    res.status(httpStatus.CREATED).json(result);
});

module.exports = {
    createAlgo,
};
