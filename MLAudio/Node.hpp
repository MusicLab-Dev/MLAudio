/*
 * @ Author: Pierre Veysseyre
 * @ Description: Node
 */

#pragma once

#include <memory>

#include "PluginTable.hpp"
#include "Control.hpp"
#include "Partition.hpp"
#include "Connection.hpp"
#include "Buffer.hpp"

#pragma once

namespace Audio
{
    class Node;

    /** @brief Handler to a node */
    using NodePtr = std::unique_ptr<Node>;

    /** @brief A list of nodes */
    using Nodes = Core::FlatVector<NodePtr>;

    /** @brief A list of connections */
    using Connections = Core::FlatVector<Connection>;

    /** @brief A list of partitions */
    using Partitions = Core::FlatVector<Partition>;
};

/** @brief A node contains a plugin, a partition table and an automation table */
class alignas_double_cacheline Audio::Node
{
public:
    /** @brief Default constructor */
    Node(void) noexcept = default;

    /** @brief Construct a node using an explicit plugin */
    // Node(PluginPtr &&plugin) noexcept { setPlugin(std::move(plugin)); }

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
    [[nodiscard]] const Core::FlatString &name(void) const noexcept { return _name; }

    /** @brief Set the node name, return true if the name changed */
    bool setName(Core::FlatString &&name) noexcept;


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
    [[nodiscard]] Buffer &cache(void) noexcept { return _cache; }

    /** @brief Get a constant reference to the node cache */
    [[nodiscard]] const Buffer &cache(void) const noexcept { return _cache; }


    /** @brief Generate an audio block */
    void generateAudioBlock(void) const noexcept;

    /** @brief Signal called when the generation of the audio block start */
    void onAudioGenerationStarted(const BeatRange &range) const noexcept;

    /** @brief Signal called when the generation of the audio block is stopped */
    void onAudioGenerationStopped(void) const noexcept;


private:
    PluginPtr           _plugin { nullptr }; // 8
    Nodes               _children {}; // 8
    Connections         _connections {}; // 8
    Partitions          _partitions {}; // 8
    Buffer              _cache; // 16
    Controls            _controls {}; // 8
    bool                _muted { false }; // 1
    bool                _dirty { false }; // 1
    IPlugin::Flags      _flags {}; // 2
    Color               _color { 0u }; // 4
    Core::FlatString    _name {}; // 8
};

static_assert_fit_double_cacheline(Audio::Node);

#include "Node.ipp"
