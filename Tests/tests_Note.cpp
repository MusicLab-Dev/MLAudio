/**
 * @ Author: Pierre Veysseyre
 * @ Description: Unit tests of Note struct
 */

#include <gtest/gtest.h>

#include <MLAudio/UtilsMidi.hpp>
#include <MLAudio/Note.hpp>

using namespace Audio;

static const Notes SortedNotes {
        Note({ 0, 1 }),
        Note({ 0, 2 }),
        Note({ 0, 3 }),
        Note({ 1, 2 }),
        Note({ 1, 3 }),
        Note({ 1, 4 }),
    };

TEST(Note, EqualOperator)
{
    EXPECT_EQ(SortedNotes[0], SortedNotes[0]);

    const auto b = Note({ 0, 1 }, Midi::NoteConverter::FrequencyToKey(22));
    EXPECT_NE(SortedNotes[0], b);
}

TEST(Note, SortComparisonOperator)
{
    EXPECT_LT(SortedNotes[0], SortedNotes[1]);
    EXPECT_LE(SortedNotes[0], SortedNotes[1]);
    EXPECT_GT(SortedNotes[3], SortedNotes[1]);
    EXPECT_GE(SortedNotes[3], SortedNotes[1]);

    EXPECT_LE(SortedNotes[0], SortedNotes[0]);
    EXPECT_GE(SortedNotes[1], SortedNotes[1]);

    for (auto i = 0u; i < SortedNotes.size() - 1; ++i) {
        EXPECT_LT(SortedNotes[i], SortedNotes[i + 1]);
        EXPECT_GT(SortedNotes[i + 1], SortedNotes[i]);
    }
}
