/**
 * @ Author: Pierre Veysseyre
 * @ Description: Unit tests of Control class
 */

#include <gtest/gtest.h>

#include <MLAudio/Control.hpp>

using namespace Audio;

TEST(Control, AutomationMutedState)
{
    Control control(23, 0);

    control.setAutomationMutedState(1, true);
    control.setAutomationMutedState(3, true);


    EXPECT_EQ(control.isAutomationMuted(0), false);
    EXPECT_EQ(control.isAutomationMuted(1), true);
    EXPECT_EQ(control.isAutomationMuted(3), true);

    EXPECT_EQ(control.setAutomationMutedState(1, true), false);
    EXPECT_EQ(control.setAutomationMutedState(1, false), true);
}
