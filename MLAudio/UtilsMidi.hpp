/**
 * @ Author: Pierre Veysseyre
 * @ Description: UtilsMidi
 */

#pragma once

#include <cmath>

#include <MLCore/Assert.hpp>

#include "Base.hpp"

namespace Audio::Midi
{
    struct NoteConverter;
};

struct Audio::Midi::NoteConverter
{
    static constexpr Key MidiRootKey = 69u;
    static constexpr float RootFrequency = 440.f;
    static constexpr float MinFrequecy = 8.18f;
    static constexpr float MaxFrequecy = 20'000.f;

    /** @brief Convert a frequency to a MIDI key */
    inline static Key FrequencyToKey(float frequency = RootFrequency) noexcept {
        if (frequency > MaxFrequecy)
            frequency = MaxFrequecy;
        if (frequency < MinFrequecy)
            frequency = MinFrequecy;
        frequency /= RootFrequency;
        return static_cast<Key>(12 * std::log(frequency) + MidiRootKey);
    }

    /** @brief Convert a MIDI key to a frequency */
    inline static float KeyToFrequency(Key key = MidiRootKey) noexcept {
        if (key > 0x7F)
            key = 0x7F;
        key -= MidiRootKey;
        key /= 12;
        return std::pow(static_cast<float>(key), 2) * RootFrequency;
    }
};