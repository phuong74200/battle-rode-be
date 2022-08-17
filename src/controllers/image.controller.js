const httpStatus = require('http-status');
const appRoot = require('app-root-path');
const catchAsync = require('../utils/catchAsync');
const ApiError = require('../utils/ApiError');
const { imageService } = require('../services');
const logger = require('../config/logger');

const getImage = catchAsync(async (req, res, next) => {
    const { imageId } = req.params;
    const file = await imageService.getImage(imageId);
    return res.send(`data:image/png;base64,${file}`);
});

module.exports = {
    getImage,
};
