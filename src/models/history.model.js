const mongoose = require('mongoose');
const AutoIncrement = require('mongoose-sequence')(mongoose);
const { toJSON } = require('./plugins');

const historySchema = mongoose.Schema(
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
historySchema.plugin(toJSON);
historySchema.plugin(AutoIncrement, { inc_field: 'historyId' });

/**
 * @typedef History
 */
const History = mongoose.model('Battle', historySchema);

module.exports = History;
