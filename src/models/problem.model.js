const mongoose = require('mongoose');
const { toJSON } = require('./plugins');

const problemSchema = mongoose.Schema(
    {
        name: {
            type: String,
            required: true,
            trim: true,
        },
        image: {
            type: String,
            required: true,
        },
        problemId: {
            type: String,
        },
        openTime: {
            type: Date,
            required: true,
        },
        closeTime: {
            type: Date,
            required: true,
        },
        battleTime: {
            type: Number,
            default: 30 * 60, // exam time is in seconds
        },
        colors: [
            {
                type: String,
            },
        ],
    },
    {
        timestamps: true,
    }
);

// add plugin that converts mongoose to json
problemSchema.plugin(toJSON);

/**
 * @typedef Problem
 */
const Problem = mongoose.model('Problem', problemSchema);

module.exports = Problem;
