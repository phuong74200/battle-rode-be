const httpStatus = require('http-status');
const he = require('he');
const fs = require('fs');
const appRoot = require('app-root-path');
const moment = require('moment');
const ApiError = require('../utils/ApiError');
const catchAsync = require('../utils/catchAsync');
const { battleService, domService, problemService, imageService } = require('../services');
const logger = require('../config/logger');

const getFinalScore = (letters, similars) => 21970 ** (similars - 1) * (1500 * (1 / 1.0005 ** letters));

const submit = catchAsync(async (req, res) => {
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
    const imageBuffer = await domService.capture(html);

    const problemImage = fs.readFileSync(`${appRoot}/upload/images/${problem.image}`);

    const numDiffPixels = await imageService.compare(imageBuffer, problemImage);

    const start = moment(battle.startTime);
    const now = moment();

    res.json({
        diffs: numDiffPixels.percent,
        score: getFinalScore(html.length, 1 - numDiffPixels.percent),
        timeLeft: problem.battleTime + start.diff(now, 'seconds'),
    });

    // res.setHeader('content-type', 'image/png');

    // res.send(imageBuffer);
});

module.exports = {
    submit,
};
