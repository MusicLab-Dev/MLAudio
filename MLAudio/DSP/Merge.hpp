/**
 * @ Author: Matthieu Moinvaziri
 * @ Description: Merge algorithm
 */

#pragma once

#include <MLCore/Utils.hpp>

namespace Audio::DSP
{
    template<typename Unit, std::size_t BufferSize, typename ...Inputs>
    void Merge(Inputs ...inputs, Unit * const output) noexcept;
}

#include "Merge.ipp"