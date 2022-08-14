const Jimp = require('jimp');

const compare = async (image1, image2) => {
    // threshold — Matching threshold, ranges from 0 to 1. Smaller values make the comparison more sensitive.

    const threshold = 0;

    const jimage1 = await Jimp.read(image1);
    const jimage2 = await Jimp.read(image2);
    const diff = Jimp.diff(jimage1, jimage2, threshold);
    return diff;
};

module.exports = { compare };
