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
        enum class BiquadForm : uint8_t {
            DirectForm1,        // 4 registers, 3 addOp -> better for fixed-points
            DirectForm2,        // 2 registers, 4 addOp -> better for fixed-points
            TransposedForm1,    // 4 registers, 4 addOp -> better for floating-points
            TransposedForm2     // 2 registers, 3 addOp -> better for floating-points
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
    };


    template<BiquadParam::BiquadForm Form>
    class BiquadBase;

    template<BiquadParam::BiquadForm Form, BiquadParam::FilterType Filter>
    class Biquad;

};

template<DSP::BiquadParam::BiquadForm Form>
class DSP::BiquadBase
{
public:

    struct Coefficients
    {
        double a[3] { 0.0 };
        double b[3] { 0.0 };
    };
    static_assert(sizeof(Coefficients) == 48, "Coefficients must take 48 bytes !");


    [[nodiscard]] float process(const float in) noexcept;

    [[nodiscard]] const Coefficients &coefficients(void) const noexcept { return _coefs; }
    // Coefficients &coefficients(void) noexcept { return _coefs; }


protected:
    Coefficients    _coefs;
    double          _regs[(Form == BiquadParam::BiquadForm::DirectForm1 || Form == BiquadParam::BiquadForm::TransposedForm1) ? 4 : 2] { 0.0 };
};


template<DSP::BiquadParam::BiquadForm Form, DSP::BiquadParam::FilterType Filter>
class DSP::Biquad : public DSP::BiquadBase<Form>
{
public:

    void foo(void);

    [[nodiscard]] void generateCoefficients(const double sampleRate, const double freq, const double gain, const double q, bool qAsBandWidth = false);

private:

};


#include "Biquad.ipp"

// // static_assert(alignof(DSP::Biquad) == 8, "Biquad must be aligned to 8 bytes !");
// // static_assert(sizeof(DSP::Biquad) == 80, "Biquad must take 80 bytes !");
