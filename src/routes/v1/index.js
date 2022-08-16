const express = require('express');
const authRoute = require('./auth.route');
const docsRoute = require('./docs.route');
const problemRoute = require('./problem.route');
const imageRoute = require('./image.route');
const battleRoute = require('./battle.route');
const submitRoute = require('./submit.route');
const rankRoute = require('./rank.route');
const algoRoute = require('./algo.route');
const config = require('../../config/config');

const router = express.Router();

const defaultRoutes = [
    {
        path: '/auth',
        route: authRoute,
    },
    {
        path: '/problem',
        route: problemRoute,
    },
    {
        path: '/image',
        route: imageRoute,
    },
    {
        path: '/battle',
        route: battleRoute,
    },
    {
        path: '/submit',
        route: submitRoute,
    },
    {
        path: '/rank',
        route: rankRoute,
    },
    {
        path: '/algo',
        route: algoRoute,
    },
];

const devRoutes = [
    // routes available only in development mode
    {
        path: '/docs',
        route: docsRoute,
    },
];

defaultRoutes.forEach((route) => {
    router.use(route.path, route.route);
});

/* istanbul ignore next */
if (config.env === 'development') {
    devRoutes.forEach((route) => {
        router.use(route.path, route.route);
    });
}

module.exports = router;
