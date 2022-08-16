const httpStatus = require('http-status');
const pick = require('../utils/pick');
const ApiError = require('../utils/ApiError');
const catchAsync = require('../utils/catchAsync');
const { battleService, problemService } = require('../services');
const logger = require('../config/logger');

const getRank = catchAsync(async (req, res) => {
    const { problemId, top } = pick(req.params, ['problemId', 'top']);

    logger.debug(problemId);

    const battles = await battleService.getProblemTopBattles(problemId, parseInt(top, 10));

    res.json(battles);
});

module.exports = {
    getRank,
};
