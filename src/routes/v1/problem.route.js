const express = require('express');
const auth = require('../../middlewares/auth');
const validate = require('../../middlewares/validate');
const problemValidation = require('../../validations/problem.validation');
const problemController = require('../../controllers/problem.controller');

const router = express.Router();

router.route('/').post(auth('createProblem'), validate(problemValidation.createProblem), problemController.createProblem);

router.route('/:problemId').get(auth(), validate(problemValidation.getProblemById), problemController.getProblemById);

module.exports = router;
