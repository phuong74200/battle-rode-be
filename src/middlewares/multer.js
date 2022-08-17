const multer = require('multer');
const ApiError = require('../utils/ApiError');
const logger = require('../config/logger');

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

const file = multer({
    limits: { fileSize: 5e6 },
    storage: multer.diskStorage({
        destination(req, file, cb) {
            cb(null, 'upload/algos');
        },
        filename(req, _file, cb) {
            logger.debug(`${req.user._id}-${req.body.type}-${_file.originalname}`);
            cb(null, `${req.user._id}-${new Date().getTime()}-${_file.originalname}`);
        },
    }),
});

module.exports = {
    image,
    file,
};
