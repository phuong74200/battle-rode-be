const httpStatus = require('http-status');
const { OAuth2Client } = require('google-auth-library');
const tokenService = require('./token.service');
const userService = require('./user.service');
const Token = require('../models/token.model');
const ApiError = require('../utils/ApiError');
const { tokenTypes } = require('../config/tokens');

// const logger = require('../config/logger');
const config = require('../config/config');

const client = new OAuth2Client(config.google.clientID);

/**
 * Login with username and password
 * @param {string} idToken
 * @returns {Promise<User>}
 */
const loginWithGoogle = async (idToken) => {
    try {
        const ticket = await client.verifyIdToken({
            idToken,
            audience: config.google.clientID,
        });

        const payload = ticket.getPayload();
        return payload;
    } catch (e) {
        throw new ApiError(httpStatus.UNAUTHORIZED, 'Invalid user');
    }
};

/**
 * Logout
 * @param {string} refreshToken
 * @returns {Promise}
 */
const logout = async (refreshToken) => {
    const refreshTokenDoc = await Token.findOne({ token: refreshToken, type: tokenTypes.REFRESH, blacklisted: false });
    if (!refreshTokenDoc) {
        throw new ApiError(httpStatus.NOT_FOUND, 'Not found');
    }
    await refreshTokenDoc.remove();
};

/**
 * Refresh auth tokens
 * @param {string} refreshToken
 * @returns {Promise<Object>}
 */
const refreshAuth = async (refreshToken) => {
    try {
        const refreshTokenDoc = await tokenService.verifyToken(refreshToken, tokenTypes.REFRESH);
        const user = await userService.getUserById(refreshTokenDoc.user);
        if (!user) {
            throw new Error();
        }
        await refreshTokenDoc.remove();
        return tokenService.generateAuthTokens(user);
    } catch (error) {
        throw new ApiError(httpStatus.UNAUTHORIZED, 'Please authenticate');
    }
};

/**
 * Reset password
 * @param {string} resetPasswordToken
 * @param {string} newPassword
 * @returns {Promise}
 */
const resetPassword = async (resetPasswordToken, newPassword) => {
    try {
        const resetPasswordTokenDoc = await tokenService.verifyToken(resetPasswordToken, tokenTypes.RESET_PASSWORD);
        const user = await userService.getUserById(resetPasswordTokenDoc.user);
        if (!user) {
            throw new Error();
        }
        await userService.updateUserById(user.id, { password: newPassword });
        await Token.deleteMany({ user: user.id, type: tokenTypes.RESET_PASSWORD });
    } catch (error) {
        throw new ApiError(httpStatus.UNAUTHORIZED, 'Password reset failed');
    }
};

/**
 * Verify email
 * @param {string} verifyEmailToken
 * @returns {Promise}
 */
const verifyEmail = async (verifyEmailToken) => {
    try {
        const verifyEmailTokenDoc = await tokenService.verifyToken(verifyEmailToken, tokenTypes.VERIFY_EMAIL);
        const user = await userService.getUserById(verifyEmailTokenDoc.user);
        if (!user) {
            throw new Error();
        }
        await Token.deleteMany({ user: user.id, type: tokenTypes.VERIFY_EMAIL });
        await userService.updateUserById(user.id, { isEmailVerified: true });
    } catch (error) {
        throw new ApiError(httpStatus.UNAUTHORIZED, 'Email verification failed');
    }
};

module.exports = {
    loginWithGoogle,
    logout,
    refreshAuth,
    resetPassword,
    verifyEmail,
};
