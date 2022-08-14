const express = require('express');
const auth = require('../../middlewares/auth');
const validate = require('../../middlewares/validate');
const submitValidation = require('../../validations/submit.validation');
const submitController = require('../../controllers/submit.controller');

const router = express.Router();

router.route('/').post(auth(), validate(submitValidation.getScore), submitController.submit);

module.exports = router;

/**
 * @swagger
 * tags:
 *   name: Submbit
 *   description: Submbit
 */

/**
 * @swagger
 * /submit:
 *   post:
 *     summary: Scoring a problem with html/css code
 *     tags: [Score]
 *     requestBody:
 *       content:
 *         application/json:
 *           schema:
 *             type: object
 *             properties:
 *               code:
 *                 description: HTML/CSS codes
 *                 type: string
 *               problemId:
 *                 description: problemId
 *                 type: integer
 */
