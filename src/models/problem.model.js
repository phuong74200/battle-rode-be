const mongoose = require('mongoose');
const AutoIncrement = require('mongoose-sequence')(mongoose);
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
            type: Number,
        },
    },
    {
        timestamps: true,
    }
);

// add plugin that converts mongoose to json
problemSchema.plugin(toJSON);
problemSchema.plugin(AutoIncrement, { inc_field: 'problemId' });

/**
 * @typedef Problem
 */
const Problem = mongoose.model('Problem', problemSchema);

module.exports = Problem;
