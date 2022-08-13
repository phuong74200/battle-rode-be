const Joi = require('joi');

const createProblem = {
    body: Joi.object().keys({
        name: Joi.string().required(),
        openTime: Joi.date().required(),
        closeTime: Joi.date().required(),
        battleTime: Joi.number(),
    }),
    file: Joi.object().required().label('image is required'),
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
