/**
 * @ Author: Pierre Veysseyre
 * @ Description: Buffer
 */

#pragma once

#include <cstddef>

namespace Audio
{
    class Buffer;
    class Buffers;
};

class Audio::Buffer
{
public:
    Buffer(void) = default;
    Buffer(const std::size_t size) : _data(new std::byte[size]) {}

    ~Buffer(void) { if (_data) delete[] _data; }

private:
    std::byte      *_data { nullptr };
};

class Audio::Buffers
{
public:
    Buffers(const std::size_t count, const std::size_t size) : _data(new Buffer[count]), _count(count) {
        for (auto i = 0u; i < count; ++i) {
            _data[i] = Buffer(size);
        }
    }

    ~Buffers(void) { if (_data) delete[] _data; }

    [[nodiscard]] std::size_t count(void) const noexcept { return _count; }

private:
    Buffer         *_data { nullptr };
    std::size_t     _count { 0u };
};
