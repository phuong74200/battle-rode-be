const mongoose = require('mongoose');
const AutoIncrement = require('mongoose-sequence')(mongoose);
const { toJSON } = require('./plugins');

const algoSchema = mongoose.Schema(
    {
        templateLink: {
            type: String,
            required: true,
        },
        openTime: {
            type: Date,
            required: true,
        },
        closeTime: {
            type: Date,
            required: true,
        },
    },
    {
        timestamps: true,
    }
);

// add plugin that converts mongoose to json
algoSchema.plugin(toJSON);
algoSchema.plugin(AutoIncrement, { inc_field: 'algoId' });

/**
 * @typedef Algo
 */
const Algo = mongoose.model('Algo', algoSchema);

module.exports = Algo;
