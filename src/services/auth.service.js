const httpStatus = require('http-status');
const { OAuth2Client } = require('google-auth-library');
const tokenService = require('./token.service');
const userService = require('./user.service');
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

module.exports = {
    loginWithGoogle,
    refreshAuth,
};
