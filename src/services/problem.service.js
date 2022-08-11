const { Problem } = require('../models');
const logger = require('../config/logger');

/**
 * Create a user
 * @param {Object} userBody
 * @returns {Promise<User>}
 */
const createProblem = async (problem) => {
    logger.debug(JSON.stringify(problem));
    return Problem.create({
        name: problem.name,
        image: problem.filename,
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
