const express = require('express');
const auth = require('../../middlewares/auth');
const validate = require('../../middlewares/validate');
const multer = require('../../middlewares/multer');
const algoValidation = require('../../validations/algo.validation');
const algoController = require('../../controllers/algo.controller');

const router = express.Router();

router
    .route('/')
    .post(auth('createAlgo'), [validate(algoValidation.createAlgo), multer.file.single('file')], algoController.createAlgo);

module.exports = router;
