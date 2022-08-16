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
        file: {
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
algoSubmitSchema.plugin(AutoIncrement, { inc_field: 'submitId' });

/**
 * @typedef AlgoSumit
 */
const AlgoSumit = mongoose.model('AlgoSumit', algoSubmitSchema);

module.exports = AlgoSumit;
