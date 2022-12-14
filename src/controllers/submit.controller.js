const httpStatus = require('http-status');
const he = require('he');
const moment = require('moment');
const ApiError = require('../utils/ApiError');
const catchAsync = require('../utils/catchAsync');
const { battleService, domService, problemService, imageService, submitService } = require('../services');

const getFinalScore = (letters, similars) => {
    const MAX_SCORE = 1000;
    return 21970 ** (similars - 1) * (MAX_SCORE * (1 / 1.0005 ** letters));
};

const submit = catchAsync(async (req, res) => {
    const { body, user } = req;

    const problem = await problemService.getProblemById(body.problemId);

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

    const problemImage = await imageService.getImage(problem.image);

    const numDiffPixels = await imageService.compare(imageBuffer, problemImage);

    const start = moment(battle.startTime);
    const now = moment();

    const score = getFinalScore(html.length, 1 - numDiffPixels.percent);

    const record = await submitService.createSubmit({
        battle: battle._id,
        score,
        code: html,
        diffs: numDiffPixels.percent,
    });

    await battle.update({
        $push: { submits: record },
    });

    // const x = await battle.populate('submits').execPopulate();

    res.json({
        diffs: numDiffPixels.percent,
        score,
        timeLeft: problem.battleTime + start.diff(now, 'seconds'),
        // battle: x,
    });

    // res.setHeader('content-type', 'image/png');

    // res.send(problemImage);
});

module.exports = {
    submit,
};
