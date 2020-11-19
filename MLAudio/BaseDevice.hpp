/**
 * @ Author: Pierre Veysseyre
 * @ Description: BaseDevice
 */

#pragma once

#include <cstdint>

namespace Audio
{
    /** @brief Format describe the bit depth (e.g. Audio headroom) of the Device
     *  Note that the CPU works increase with the size of the format ! */
    enum class Format : std::uint8_t {
        Fixed8, Fixed16, Fixed32, Floating32
    };

    using SampleRate = std::uint32_t;

    using BlockSize = std::uint16_t;
};