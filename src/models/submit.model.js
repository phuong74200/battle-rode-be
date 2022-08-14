const mongoose = require('mongoose');
const AutoIncrement = require('mongoose-sequence')(mongoose);
const { toJSON } = require('./plugins');

const submitSchema = mongoose.Schema(
    {
        battle: {
            type: mongoose.Schema.Types.ObjectId,
            ref: 'Battle',
            required: true,
        },
        score: {
            type: Number,
            default: 0,
        },
    },
    {
        timestamps: true,
    }
);

// add plugin that converts mongoose to json
submitSchema.plugin(toJSON);
submitSchema.plugin(AutoIncrement, { inc_field: 'submitId' });

/**
 * @typedef Submit
 */
const Submit = mongoose.model('Submit', submitSchema);

module.exports = Submit;
