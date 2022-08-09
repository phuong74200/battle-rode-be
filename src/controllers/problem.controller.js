const httpStatus = require('http-status');
const pick = require('../utils/pick');
const catchAsync = require('../utils/catchAsync');
const { problemService } = require('../services');

const createProblem = catchAsync(async (req, res) => {
    const problemBody = pick(req.body, ['name', 'imageURL']);
    const result = await problemService.createProblem(problemBody);
    res.status(httpStatus.CREATED).send(result);
});

const getProblem = catchAsync(async (req, res) => {
    const { id } = pick(req.query, ['problemId']);
    const result = await problemService.getProblemById(id);
    res.send(result);
});

const getProblemById = catchAsync(async (req, res) => {
    const { problemId } = pick(req.params, ['problemId']);
    const result = await problemService.getProblemById(problemId);
    res.json({ problem: result, problemId });
});

module.exports = {
    getProblemById,
    createProblem,
    getProblem,
};
