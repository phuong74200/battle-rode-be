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

router.route('/:problemId').get(auth(), validate(problemValidation.getProblemById), problemController.getProblemById);

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
 *       required: true
 *       content:
 *         application/json:
 *           schema:
 *             type: object
 *             required:
 *               - name
 *               - image
 *             properties:
 *               name:
 *                 type: string
 *               image:
 *                 type: string
 *     responses:
 *       "200":
 *         description: OK
 *         content:
 *           application/json:
 *             schema:
 *               $ref: '#/components/schemas/GoogleUser'
 *       "401":
 *         description: Invalid user's token ID
 *         content:
 *           application/json:
 *             schema:
 *               $ref: '#/components/schemas/Error'
 *             example:
 *               code: 401
 *               message: Invalid user
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
