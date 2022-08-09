const { version } = require('../../package.json');
const config = require('../config/config');

const swaggerDef = {
    openapi: '3.0.0',
    info: {
        title: 'Battle Rode API documentation',
        version,
        license: {
            name: 'MIT',
            url: 'https://github.com/phuong74200/battle-rode-be',
        },
    },
    servers: [
        {
            url: `http://20.249.11.108:${config.port}/v1`,
        },
    ],
};

module.exports = swaggerDef;
