const express = require('express');
const validate = require('../../middlewares/validate');
const authValidation = require('../../validations/auth.validation');
const authController = require('../../controllers/auth.controller');
const auth = require('../../middlewares/auth');

const router = express.Router();

router.post('/register', validate(authValidation.register), authController.register);
router.post('/login', validate(authValidation.login), authController.login);
router.post('/logout', validate(authValidation.logout), authController.logout);
router.post('/refresh-tokens', validate(authValidation.refreshTokens), authController.refreshTokens);
router.post('/forgot-password', validate(authValidation.forgotPassword), authController.forgotPassword);
router.post('/reset-password', validate(authValidation.resetPassword), authController.resetPassword);
router.post('/send-verification-email', auth(), authController.sendVerificationEmail);
router.post('/verify-email', validate(authValidation.verifyEmail), authController.verifyEmail);

module.exports = router;

/**
 * @swagger
 * tags:
 *   name: Auth
 *   description: Authentication
 */

/**
 * @swagger
 * /auth/login:
 *   post:
 *     summary: Login
 *     tags: [Auth]
 *     requestBody:
 *       required: true
 *       content:
 *         application/json:
 *           schema:
 *             type: object
 *             required:
 *               - idToken
 *               - name
 *               - email
 *             properties:
 *               idToken:
 *                 type: string
 *                 format: jwt
 *             example:
 *               idToken: eyJhbGciOiJSUzI1NiIsImtpZCI6ImZkYTEwNjY0NTNkYzlkYzNkZDkzM2E0MWVhNTdkYTNlZjI0MmIwZjciLCJ0eXAiOiJKV1QifQ.eyJpc3MiOiJhY2NvdW50cy5nb29nbGUuY29tIiwiYXpwIjoiOTc3NzY5MjkzNTEzLTY3czd2bDVpajBucnZwYWZxbGlhbW9icDFoaG9jcmphLmFwcHMuZ29vZ2xldXNlcmNvbnRlbnQuY29tIiwiYXVkIjoiOTc3NzY5MjkzNTEzLTY3czd2bDVpajBucnZwYWZxbGlhbW9icDFoaG9jcmphLmFwcHMuZ29vZ2xldXNlcmNvbnRlbnQuY29tIiwic3ViIjoiMTE1ODczMDM1MzIzNjgyNzgwODI4IiwiaGQiOiJmcHQuZWR1LnZuIiwiZW1haWwiOiJwaHVvbmdtdHNlMTYxMTg3QGZwdC5lZHUudm4iLCJlbWFpbF92ZXJpZmllZCI6dHJ1ZSwiYXRfaGFzaCI6ImFleXZDdEZkVFRsY3hXTWpnc0xfMlEiLCJuYW1lIjoiTWFpIFRoYW5oIFBodW9uZyAoSzE2X0hDTSkiLCJwaWN0dXJlIjoiaHR0cHM6Ly9saDMuZ29vZ2xldXNlcmNvbnRlbnQuY29tL2EvQUl0YnZtbXRKcWlHUVI5eTBUaTNqcmlaRmRvMzdpS3Y3OTQtV2hVeTBvWjA9czk2LWMiLCJnaXZlbl9uYW1lIjoiTWFpIFRoYW5oIFBodW9uZyIsImZhbWlseV9uYW1lIjoiKEsxNl9IQ00pIiwibG9jYWxlIjoiZW4tR0IiLCJpYXQiOjE2NTk5ODYyMDAsImV4cCI6MTY1OTk4OTgwMCwianRpIjoiYjdjZjIyN2ExM2NiMzhiODE3MjllNjI0YjQ5MTdiNjQ4MGI5MWU3YyJ9.yWGJf9Y4qvw-dgf_tQssBnh8yakDSoDVH2TLG7ltsjoJA5Q4Cs0BU4mipUxkAzMtQ9M6G5UWIupaq7EPMzzhnq7rBxG8ZNCCQL9q5MbS9zrMwlylZbR1iWv5fXy8qfavhkys3hcGUOhCsE2ELP7sVAdq0Wn6ASr9MUznm_k_VhNFSURFromiuaAVONjDfZjWmVoikEaORbqMyMWz_QHs7eXoyoRp2IQTbYmauTH1yTmOX97JYvII9eIy1xVOrGfsRwkGh02IvSlXjS1yLR65KqAKIaDJDD2nIuqkl-mbdbjtKa-wIadA2Te9NISrT_BhPzku0FecA29DoaHs5sD6EA
 *     responses:
 *       "200":
 *         description: OK
 *         content:
 *           application/json:
 *             schema:
 *               type: object
 *               properties:
 *                 user:
 *                   $ref: '#/components/schemas/GoogleUser'
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
