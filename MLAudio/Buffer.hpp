/**
 * @ Author: Pierre Veysseyre
 * @ Description: Buffer
 */

#pragma once

#include "Base.hpp"

#include <cstddef>
#include <cstring>
#include <memory>

namespace Audio
{
    class Buffer;
    class BufferView;

    using BufferViews = Core::TinyVector<BufferView>;

    namespace Internal
    {
        class BufferBase;
    }
};

/** @brief A BufferBase is a helper base class for any Buffer or BufferView */
class alignas_quarter_cacheline Audio::Internal::BufferBase
{
    /** @brief Get data pointer reintrepreted to a given type */
    template<typename Type>
    [[nodiscard]] Type *data(const Channel channel) noexcept
        { return reinterpret_cast<Type *>(_data.get() + _channelByteSize * static_cast<std::uint32_t>(channel)); }

    /** @brief Get constant data pointer reintrepreted to a given type */
    template<typename Type>
    [[nodiscard]] const Type *data(const Channel channel) const noexcept
        { return reinterpret_cast<const Type *>(_data.get() + _channelByteSize * static_cast<std::uint32_t>(channel)); }

    /** @brief Get the byte data pointer */
    [[nodiscard]] std::byte *byteData(void) noexcept { return _data; }
    [[nodiscard]] const std::byte *byteData(void) const noexcept { return _data; }


    /** @brief Get the byte size per channel */
    [[nodiscard]] std::uint32_t channelByteSize(void) const noexcept { return _channelByteSize; }

    /** @brief Get the buffer size relative to a given type */
    template<typename Type>
    [[nodiscard]] std::uint32_t size(void) const noexcept { return _channelByteSize / sizeof(Type); }

    /** @brief Get the channel arrangement of the buffer */
    [[nodiscard]] ChannelArrangement channelArrangement(void) const noexcept { return _arrangement; }


    /** @brief POD semantics */
    BufferBase(const BufferBase &other) noexcept = default;
    BufferBase(BufferBase &&other) noexcept = default;
    ~BufferBase(void) noexcept = default;
    BufferBase &operator=(const BufferBase &other) noexcept = default;
    BufferBase &operator=(BufferBase &&other) noexcept = default;

protected:
    std::byte *_data { nullptr };
    std::uint32_t _channelByteSize { 0 };
    ChannelArrangement _arrangement { ChannelArrangement::Mono };

    /** @brief Private constructor */
    BufferBase(std::byte * const data, const std::uint32_t channelByteSize, const ChannelArrangement arrangement) noexcept
        : _data(data), _channelByteSize(channelByteSize), _arrangement(arrangement) {}
};

static_assert_fit_quarter_cacheline(Audio::Internal::BufferBase);

/** @brief A Buffer manage ownership of his data */
class Audio::Buffer : public Audio::Internal::BufferBase
{
public:
    /** @brief Allocate the buffer */
    Buffer(const std::uint32_t channelByteSize, const ChannelArrangement arrangement)
        : Internal::BufferBase(
            new std::byte[channelByteSize * static_cast<std::uint32_t>(arrangement)],
            channelByteSize,
            arrangement
        ) {}

    /** @brief Move constructor */
    Buffer(Buffer &&other) noexcept = default;

    /** @brief Delete the allocated buffer */
    ~Buffer(void) noexcept { delete _data; }

    /** @brief Move assignment */
    Buffer &operator=(Buffer &&other) noexcept = default;
};

static_assert_fit_quarter_cacheline(Audio::Buffer);

/** @brief A BufferView holds a reference to an existing buffer without managing data ownership */
class Audio::BufferView : public Audio::Internal::BufferBase
{
public:
    /** @brief Construct the view using an existing buffer */
    BufferView(const Buffer &source) noexcept : Internal::BufferBase(source) {}

    /** @brief Copy constructor */
    BufferView(const BufferView &other) noexcept = default;

    /** @brief Move constructor */
    BufferView(BufferView &&other) noexcept = default;

    /** @brief Destruct the view */
    ~BufferView(void) noexcept = default;

    /** @brief Copy assignment */
    BufferView &operator=(const BufferView &other) noexcept = default;

    /** @brief Move assignment */
    BufferView &operator=(BufferView &&other) noexcept = default;
};
