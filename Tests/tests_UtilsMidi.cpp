/**
 * @ Author: Pierre Veysseyre
 * @ Description: Unit tests of Midi utils
 */

#include <gtest/gtest.h>

#include <MLAudio/UtilsMidi.hpp>

using namespace Audio;

TEST(NoteConverter, FrequencyToKey)
{
    auto freq = 42.f;
    auto k1 = Midi::NoteConverter::FrequencyToKey(freq);
    auto k2 = Midi::NoteConverter::FrequencyToKey(freq * 2);

    EXPECT_NE(k1, Midi::NoteConverter::FrequencyToKey());
    EXPECT_NE(k1, k2);

    EXPECT_EQ(Midi::NoteConverter::FrequencyToKey(22'000), Midi::NoteConverter::FrequencyToKey(20'000));
}
