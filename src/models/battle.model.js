const mongoose = require('mongoose');
const AutoIncrement = require('mongoose-sequence')(mongoose);
const { toJSON } = require('./plugins');

const battleSchema = mongoose.Schema(
    {
        user: {
            type: mongoose.Schema.Types.ObjectId,
            ref: 'User',
            required: true,
        },
        problem: {
            type: mongoose.Schema.Types.ObjectId,
            ref: 'Problem',
            required: true,
        },
        startTime: {
            type: Date,
            required: true,
        },
        submits: [{ type: mongoose.Types.ObjectId, ref: 'Submit' }],
    },
    {
        timestamps: true,
        id: false,
    }
);

// add plugin that converts mongoose to json
battleSchema.plugin(toJSON);
battleSchema.plugin(AutoIncrement, { inc_field: 'battleId' });

/**
 * @typedef Battle
 */
const Battle = mongoose.model('Battle', battleSchema);

module.exports = Battle;
