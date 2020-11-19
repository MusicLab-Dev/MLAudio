/**
 * @ Author: Pierre Veysseyre
 * @ Description: Unit tests of Instance class
 */

#include <gtest/gtest.h>

#include <MLAudio/Device.hpp>

using namespace Audio;

static const Device::Descriptor TestDescriptor {
    .name = "device-test",
    .isInput = false,
    .sampleRate = 2048u,
    .format = Format::Floating32,
    .midiChannels = 2u,
    .blockSize = 2048u
};

static void Callback(void *udata, std::uint8_t *stream, int len) {
    memset(stream, 0, len);
    std::cout << "AUDIO CALLBACK TICK !\n";
}

TEST(Instanciation, NoInitSDL)
{
    try {
        Device device(TestDescriptor, Callback);
        FAIL() << "Expected throw !";
    } catch (const std::runtime_error &err) {
        EXPECT_STREQ(err.what(), "Couldn't open audio: Audio subsystem is not initialized");
    } catch (...) {
        FAIL() << "Expected std::runtime_error";
    }
}

TEST(Instantiation, InitSDL)
{
    Device::InitDriver();

    try {
        Device device(TestDescriptor, Callback);
        SUCCEED() << "Device correctly initialized.";
    } catch (...) {
        FAIL() << "No throw was expected !";
    }

    Device::ReleaseDriver();
}

TEST(Instantiation, BasicsStartStop)
{
    Device::InitDriver();

    Device device(TestDescriptor, Callback);
    EXPECT_EQ(device.running(), false);

    device.start();
    EXPECT_EQ(device.running(), true);

    usleep(42'000);

    device.stop();
    EXPECT_EQ(device.running(), false);

    Device::ReleaseDriver();
}
