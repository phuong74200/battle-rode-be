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
    return Battle.find({ user: userId, problem: problemId }).populate('problem').populate('user').exec();
};

module.exports = {
    createBattle,
    getBattleById,
    getBattlesByUserAndProblemId,
};
