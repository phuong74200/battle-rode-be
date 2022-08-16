const Joi = require('joi');

const getRank = {
    params: Joi.object().keys({
        problemId: Joi.string().required(),
        top: Joi.number().required(),
    }),
};

module.exports = { getRank };
