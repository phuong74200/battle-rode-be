const mongoose = require('mongoose');
const AutoIncrement = require('mongoose-sequence')(mongoose);
const { toJSON } = require('./plugins');

const algoSubmitSchema = mongoose.Schema(
    {
        user: {
            type: mongoose.Schema.Types.ObjectId,
            ref: 'User',
            required: true,
        },
        algo: {
            type: mongoose.Schema.Types.ObjectId,
            ref: 'Algo',
            required: true,
        },
        code: {
            type: String,
            required: true,
        },
    },
    {
        timestamps: true,
    }
);

// add plugin that converts mongoose to json
algoSubmitSchema.plugin(toJSON);
algoSubmitSchema.plugin(AutoIncrement, { inc_field: 'algoSubmitId' });

/**
 * @typedef AlgoSubmit
 */
const AlgoSubmit = mongoose.model('AlgoSubmit', algoSubmitSchema);

module.exports = AlgoSubmit;
