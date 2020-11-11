/**
 * @ Author: Pierre Veysseyre
 * @ Description: Biquad.hpp
 */

#pragma once

#include <cstdint>
#include <cmath>

namespace DSP
{
    struct BiquadParam {
        struct Coefficients
        {
            double a[3] { 0.0 };
            double b[3] { 0.0 };
        };
        static_assert(sizeof(Coefficients) == 48, "Coefficients must take 48 bytes !");

        enum class Optimization : uint8_t {
            Classic, Optimized
        };

        enum class InternalForm : uint8_t {
            Direct1,        // 4 registers, 3 addOp -> better for fixed-points
            Direct2,        // 2 registers, 4 addOp -> better for fixed-points
            Transposed1,    // 4 registers, 4 addOp -> better for floating-points
            Transposed2     // 2 registers, 3 addOp -> better for floating-points
        };

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

        template<BiquadParam::FilterType Filter>
        [[nodiscard]] static Coefficients GenerateCoefficients(const double sampleRate, const double freq, const double gain, const double q, bool qAsBandWidth) noexcept;

    };

    template<BiquadParam::Optimization Opti, typename T>
    struct BiquadMaker;

    template<BiquadParam::InternalForm Form>
    class Biquad;

};

template<DSP::BiquadParam::InternalForm Form>
class DSP::Biquad
{
public:
    static constexpr auto Type = Form;

    /** @brief Default constructor */
    Biquad(const double sampleRate, const double freq, const double gain, const double q, bool qAsBandWidth) {
        setup<BiquadParam::FilterType::LowPass>(sampleRate, freq, gain, q, qAsBandWidth);
    }

    /** @brief Setup the biquad according to the filter type and characteristics */
    template<BiquadParam::FilterType Filter>
    void setup(const double sampleRate, const double freq, const double gain, const double q, bool qAsBandWidth) noexcept {
        _coefs = BiquadParam::GenerateCoefficients<Filter>(sampleRate, freq, gain, q, qAsBandWidth);
    }

    /** Process a block of samples */
    void processBlock(float *block, std::size_t len) noexcept { for (; len; --len) *block = process(*(block)++); }

    /** Get the internal biquad coefficients */
    [[nodiscard]] const BiquadParam::Coefficients &coefficients(void) const noexcept { return _coefs; }
    // [[nodiscard]] BiquadParam::Coefficients &coefficients(void) noexcept { return _coefs; }


protected:
    BiquadParam::Coefficients   _coefs;
    double                      _regs[(Form == BiquadParam::InternalForm::Direct1 || Form == BiquadParam::InternalForm::Transposed1) ? 4 : 2] { 0.0 };

    /** @brief Process a sample into the biquad */
    [[nodiscard]] float process(const float in) noexcept;
};


template<DSP::BiquadParam::Optimization Opti, typename T>
struct DSP::BiquadMaker
{
    [[nodiscard]] static auto MakeBiquad(const double sampleRate, const double freq, const double gain = 3.0, const double q = 0.707, bool qAsBandWidth = false) noexcept {
        if constexpr (std::is_floating_point_v<T>) {
            if constexpr (Opti == DSP::BiquadParam::Optimization::Classic)
                return Biquad<BiquadParam::InternalForm::Transposed1>(sampleRate, freq, gain, q, qAsBandWidth);
            else if constexpr (Opti == BiquadParam::Optimization::Optimized)
                return Biquad<BiquadParam::InternalForm::Transposed2>(sampleRate, freq, gain, q, qAsBandWidth);
        } else if constexpr (std::is_integral<T>()) {
            if constexpr (Opti == BiquadParam::Optimization::Classic)
                return Biquad<BiquadParam::InternalForm::Direct1>(sampleRate, freq, gain, q, qAsBandWidth);
            else if constexpr (Opti == BiquadParam::Optimization::Optimized)
                return Biquad<BiquadParam::InternalForm::Direct2>(sampleRate, freq, gain, q, qAsBandWidth);
        }
    }
};

#include "Biquad.ipp"

// // static_assert(alignof(DSP::Biquad) == 8, "Biquad must be aligned to 8 bytes !");
// // static_assert(sizeof(DSP::Biquad) == 80, "Biquad must take 80 bytes !");
