const Joi = require('joi');

const createProblem = {
    body: Joi.object().keys({
        name: Joi.string().required(),
        imageURL: Joi.string().required(),
    }),
};

const getProblemById = {
    params: Joi.object().keys({
        problemId: Joi.number(),
    }),
};

module.exports = {
    createProblem,
    getProblemById,
};
