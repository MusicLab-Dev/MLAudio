/**
 * @ Author: Matthieu Moinvaziri
 * @ Description: Node
 */

inline void Audio::Node::setPlugin(PluginPtr &&plugin)
{
    // reset affected members
    _plugin = std::move(plugins);
}

inline bool Audio::Node::setMuted(const bool muted) noexcept
{
    if (muted == _muted)
        return false;
    _muted = muted;
    return true;
}

inline bool Audio::Node::setColor(const Color color) noexcept
{
    if (color == _color)
        return false;
    _color = color;
    return true;
}

inline bool Audio::Node::setName(CustomString &&name) noexcept
{
    if (name == _name)
        return false;
    _name = std::move(name);
    return true;
}