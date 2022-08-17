const mongoose = require('mongoose');
const https = require('https');
const http = require('http');
const fs = require('fs');
const app = require('./app');
const config = require('./config/config');
const logger = require('./config/logger');

const privateKey = fs.readFileSync('./cert/private.pem', 'utf8');
const certificate = fs.readFileSync('./cert/origin.pem', 'utf8');

const credentials = { key: privateKey, cert: certificate };

let server;
mongoose.connect(config.mongoose.url, config.mongoose.options).then(() => {
    logger.info('Connected to MongoDB');
    const httpsServer = https.createServer(credentials, app);
    const httpServer = http.createServer(app);
    if (config.env === 'production') {
        server = httpsServer.listen(config.port, () => {
            logger.info(`SSL: Listening to port ${config.port}`);
        });
    } else {
        server = httpServer.listen(config.port, () => {
            logger.info(`NoSSL: Listening to port ${config.port}`);
        });
    }
});

const exitHandler = () => {
    if (server) {
        server.close(() => {
            logger.info('Server closed');
            process.exit(1);
        });
    } else {
        process.exit(1);
    }
};

const unexpectedErrorHandler = (error) => {
    logger.error(error);
    exitHandler();
};

process.on('uncaughtException', unexpectedErrorHandler);
process.on('unhandledRejection', unexpectedErrorHandler);

process.on('SIGTERM', () => {
    logger.info('SIGTERM received');
    if (server) {
        server.close();
    }
});
