const { Algo } = require('../models');

const createAlgo = (algo) => {
    return Algo.create(algo);
};

module.exports = {
    createAlgo,
};
