/**
 * @ Author: Pierre Veysseyre
 * @ Description: Oscillator implementation
 */

inline Audio::IPlugin::Flags Audio::Oscillator::getFlags(void) const noexcept
{
    return static_cast<Flags>(
        static_cast<std::size_t>(Flags::AudioOutput) |
        static_cast<std::size_t>(Flags::ControlInput) |
        static_cast<std::size_t>(Flags::NoteInput)
    );
}