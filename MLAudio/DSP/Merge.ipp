/**
 * @ Author: Matthieu Moinvaziri
 * @ Description: Merge algorithm
 */

template<typename Unit, std::size_t BufferSize, typename ...Inputs>
void Audio::DSP::Merge(Inputs ...inputs, Unit * const output) noexcept
{
    constexpr auto CachelineCount = (BufferSize * sizeof(Unit)) / Core::CacheLineSize;

}

/** Dummy unroll example
template<std::size_t Count>
void Unroll(void)
{
    if constexpr (Count > 0)
        Unroll<Count - 1>();
}
*/