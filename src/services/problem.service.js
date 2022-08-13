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

module.exports = {
    createProblem,
    getProblemById,
};
