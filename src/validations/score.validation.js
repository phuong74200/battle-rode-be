const Joi = require('joi');

const getScore = {
    body: Joi.object().keys({
        problemId: Joi.number().required(),
        code: Joi.string().required(),
    }),
};

module.exports = {
    getScore,
};
