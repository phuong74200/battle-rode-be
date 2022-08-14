const express = require('express');
const auth = require('../../middlewares/auth');
const validate = require('../../middlewares/validate');
const battleValidation = require('../../validations/battle.validation');
const battleController = require('../../controllers/battle.controller');

const router = express.Router();

router.route('/start/:problemId').get(auth(), validate(battleValidation.startBattle), battleController.startBattle);
// router.route('/:battleId').get(auth(), validate(battleValidation.getBattle), battleController.getBattle);

module.exports = router;

/**
 * @swagger
 * tags:
 *   name: Battle
 *   description: Battle
 */

/**
 * @swagger
 * /battle/start/{problemId}:
 *   get:
 *     summary: Let user start a battle by problemId
 *     tags: [Battle]
 *     parameters:
 *       - in: path
 *         name: problemId
 *         schema:
 *           type: string
 *         description: problemId
 */
