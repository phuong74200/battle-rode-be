const moment = require('moment');
const { Battle } = require('../models');

/**
 * Create a battle
 * @param {Object} battle
 * @returns {Promise<Battle>}
 */
const createBattle = async (battle) => {
    return Battle.create({
        user: battle.user,
        problem: battle.problem,
        startTime: battle.startTime,
    });
};

/**
 * Get a problem by id
 * @param {Object} problemId
 * @returns {Promise<Problem>}
 */
const getBattleById = async (battleId) => {
    return Battle.findOne({ battleId });
};

const getBattlesByUserAndProblemId = async ({ userId, problemId }) => {
    return Battle.find({ user: userId, problem: problemId });
};

const getBattle = async ({ userId, problemId }) => {
    return Battle.findOne({ user: userId, problem: problemId });
};

const getValidBattle = async ({ userId, problemId }) => {
    const battle = await Battle.findOne({ user: userId, problem: problemId })
        .populate({
            path: 'problem',
            match: {
                openTime: { $lte: moment() },
                closeTime: { $gte: moment() },
            },
        })
        .exec();
    return battle;
};

const isTimeout = async (_battle) => {
    const battle = await _battle.populate('problem').execPopulate();

    if (!battle || !battle.problem) return true;

    const { problem } = battle;

    const start = moment(battle.startTime);
    const now = moment();

    if (now.diff(start, 'seconds') > problem.battleTime) {
        return true;
    }

    return false;
};

module.exports = {
    createBattle,
    getBattleById,
    getBattlesByUserAndProblemId,
    getValidBattle,
    getBattle,
    isTimeout,
};
