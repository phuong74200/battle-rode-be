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

const getBattles = async (condition = {}) => {
    return Battle.find(condition).populate('submits').exec();
};

const getBattlesWithLastSubmit = async (condition = {}) => {
    return Battle.find(condition)
        .populate({
            path: 'submits',
            options: {
                sort: {
                    createdAt: -1,
                },
                limit: 1,
                select: '-battle',
            },
        })
        .populate('user')
        .exec();
};

const getProblemTopBattles = async (condition = {}, top = 10) => {
    // return Battle.find(condition)
    //     .limit(top)
    //     .populate({
    //         path: 'submits',
    //         options: {
    //             sort: [{ score: -1 }],
    //             select: '-battle',
    //         },
    //     })
    //     .populate('user')
    //     .exec();

    const $project = {
        problem: false,
        startTime: false,
        createdAt: false,
        updatedAt: false,
        __v: false,
        _id: false,
        submits: false,
    };

    return Battle.aggregate([
        { $lookup: { from: 'users', localField: 'user', foreignField: '_id', as: 'user', pipeline: [{ $project }] } },
        {
            $lookup: {
                from: 'submits',
                localField: 'submits',
                foreignField: '_id',
                as: 'lastSubmit',
                pipeline: [
                    { $sort: { createdAt: -1 } },
                    { $limit: 1 },
                    {
                        $addFields: {
                            submitAt: '$createdAt',
                        },
                    },
                    { $project },
                ],
            },
        },
        { $unwind: '$user' },
        { $unwind: '$lastSubmit' },
        { $project },
        { $sort: { 'lastSubmit.score': -1 } },
        { $limit: top },
        // { $unwind: '$wallet' },
        // { $sort: { 'wallet.amount': 1 } }, //
    ]);
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
    getBattles,
    isTimeout,
    getBattlesWithLastSubmit,
    getProblemTopBattles,
};
