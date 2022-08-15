const express = require('express');
const auth = require('../../middlewares/auth');
const validate = require('../../middlewares/validate');
const rankController = require('../../controllers/rank.controller');
const rankValidation = require('../../validations/rank.validation');

const router = express.Router();

router.route('/:problemId/:top').get(auth('getRank'), validate(rankValidation.getScore), rankController.getRank);

module.exports = router;

/**
 * @swagger
 * tags:
 *   name: Rank
 *   description: Rank
 */

/**
 * @swagger
 * /rank/{problemId}/{limit}:
 *   get:
 *     summary: Get ranking users of a problem
 *     tags: [Rank]
 *     parameters:
 *       - in: path
 *         name: problemId
 *         schema:
 *           type: integer
 *           example: 1
 *         description: Problem id
 *       - in: path
 *         name: limit
 *         schema:
 *           type: integer
 *           example: 10
 *         description: the number of users in descending
 */
