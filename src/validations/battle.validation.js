const Joi = require('joi');

const getBattle = {
    params: Joi.object().keys({
        battleId: Joi.number().required(),
    }),
};

const startBattle = {
    params: Joi.object().keys({
        problemId: Joi.number().required(),
    }),
};

module.exports = {
    getBattle,
    startBattle,
};
