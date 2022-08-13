const express = require('express');
const auth = require('../../middlewares/auth');
const validate = require('../../middlewares/validate');
const battleValidation = require('../../validations/battle.validation');
const battleController = require('../../controllers/battle.controller');

const router = express.Router();

router.route('/start/:problemId').get(auth(), validate(battleValidation.startBattle), battleController.startBattle);
router.route('/:battleId').get(auth(), validate(battleValidation.getBattle), battleController.getBattle);

module.exports = router;
