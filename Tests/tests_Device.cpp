/**
 * @ Author: Pierre Veysseyre
 * @ Description: Unit tests of Instance class
 */

#include <gtest/gtest.h>

#include <MLAudio/Device.hpp>

using namespace Audio;

static void Callback(void *udata, std::uint8_t *stream, int len) {

}

TEST(Device, Basics)
{
    // Device device("device", Callback);
}