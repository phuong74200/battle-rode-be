const httpStatus = require('http-status');
const he = require('he');
const fs = require('fs');
const appRoot = require('app-root-path');
const ApiError = require('../utils/ApiError');
const catchAsync = require('../utils/catchAsync');
const { battleService, domService, problemService, imageService } = require('../services');
const logger = require('../config/logger');

const getFinalScore = (letters, similars) => 21970 ** (similars - 1) * (1500 * (1 / 1.0005 ** letters));

const getScore = catchAsync(async (req, res) => {
    const { body, user } = req;

    const problem = await problemService.getProblemById(body.problemId);

    logger.debug(JSON.stringify(body));

    if (!problem) {
        throw new ApiError(httpStatus.NOT_FOUND, 'Problem not found');
    }

    const filter = { userId: user._id, problemId: problem._id };

    const battle = await battleService.getValidBattle(filter);

    if (!battle) {
        throw new ApiError(httpStatus.METHOD_NOT_ALLOWED, 'User not in the battle');
    }

    const isTimeout = await battleService.isTimeout(battle);

    if (isTimeout) {
        throw new ApiError(httpStatus.METHOD_NOT_ALLOWED, 'Battle time out');
    }

    const html = he.decode(body.code);
    const purify = domService.purify(html);
    const imageBuffer = await domService.capture(purify);

    const problemImage = fs.readFileSync(`${appRoot}/upload/images/${problem.image}`);

    const numDiffPixels = await imageService.compare(imageBuffer, problemImage);

    logger.debug(`diffs: ${numDiffPixels.percent}`);
    logger.debug(`simis: ${1 - numDiffPixels.percent}`);
    res.json({
        diffs: numDiffPixels.percent,
        score: getFinalScore(html.length, 1 - numDiffPixels.percent),
        html,
    });
});

module.exports = {
    getScore,
};
