const allRoles = {
    user: [],
    admin: ['getUsers', 'manageUsers', 'createProblem', 'allProblems', 'getRank', 'createAlgo'],
};

const roles = Object.keys(allRoles);
const roleRights = new Map(Object.entries(allRoles));

module.exports = {
    roles,
    roleRights,
};
