/*
 * Project: MusicLab
 * Author: Pierre Veysseyre
 * Description: Node.hpp
 */

#include <memory>

#include "Globals.hpp"

#include "PluginPtr.hpp"
#include "Control.hpp"

#pragma once

namespace ML::Audio
{
    template<typename Type>
    class Node;

    template<typename Type>
    using NodePtr = std::unique_ptr<Node<Type>>;

    // Replace std::vector by FlatVector ??
    template<typename Type>
    using Nodes = std::vector<NodePtr<Type>>;

    // Replace std::string by FlatString
    using CustomString = std::string;
}

template<typename Type>
class ML::Audio::Node
{
public:
    Node(Type &&type) = default;


    /**
     * @brief Check if the node is muted (not active) or not
     *
     * @return true Control is muted
     * @return false Control isn't muted
     */
    bool muted(void) const noexcept { return _muted; }

    /**
     * @brief Set the muted state of the node
     *
     * @param muted New muted state
     */
    void setMuted(bool muted) noexcept { _muted = muted; }


    /**
     * @brief Check if the control is dirty or not
     *
     * @return true Control is dirty
     * @return false Control isn't dirty
     */
    bool dirty(void) const noexcept { return _dirty; }

    /**
     * @brief Set the dirty state of the control
     *
     * @param dirty New dirty state
     */
    void setDirty(bool dirty) noexcept { _dirty = muted; }


    /**
     * @brief Get the plugin's flags associated to this node
     *
     * @return const IPlugin::Flags Plugin's flags
     */
    const IPlugin::Flags flags(void) const noexcept { return _flags; }


    /**
     * @brief Get the color associated to this node
     *
     * @return Color Color value
     */
    Color color(void) const noexcept { return _color; }

    /**
     * @brief Set the color
     *
     * @param color Color value
     */
    void setColor(const Color color) noexcept { _color = color; }


    /**
     * @brief Get the name of the node
     *
     * @return const CustomString& Constant reference to the node name
     */
    const CustomString &name(void) const noexcept { return _name; }

    /**
     * @brief Set the node name
     *
     * @param name New name
     * @return true New name correctly set
     * @return false Cannot set the new name
     */
    bool setName(CustomString &&name) noexcept { return false; }


    // IDevicePtr &device(void) noexcept { return _device; }
    // const IDevicePtr &device(void) const noexcept { return _device; }


    /**
     * @brief Get the partitions associated to the node
     *
     * @return Partitions& Reference to the partitions
     */
    // Partitions &partitions(void) noexcept { return _partitions; }

    /**
     * @brief Get the partitions associated to the node
     *
     * @return Partitions& Constant reference to the partitions
     */
    // const Partitions &partitions(void) const noexcept { return _partitions; }


    /**
     * @brief Get the node childrens
     *
     * @return Nodes& Reference to the childrens
     */
    Nodes &children(void) noexcept { return _children; }

    /**
     * @brief Get the node childrens
     *
     * @return Nodes& Constant reference to the childrens
     */
    const Nodes &children(void) const noexcept { return _children; }


    /**
     * @brief Get the connections associated to the node
     *
     * @return Connections& Reference to the connections
     */
    // Connections &connections(void) noexcept { return _connections; }

    /**
     * @brief Get the connections associated to the node
     *
     * @return Connections& Constant reference to the connections
     */
    // const Connections &connections(void) const noexcept { return _connections; }


    /**
     * @brief Get the connections associated to the node
     *
     * @return Connections& Reference to the connections
     */
    // Connections &connections(void) noexcept { return _connections; }

    /**
     * @brief Get the connections associated to the node
     *
     * @return Connections& Constant reference to the connections
     */
    // const Connections &connections(void) const noexcept { return _connections; }

private:
    bool            _muted { false };
    bool            _dirty { false };
    IPlugin::Flags  _flags { /* IPlugin::Flags::AudioOutput */ };
    Color           _color { 0u };
    CustomString    _name { "Node" };
    PluginPtr       _plugin { nullptr };
    Controls        _controls { 0u };
    // Partitions      _partitions { 0u };
    Nodes<Type>     _children { 0u };
    // Connections     _connections { 0u };
    // Buffer          _cache {};

};
