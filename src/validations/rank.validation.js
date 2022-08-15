const Joi = require('joi');

const getRank = {
    params: Joi.object().keys({
        problemId: Joi.number().required(),
        top: Joi.number().required(),
    }),
};

module.exports = { getRank };
