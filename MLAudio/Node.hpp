/*
 * @ Author: Pierre Veysseyre
 * @ Description: Node
 */

#include <memory>

#include "PluginPtr.hpp"
#include "Control.hpp"
#include "Partition.hpp"
#include "Connection.hpp"
#include "Buffer.hpp"

#pragma once

namespace Audio
{
    class Node;

    using NodePtr = std::unique_ptr<Node>;

    // Replace FlatVector ??
    using Nodes = FlatVector<NodePtr>;
};

/** @brief A node contains a plugin, a partition table and an automation table */
class alignas(64) Audio::Node
{
public:
    /** @brief Default constructor */
    Node(void) noexcept = default;

    /** @brief Construct a node using an explicit plugin */
    Node(PluginPtr &&plugin) noexcept { setPlugin(std::move(plugin)); }

    /** @brief Move constructor */
    Node(Node &&other) noexcept = default;

    /** @brief Move assignment */
    Node &operator=(Node &&other) noexcept = default;

    /** @brief Get the internal plugin */
    [[nodiscard]] IPlugin *getPlugin(void) { return _plugin.get(); }

    /** @brief Set the internal plugin */
    void setPlugin(PluginPtr &&plugin);


    /** @brief Check if the node is muted (not active) or not */
    [[nodiscard]] bool muted(void) const noexcept { return _muted; }

    /** @brief Set the muted state of the node */
    bool setMuted(const bool muted) noexcept;


    /** @brief Check if the control is dirty or not */
    [[nodiscard]] bool dirty(void) const noexcept { return _dirty; }

    /** @brief Set the dirty state of the control */
    void setDirty(const bool dirty) noexcept { _dirty = dirty; }


    /** @brief Get the plugin's flags associated to this node */
    [[nodiscard]] const IPlugin::Flags flags(void) const noexcept { return _flags; }


    /** @brief Get the color associated to this node */
    [[nodiscard]] Color color(void) const noexcept { return _color; }

    /** @brief Set the color */
    bool setColor(const Color color) noexcept;


    /** @brief Get the name of the node */
    [[nodiscard]] const CustomString &name(void) const noexcept { return _name; }

    /** @brief Set the node name, return true if the name changed */
    bool setName(CustomString &&name) noexcept;


    /** @brief Get a reference to the node plugin */
    [[nodiscard]] PluginPtr &plugin(void) noexcept { return _plugin; }

    /** @brief Get a constant reference to the node plugin */
    [[nodiscard]] const PluginPtr &plugin(void) const noexcept { return _plugin; }


    /** @brief Get a reference to the node partitions */
    [[nodiscard]] Partitions &partitions(void) noexcept { return _partitions; }

    /** @brief Get a constant reference to the node partitions */
    [[nodiscard]] const Partitions &partitions(void) const noexcept { return _partitions; }


    /** @brief Get a reference to the node childrens */
    [[nodiscard]] Nodes &children(void) noexcept { return _children; }

    /** @brief Get a constant reference to the node childrens */
    [[nodiscard]] const Nodes &children(void) const noexcept { return _children; }


    /** @brief Get a reference to the node connections */
    [[nodiscard]] Connections &connections(void) noexcept { return _connections; }

    /** @brief Get a constant reference to the node connections */
    [[nodiscard]] const Connections &connections(void) const noexcept { return _connections; }


    /** @brief Get a reference to the node cache */
    // [[nodiscard]] Buffer &cache(void) noexcept { return _cache; }

    /** @brief Get a constant reference to the node cache */
    // [[nodiscard]] const Buffer &cache(void) const noexcept { return _cache; }


    /** @brief Generate an audio block */
    void generateAudioBlock(void) const noexcept;

    /** @brief Signal called when the generation of the audio block start */
    void onAudioGenerationStarted(const BeatRange &range) const noexcept;

    /** @brief Signal called when the generation of the audio block is stopped */
    void onAudioGenerationStopped(void) const noexcept;


private:
    bool            _muted { false };
    bool            _dirty { false };
    IPlugin::Flags  _flags { /* IPlugin::Flags::AudioOutput */ };
    Color           _color { 0u };
    CustomString    _name { "Node" };
    PluginPtr       _plugin { nullptr };
    Controls        _controls { 0u };
    Partitions      _partitions { 0u };
    Nodes           _children { 0u };
    Connections     _connections { 0u };
    Buffer          _cache { 0u };
};

#include "Node.ipp"

static_assert(alignof(Audio::Node) == 64, "Node must be aligned to 64 bytes !");
static_assert(sizeof(Audio::Node) == 64, "Node must take 64 bytes !");