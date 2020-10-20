/**
 * @ Author: Matthieu Moinvaziri
 * @ Description: Control
 */

inline bool Audio::Control::setAutomationMutedState(const std::size_t index, const bool state) noexcept
{
    if (_bitset.test(index) == state)
        return false;
    _bitset.set(index, state);
    return true;
}

inline bool Audio::Control::setParamID(const ParamID paramID) noexcept
{
    if (paramID == _paramID)
        return false;
    _paramID = paramID;
    return true;
}
