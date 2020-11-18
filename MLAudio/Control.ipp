/**
 * @ Author: Matthieu Moinvaziri
 * @ Description: Control
 */

inline bool Audio::Control::setMuted(const bool muted) noexcept
{
    if (_muted == muted)
        return false;
    _muted = muted;
    return true;
}

inline bool Audio::Control::setAutomationMutedState(const std::size_t index, const bool state) noexcept
{
    if (isAutomationMuted(index) == state)
        return false;
    if (state)
        _automationMutedStates |= 1u << index;
    else
        _automationMutedStates &= ~(1u << index);
    return true;
}

inline bool Audio::Control::setParamID(const ParamID paramID) noexcept
{
    if (paramID == _paramID)
        return false;
    _paramID = paramID;
    return true;
}
