const express = require('express');
const auth = require('../../middlewares/auth');
const validate = require('../../middlewares/validate');
const scoreValidation = require('../../validations/score.validation');
const scoreController = require('../../controllers/score.controller');

const router = express.Router();

router.route('/').post(auth(), validate(scoreValidation.getScore), scoreController.getScore);

module.exports = router;

/**
 * @swagger
 * tags:
 *   name: Score
 *   description: Score
 */

/**
 * @swagger
 * /score:
 *   post:
 *     summary: Scoring a problem using html/css code
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
