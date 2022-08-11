const sizeOf = require('image-size');
const httpStatus = require('http-status');
const ApiError = require('../utils/ApiError');

const imageSizeLimit = (width, height) => (req, res, next) => {
    const { file } = req;

    sizeOf(file.path, (err, dimensions) => {
        if (err) {
            return next(new ApiError(httpStatus.BAD_REQUEST, err));
        }
        if (dimensions.width !== width || dimensions.height !== height) {
            return next(new ApiError(httpStatus.BAD_REQUEST, `image size must be ${width}x${height}`));
        }
    });

    return next();
};

module.exports = imageSizeLimit;
