const Joi = require('joi');

const getImage = {
    params: Joi.object().keys({
        imageId: Joi.string().required(),
    }),
};

module.exports = {
    getImage,
};
