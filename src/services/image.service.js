const Jimp = require('jimp');
const fs = require('fs');
const appRoot = require('app-root-path');
const path = require('path');
const sanitize = require('sanitize-filename');
const httpStatus = require('http-status');
const ApiError = require('../utils/ApiError');

const getImage = async (imgName) => {
    const sanitized = sanitize(imgName);
    const imgPath = path.join(`${appRoot}/upload/images/${sanitized}`);
    try {
        return fs.readFileSync(imgPath);
    } catch (e) {
        throw new ApiError(httpStatus.NOT_FOUND, 'Image not found');
    }
};

const compare = async (image1, image2) => {
    // threshold — Matching threshold, ranges from 0 to 1. Smaller values make the comparison more sensitive.

    const threshold = 0.05;

    const jimage1 = await Jimp.read(image1);
    const jimage2 = await Jimp.read(image2);
    const diff = Jimp.diff(jimage1, jimage2, threshold);
    return diff;
};

module.exports = { compare, getImage };
