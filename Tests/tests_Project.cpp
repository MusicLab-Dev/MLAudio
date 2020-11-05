/**
 * @ Author: Pierre Veysseyre
 * @ Description: Unit tests of Project class
 */

#include <gtest/gtest.h>

#include <MLAudio/Project.hpp>

using namespace Audio;

TEST(Project, Instantiation)
{
    auto project = Project(Core::FlatString("test-project"), Project::PlaybackMode::Production);
}