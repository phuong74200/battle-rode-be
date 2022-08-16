const httpStatus = require('http-status');
const pick = require('../utils/pick');
const catchAsync = require('../utils/catchAsync');
const ApiError = require('../utils/ApiError');
const { problemService, battleService } = require('../services');
const logger = require('../config/logger');

const createProblem = catchAsync(async (req, res, next) => {
    const problemBody = pick(req.body, ['name', 'closeTime', 'openTime', 'battleTime', 'problemId', 'colors']);
    const problemFile = pick(req.file, ['filename']);

    logger.debug(JSON.stringify(problemBody));

    const problem = await problemService.getProblemById(problemBody.problemId);

    logger.debug(JSON.stringify(problem));

    if (problem) {
        return next(new ApiError(httpStatus.CONFLICT, 'ProblemId existed'));
    }

    const result = await problemService.createProblem({
        ...problemBody,
        ...problemFile,
    });
    res.status(httpStatus.CREATED).json(result);
});

const getProblemById = catchAsync(async (req, res) => {
    const { problemId } = pick(req.params, ['problemId']);
    const { user } = req;
    const problem = await problemService.getProblemById(problemId);

    if (!problem) {
        throw new ApiError(httpStatus.NOT_FOUND, 'Problem not found');
    }

    if (user.role === 'admin') {
        return res.json(problem);
    }

    const filter = { userId: user._id, problemId: problem._id };

    const battle = await battleService.getBattle(filter);

    if (!battle) {
        throw new ApiError(httpStatus.NOT_ACCEPTABLE, 'User not join battle');
    }

    const isTimeout = await battleService.isTimeout(battle);

    if (isTimeout) {
        throw new ApiError(httpStatus.NOT_ACCEPTABLE, 'Battle timeout');
    }

    return res.json(problem);
});

const getProblems = catchAsync(async (req, res) => {
    const problems = await problemService.getProblems({});

    return res.json(problems);
});

module.exports = {
    getProblemById,
    createProblem,
    getProblems,
};
