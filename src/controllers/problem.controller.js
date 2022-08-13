const httpStatus = require('http-status');
const pick = require('../utils/pick');
const catchAsync = require('../utils/catchAsync');
const ApiError = require('../utils/ApiError');
const { problemService } = require('../services');
const logger = require('../config/logger');

const createProblem = catchAsync(async (req, res) => {
    const problemBody = pick(req.body, ['name', 'closeTime', 'openTime', 'battleTime']);
    const problemFile = pick(req.file, ['filename']);

    const result = await problemService.createProblem({
        ...problemBody,
        ...problemFile,
    });
    res.status(httpStatus.CREATED).json({
        name: result.name,
        problemId: result.problemId,
        image: result.image,
        openTime: result.openTime,
        closeTime: result.closeTime,
        battleTime: result.battleTime,
    });
});

const getProblemById = catchAsync(async (req, res) => {
    const { problemId } = pick(req.params, ['problemId']);
    const result = await problemService.getProblemById(problemId);
    logger.debug(JSON.stringify(req.user));
    if (!result) {
        throw new ApiError(httpStatus.NOT_FOUND, 'Problem not found');
    }
    res.json({
        name: result.name,
        problemId: result.problemId,
        image: result.image,
        openTime: result.openTime,
        closeTime: result.closeTime,
        battleTime: result.battleTime,
    });
});

module.exports = {
    getProblemById,
    createProblem,
};
