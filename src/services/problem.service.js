const moment = require('moment');
const { Problem } = require('../models');

/**
 * Create a user
 * @param {Object} userBody
 * @returns {Promise<User>}
 */
const createProblem = async (problem) => {
    return Problem.create({
        name: problem.name,
        image: problem.filename,
        openTime: moment(problem.openTime),
        closeTime: moment(problem.closeTime),
        battleTime: problem.battleTime,
        problemId: problem.problemId,
    });
};

/**
 * Get a problem by id
 * @param {Object} problemId
 * @returns {Promise<Problem>}
 */
const getProblemById = async (problemId) => {
    return Problem.findOne({ problemId });
};

const getValidProblemById = async (problemId) => {
    return Problem.findOne({ problemId, openTime: { $lte: moment() }, closeTime: { $gte: moment() } });
};

const getProblems = async (condition) => {
    return Problem.find(condition);
};

module.exports = {
    createProblem,
    getProblemById,
    getValidProblemById,
    getProblems,
};
