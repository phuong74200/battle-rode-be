const express = require('express');
const auth = require('../../middlewares/auth');
const validate = require('../../middlewares/validate');
const multer = require('../../middlewares/multer');
const problemValidation = require('../../validations/problem.validation');
const problemController = require('../../controllers/problem.controller');
const imageSizeLimit = require('../../middlewares/imageSizeLimit');

const router = express.Router();

router
    .route('/')
    .post(
        auth('createProblem'),
        [multer.image.single('image'), imageSizeLimit(400, 300), validate(problemValidation.createProblem)],
        problemController.createProblem
    );

router
    .route('/:problemId')
    .get(auth('getProblem'), validate(problemValidation.getProblemById), problemController.getProblemById);

module.exports = router;

/**
 * @swagger
 * tags:
 *   name: Problem
 *   description: Problem management
 */

/**
 * @swagger
 * /problem:
 *   post:
 *     summary: Create a new problem
 *     tags: [Problem]
 *     requestBody:
 *       content:
 *         multipart/form-data:
 *           schema:
 *             type: object
 *             properties:
 *               image:
 *                 description: Size of the image must be 400x300
 *                 type: string
 *                 format: binary
 *               name:
 *                 type: string
 *               openTime:
 *                 type: string
 *                 format: YYYY-MM-DDTHH:mm:ss.SSSZ
 *               closeTime:
 *                 type: string
 *                 format: YYYY-MM-DDTHH:mm:ss.SSSZ
 *               battleTime:
 *                 description: Limit time of the round in seconds
 *                 type: integer
 *                 default: 1800
 */

/**
 * @swagger
 * /problem/{id}:
 *   get:
 *     summary: Get a problem by problem ID
 *     tags: [Problem]
 *     parameters:
 *       - in: path
 *         name: id
 *         schema:
 *           type: integer
 *           example: 1
 *         description: Problem id
 */
