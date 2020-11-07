/**
 * @ Author: Pierre Veysseyre
 * @ Description: Note implementation
 */

using namespace Audio;

inline bool Note::operator==(const Note &other) const noexcept
{
    return (
        (range == other.range) &&
        (type == other.type) &&
        (key == other.key) &&
        (velocity == other.velocity) &&
        (tunning == other.tunning) &&
        (noteIndex == other.noteIndex)
    );
}

inline bool Note::operator!=(const Note &other) const noexcept
{
    return !(operator==(other));
}

inline bool Note::operator>(const Note &other) const noexcept
{
    if (range.from > other.range.from)
        return true;
    if (range.from == other.range.from && range.to > other.range.to)
        return true;
    return false;
}

inline bool Note::operator>=(const Note &other) const noexcept
{
    if (range.from > other.range.from)
        return true;
    if (range.from == other.range.from && range.to >= other.range.to)
        return true;
    return false;
}

inline bool Note::operator<(const Note &other) const noexcept
{
    if (range.from < other.range.from)
        return true;
    if (range.from == other.range.from && range.to < other.range.to)
        return true;
    return false;
}

inline bool Note::operator<=(const Note &other) const noexcept
{
    if (range.from < other.range.from)
        return true;
    if (range.from == other.range.from && range.to <= other.range.to)
        return true;
    return false;
}
