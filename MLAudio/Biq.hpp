/**
 * @ Author: Pierre Veysseyre
 * @ Description: Test.hpp
 */

#pragma once

#include <cstdint>

namespace DSP
{
    template<typename T>
    class BiquadFactory;

    // class BiquadFilter;

    struct BiquadParam;

};

struct DSP::BiquadParam
{
    enum class FilterType : uint8_t {
        LowPass,
        HighPass,
        BandPass,
        BandPass2,
        BandStop    /* Notch */,
        Peak,
        LowShelf,
        HighShelf
    };

    enum class FormType : uint8_t {
        Normal, Inversed
    };

    enum class InternalForm : uint8_t {
        Direct1,        // 4 registers, 3 addOp -> better for fixed-points
        Direct2,        // 2 registers, 4 addOp -> better for fixed-points
        Transposed1,    // 4 registers, 4 addOp -> better for floating-points
        Transposed2     // 2 registers, 3 addOp -> better for floating-points
    };
};




template<typename T = double>
class DSP::BiquadFactory
{

private:

    struct Coefficients
    {
        double a[3] { 0.0 };
        double b[3] { 0.0 };
    };

    template<BiquadParam::FilterType Filter, BiquadParam::InternalForm Form>
    class DSP::BiquadFilter
    {

        int a;
    };
    // static

public:
    template<BiquadParam::FilterType Filter, BiquadParam::FormType Type>
    static BiquadFilter CreateFilter(const double sampleRate, const double freq, const double gain, const double q, bool qAsBandWidth = false) noexcept {
        if constexpr (std::is_signed_v(T)) {
            // if constexpr (std::)
        }
    }

private:
};

// #include "Biq.ipp"