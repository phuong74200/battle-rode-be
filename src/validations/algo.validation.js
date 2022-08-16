const Joi = require('joi');

const createAlgo = {
    body: Joi.object().keys({
        templateLink: Joi.string().required(),
        openTime: Joi.date().required(),
        closeTime: Joi.date().required(),
    }),
};

const submitAlgo = {
    body: Joi.object().keys({
        algoId: Joi.number().required(),
    }),
    code: Joi.object().required().label('code file is required'),
};

const getAlgo = {
    params: Joi.object().keys({
        algoId: Joi.number().required(),
    }),
};

const getSubmits = {
    params: Joi.object().keys({
        algoId: Joi.number().required(),
        limit: Joi.number().required(),
    }),
};

const getFile = {
    params: Joi.object().keys({
        fileId: Joi.string().required(),
    }),
};

module.exports = {
    submitAlgo,
    createAlgo,
    getAlgo,
    getSubmits,
    getFile,
};
