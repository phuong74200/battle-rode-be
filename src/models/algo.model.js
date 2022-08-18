const mongoose = require('mongoose');
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
        algoId: {
            type: Number,
            required: true,
        },
    },
    {
        timestamps: true,
    }
);

// add plugin that converts mongoose to json
algoSchema.plugin(toJSON);

/**
 * @typedef Algo
 */
const Algo = mongoose.model('Algo', algoSchema);

module.exports = Algo;
