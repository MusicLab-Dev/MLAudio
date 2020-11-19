/**
 * @ Author: Pierre Veysseyre
 * @ Description: Unit tests of Biquad filters
 */

#include <gtest/gtest.h>

#include <MLAudio/DSP/Biquad.hpp>

#include <iostream>

using namespace DSP;

TEST(Biquad, Instantiation)
{
    auto filterD1 = BiquadMaker<BiquadParam::Optimization::Classic, char>::MakeBiquad(48000, 0.2);
    auto filterD2 = BiquadMaker<BiquadParam::Optimization::Optimized, int>::MakeBiquad(48000, 0.2);
    auto filterTP1 = BiquadMaker<BiquadParam::Optimization::Classic, float>::MakeBiquad(48000, 0.2);
    auto filterTP2 = BiquadMaker<BiquadParam::Optimization::Optimized, double>::MakeBiquad(48000, 0.2);

    ASSERT_EQ(decltype(filterD1)::Type == BiquadParam::InternalForm::Direct1, true);
    ASSERT_EQ(decltype(filterD2)::Type == BiquadParam::InternalForm::Direct2, true);
    ASSERT_EQ(decltype(filterTP1)::Type == BiquadParam::InternalForm::Transposed1, true);
    ASSERT_EQ(decltype(filterTP2)::Type == BiquadParam::InternalForm::Transposed2, true);
}
