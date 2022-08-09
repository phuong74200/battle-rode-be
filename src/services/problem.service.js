const { Problem } = require('../models');

/**
 * Create a user
 * @param {Object} userBody
 * @returns {Promise<User>}
 */
const createProblem = async (problemBody) => {
    return Problem.create(problemBody);
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
