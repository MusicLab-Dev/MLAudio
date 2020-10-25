/**
 * @ Author: Pierre Veysseyre
 * @ Description: Device.cpp
 */

#include <stdexcept>

#include "Device.hpp"

using namespace Audio;

Device::Device(const Descriptor &descriptor, AudioCallback &&callback)
{
    // if ((_deviceID = SDL_OpenAudioDevice(descriptor.name.c_str(), descriptor.isInput, )))
    //     throw std::runtime_error(std::string("Couldn't open audio: ") + SDL_GetError());
}