const httpStatus = require('http-status');
const appRoot = require('app-root-path');
const catchAsync = require('../utils/catchAsync');
const ApiError = require('../utils/ApiError');

const getImage = catchAsync(async (req, res, next) => {
    const { imageId } = req.params;
    res.sendFile(
        `${appRoot}/upload/images/${imageId}`,
        {
            headers: { 'Content-Type': 'image/png' },
        },
        (err) => {
            if (err) next(new ApiError(httpStatus.NOT_FOUND, 'image not found'));
        }
    );
});

module.exports = {
    getImage,
};
