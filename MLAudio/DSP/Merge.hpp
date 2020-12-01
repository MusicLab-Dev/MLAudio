/**
 * @ Author: Matthieu Moinvaziri
 * @ Description: Merge algorithm
 */

#pragma once

#include <MLCore/Utils.hpp>

namespace Audio::DSP
{
    template<typename Unit, std::size_t BufferSize, typename ...Args>
    void Merge(Unit * const output, Args &&...args) noexcept;

    namespace Internal
    {
        template<typename Unit, std::size_t BufferSize, std::size_t Index, typename Tuple>
        std::enable_if_t<std::is_convertible_v<std::tuple_element_t<Index, Tuple>, Unit * const>, void>
            MergeUnroll(Unit * const output, const Tuple &tuple) noexcept;

        template<typename Unit, std::size_t Count, std::size_t InputCount>
        void UnrolledCopy(Unit * const output, const Unit * const input, const Unit ratio) noexcept;
    }
}

#include "Merge.ipp"
