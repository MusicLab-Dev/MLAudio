/**
 * @ Author: Matthieu Moinvaziri
 * @ Description: Unit tests of Instance class
 */

#include <gtest/gtest.h>

#include <MLAudio/Instance.hpp>
#include <MLAudio/Device.hpp>

using namespace Audio;

TEST(Instance, Basics)
{
    Instance instance;
}

static void Callback(void *udata, std::uint8_t *stream, int len) {

}

TEST(Device, Basics)
{
    Device device("device", Callback);
}