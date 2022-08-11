const express = require('express');
const validate = require('../../middlewares/validate');
const imageValidation = require('../../validations/image.validation');
const imageController = require('../../controllers/image.controller');
const auth = require('../../middlewares/auth');

const router = express.Router();

router.route('/:imageId').get(auth(), validate(imageValidation.getImage), imageController.getImage);

module.exports = router;
