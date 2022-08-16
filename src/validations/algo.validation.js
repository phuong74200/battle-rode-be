const Joi = require('joi');

const createAlgo = {
    body: Joi.object().keys({
        drive: Joi.string().required(),
        openTime: Joi.date().required(),
        closeTime: Joi.date().required(),
    }),
    file: Joi.object().required().label('code file is required'),
};

module.exports = {
    createAlgo,
};
