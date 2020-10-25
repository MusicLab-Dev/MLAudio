/**
 * @ Author: Matthieu Moinvaziri
 * @ Description: Unit tests of Instance class
 */

#include <gtest/gtest.h>

#include <MLAudio/Control.hpp>

using namespace Audio;

TEST(Control, AutomationMutedState)
{
    Control control(23);

    control.setAutomationMutedState(1, true);
    control.setAutomationMutedState(3, true);


    EXPECT_EQ(control.isAutomationMuted(0), false);
    EXPECT_EQ(control.isAutomationMuted(1), true);
    EXPECT_EQ(control.isAutomationMuted(3), true);

    EXPECT_EQ(control.setAutomationMutedState(1, false), false);
}