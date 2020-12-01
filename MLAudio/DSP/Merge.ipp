/**
 * @ Author: Matthieu Moinvaziri
 * @ Description: Merge algorithm
 */

template<typename Unit, std::size_t BufferSize, typename ...Args>
void Audio::DSP::Merge(Unit * const output, Args &&...args) noexcept
{
    Internal::MergeUnroll<Unit, BufferSize, 0ul>(
        output,
        std::make_tuple<Args...>(std::forward<Args>(args)...)
    );
}

template<typename Unit, std::size_t Count, std::size_t InputCount>
void Audio::DSP::Internal::UnrolledCopy(Unit * const output, const Unit * const input, const Unit ratio) noexcept
{
    *output += *input * ratio / InputCount;
    if constexpr (Count > 0)
        UnrolledCopy<Unit, Count - 1, InputCount>(output + 1, input + 1, ratio);
}

template<typename Unit, std::size_t BufferSize, std::size_t Index, typename Tuple>
std::enable_if_t<std::is_convertible_v<std::tuple_element_t<Index, Tuple>, Unit * const>, void>
    Audio::DSP::Internal::MergeUnroll(Unit * const output, const Tuple &tuple) noexcept
{
    constexpr std::size_t BufferByteSize = BufferSize * sizeof(Unit);
    constexpr std::size_t CacheLineCount = BufferByteSize / Core::CacheLineSize;
    constexpr std::size_t UnitPerCacheLine = Core::CacheLineSize / sizeof(Unit);

    static_assert(!(BufferByteSize == 0ul) && !(BufferByteSize & (BufferByteSize - 1ul)),
        "BufferByteSize must be a power of two of at least one cacheline size");

    constexpr auto Process = [](Unit * const output, const Unit * const input, const Unit ratio) {
        for (std::size_t i = 0ul; i < CacheLineCount; ++i){
            UnrolledCopy<Unit, UnitPerCacheLine, std::tuple_size_v<Tuple>>(output + i * UnitPerCacheLine, input + i * UnitPerCacheLine, ratio);
        }
    };

    if constexpr (Index + 1 < std::tuple_size_v<Tuple>) {
        if constexpr (std::is_convertible_v<std::tuple_element_t<Index + 1, Tuple>, const Unit>)
            Process(output, std::get<Index>(tuple), std::get<Index + 1>(tuple));
        else {
            Process(output, std::get<Index>(tuple), static_cast<Unit>(1));
            if constexpr (Index + 1 < std::tuple_size_v<Tuple>)
                MergeUnroll<Unit, BufferSize, Index + 1, Tuple>(output, tuple);
        }
        if constexpr (Index + 2 < std::tuple_size_v<Tuple>)
            MergeUnroll<Unit, BufferSize, Index + 2, Tuple>(output, tuple);
    } else {
        Process(output, std::get<Index>(tuple), static_cast<Unit>(1));
        if constexpr (Index + 1 < std::tuple_size_v<Tuple>)
            MergeUnroll<Unit, BufferSize, Index + 1, Tuple>(output, tuple);
    }
}
