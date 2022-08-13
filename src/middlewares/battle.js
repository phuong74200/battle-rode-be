const pick = require('../utils/pick');

const timeLimit = (req, res, next) => {
    const battle = pick(req.params, ['battleId']);
};
