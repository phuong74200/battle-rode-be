const httpStatus = require('http-status');
const moment = require('moment');
const catchAsync = require('../utils/catchAsync');
const ApiError = require('../utils/ApiError');
const pick = require('../utils/pick');
const battleService = require('../services/battle.service');
const problemService = require('../services/problem.service');

const logger = require('../config/logger');

const { Battle } = require('../models');

const getBattle = catchAsync(async (req, res, next) => {
    const { problemId } = pick(req.params, ['problemId']);

    const battle = await Battle.find({ problemId }).populate('problem').populate('user').exec();

    res.json(battle);
});

const startBattle = catchAsync(async (req, res, next) => {
    const { problemId } = pick(req.params, ['problemId']);
    const { user } = req;

    const problem = await problemService.getProblemById(problemId);

    if (!problem) {
        return next(new ApiError(httpStatus.NOT_FOUND, 'Problem not found'));
    }

    const filter = { userId: user._id, problemId: problem._id };

    const battles = await battleService.getBattlesByUserAndProblemId(filter);

    if (battles.length > 0) {
        return next(new ApiError(httpStatus.CONFLICT, 'User already joined in'));
    }

    const battle = await battleService.createBattle({
        user: user._id,
        problem: problem._id,
        startTime: moment(),
    });

    const populateBattle = await battle.populate('user').populate('problem').execPopulate();

    res.json(populateBattle);
});

module.exports = {
    getBattle,
    startBattle,
};
