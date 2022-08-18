const moment = require('moment');
const fs = require('fs');
const appRoot = require('app-root-path');
const path = require('path');
const sanitize = require('sanitize-filename');
const httpStatus = require('http-status');
const { Algo, AlgoSubmit } = require('../models');
const ApiError = require('../utils/ApiError');
const logger = require('../config/logger');

const createAlgo = async (algo) => {
    return Algo.create(algo);
};

//

const getAlgoById = async (id) => {
    return Algo.findOne({ algoId: id });
};

const createSubmit = async (submit) => {
    return AlgoSubmit.create(submit);
};

const isOpen = async (algo) => {
    if (!algo) return false;

    const open = moment(algo.openTime);
    const close = moment(algo.closeTime);
    const now = moment();

    if (now > open && now < close) {
        return true;
    }

    return false;
};

const getSubmitAlgo = async (algoId, top = 10) => {
    const $project = {
        createdAt: false,
        updatedAt: false,
        __v: false,
        _id: false,
    };
    return AlgoSubmit.aggregate([
        { $sort: { createdAt: 1 } },
        {
            $group: {
                _id: '$user',
                lastSubmitFile: { $last: '$code' },
            },
        },
        { $lookup: { from: 'users', localField: '_id', foreignField: '_id', as: 'user', pipeline: [{ $project }] } },
        { $unwind: '$user' },
        { $project },
        { $limit: top },
    ]);
};

const getFile = async (fileName) => {
    const sanitized = sanitize(fileName);
    const filePath = path.join(`${appRoot}/upload/algos/${sanitized}`);
    logger.debug(filePath);
    try {
        return fs.readFileSync(filePath);
    } catch (e) {
        throw new ApiError(httpStatus.NOT_FOUND, 'File not found');
    }
};

module.exports = {
    createAlgo,
    createSubmit,
    getAlgoById,
    isOpen,
    getSubmitAlgo,
    getFile,
};
