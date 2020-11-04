/**
 * @ Author: Pierre Veysseyre
 * @ Description: Unit tests of Project class
 */

#include <gtest/gtest.h>

#include <MLAudio/Project.hpp>

using namespace Audio;

TEST(Project, Instantiation)
{
    char *cName = "test";
    auto name = std::make_unique<char *>(cName);
    auto project = Project(std::move(name), Project::PlaybackMode::Production);

}