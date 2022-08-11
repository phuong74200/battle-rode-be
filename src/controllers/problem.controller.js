const httpStatus = require('http-status');
const pick = require('../utils/pick');
const catchAsync = require('../utils/catchAsync');
const ApiError = require('../utils/ApiError');
const { problemService } = require('../services');

const createProblem = catchAsync(async (req, res) => {
    const problemBody = pick(req.body, ['name']);
    const problemFile = pick(req.file, ['filename']);

    const result = await problemService.createProblem({
        ...problemBody,
        ...problemFile,
    });
    res.status(httpStatus.CREATED).json({
        name: result.name,
        problemId: result.problemId,
        image: `${req.protocol}://${req.headers.host}/v1/image/${result.image}`,
    });
});

const getProblemById = catchAsync(async (req, res) => {
    const { problemId } = pick(req.params, ['problemId']);
    const result = await problemService.getProblemById(problemId);
    if (!result) {
        throw new ApiError(httpStatus.NOT_FOUND, 'Problem not found');
    }
    res.json({
        name: result.name,
        problemId: result.problemId,
        image: `${req.protocol}://${req.headers.host}/v1/image/${result.image}`,
    });
});

module.exports = {
    getProblemById,
    createProblem,
};
