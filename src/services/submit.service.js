const { Submit } = require('../models');

const createSubmit = async (submit) => {
    return Submit.create(submit);
};

module.exports = {
    createSubmit,
};
