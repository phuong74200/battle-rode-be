const multer = require('multer');
const ApiError = require('../utils/ApiError');

const image = multer({
    dest: 'upload/images',
    fileFilter: (req, file, cb) => {
        const type = file.mimetype.split('/')[0];
        if (type !== 'image') {
            return cb(new ApiError('Only images are allowed'), false);
        }
        cb(null, true);
    },
});

module.exports = {
    image,
};
