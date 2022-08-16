const Joi = require('joi');

const getScore = {
    body: Joi.object().keys({
        problemId: Joi.string().required(),
        code: Joi.string().required(),
    }),
};

module.exports = {
    getScore,
};
