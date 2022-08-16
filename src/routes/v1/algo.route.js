const express = require('express');
const auth = require('../../middlewares/auth');
const validate = require('../../middlewares/validate');
const multer = require('../../middlewares/multer');
const algoValidation = require('../../validations/algo.validation');
const algoController = require('../../controllers/algo.controller');

const router = express.Router();

router
    .route('/submit')
    .post(auth(), [multer.file.single('file'), validate(algoValidation.submitAlgo)], algoController.submitAlgo);

router.route('/rank/:algoId/:limit').get(auth('getRank'), validate(algoValidation.getSubmits), algoController.getSubmits);
router.route('/file/:fileId').get(auth('getRank'), validate(algoValidation.getFile), algoController.getFile);
router.route('/:algoId').get(auth(), validate(algoValidation.getAlgo), algoController.getAlgo);
router.route('/').post(auth('createAlgo'), validate(algoValidation.createAlgo), algoController.createAlgo);

module.exports = router;

/**
 * @swagger
 * tags:
 *   name: Algorith
 *   description: Algorith
 */

/**
 * @swagger
 * /algo/submit:
 *   post:
 *     summary: Submit user's code
 *     tags: [Algorithm]
 *     requestBody:
 *       content:
 *         multipart/form-data:
 *           schema:
 *             type: object
 *             properties:
 *               file:
 *                 type: string
 *                 format: binary
 *               algoId:
 *                 description: The algoId
 *                 type: integer
 */

/**
 * @swagger
 * /v1/algo:
 *   post:
 *     summary: Create a new algorithm test
 *     tags: [Algorithm]
 *     requestBody:
 *       content:
 *         application/json:
 *           schema:
 *             type: object
 *             properties:
 *               templateLink:
 *                 description: the google drive's template link
 *                 type: string
 *               openTime:
 *                 description: the time that this template will open public to user
 *                 type: string
 *                 format: YYYY-MM-DDTHH:mm:ss.SSSZ
 *               closeTime:
 *                 description: the time that this template will be closed
 *                 type: string
 *                 format: YYYY-MM-DDTHH:mm:ss.SSSZ
 */

/**
 * @swagger
 * /algo/{algoId}:
 *   get:
 *     summary: Get a algorithm test by algoId
 *     tags: [Algorithm]
 *     parameters:
 *       - in: path
 *         name: algoId
 *         schema:
 *           type: integer
 *           example: 1
 *         description: algoId
 */

/**
 * @swagger
 * /rank/{algoId}/{limit}:
 *   get:
 *     summary: Get ranking users of a problem
 *     tags: [Rank, Algorithm]
 *     parameters:
 *       - in: path
 *         name: algoId
 *         schema:
 *           type: integer
 *           example: 1
 *         description: algoId
 *       - in: path
 *         name: limit
 *         schema:
 *           type: integer
 *           example: 10
 *         description: the number of users in descending
 */

/**
 * @swagger
 * /algo/file/{fileId}:
 *   get:
 *     summary: Download a file by it's fileId
 *     tags: [Algorithm]
 *     parameters:
 *       - in: path
 *         name: fileId
 *         schema:
 *           type: string
 *         description: fileId
 */
