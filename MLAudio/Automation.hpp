/*
 * @ Author: Pierre Veysseyre
 * @ Description: Automation.hpp
 */

#pragma once

#include "Base.hpp"

namespace Audio
{
    class Automation;
    struct Point;

    /** @brief A list of automations */
    using Automations = Core::FlatVector<Automation>;

    /** @brief A sorted list of points */
    using Points = Core::SortedFlatVector<Point>;
};

/** @brief Represent a point in an automation curve */
struct alignas_quarter_cacheline Audio::Point
{
    /** @brief Describe the interpolation type between points */
    enum class CurveType : std::uint8_t {
        Linear, Fast, Slow
    };

    Point(void) = default;
    Point(const ParamValue value_) : value(value_) {}

    Beat                    beat {};
    alignas(2) CurveType    type { CurveType::Linear };
    std::int16_t            curveRate {}; // We may change this to unsigned 24bits for better precision
    ParamValue              value {};
};

static_assert_fit_quarter_cacheline(Audio::Point);

/** @brief An automation hold a curve used to change parameters over time, it may contains multiple instances which describe where the automation appears over time */
class alignas_quarter_cacheline Audio::Automation
{
public:
    /** @brief Get a reference to automation points */
    [[nodiscard]] Points &points(void) noexcept { return _points; }

    /** @brief Get a constant reference to automation points */
    [[nodiscard]] const Points &points(void) const noexcept { return _points; }

    /** @brief Get a reference to automation instances */
    [[nodiscard]] BeatRanges &instances(void) noexcept { return _instances; }

    /** @brief Get a constant reference to automation instances */
    [[nodiscard]] const BeatRanges &instances(void) const noexcept { return _instances; }

private:
    Points          _points { 0u };
    BeatRanges      _instances { 0u };
};

static_assert_fit_quarter_cacheline(Audio::Automation);
