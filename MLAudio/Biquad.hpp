/**
 * @ Author: Pierre Veysseyre
 * @ Description: Biquad.hpp
 */

#pragma once

#include <cmath>

namespace DSP
{
    class Biquad;
};

class DSP::Biquad
{
    enum class Type : unsigned char {
        LP, HP, BP, BP2, BS /* Notch */, Peak, LS, HS
    };

    struct Coefficients
    {
        double a[3] { 0.0 };
        double b[3] { 0.0 };
    };
    // static_assert(sizeof(Coefficients) == 48, "Coefficients must take 48 bytes !");

    struct History
    {
        double in[2] { 0.0 };
        double out[2] { 0.0 };

        void shift(const double i, const double o) noexcept {
            in[1] = in[0];
            in[0] = i;
            out[1] = out[0];
            out[0] = o;
        };
    };
    // static_assert(sizeof(History) == 32, "History must take 32 bytes !");

    Biquad(Type type, const double sampleRate, const double freq, const double gainDb, const double q, bool qAsBandWidth = false) {
        setup(type, sampleRate, freq, gainDb, q, qAsBandWidth);
    }

    void setup(Type type, const double sampleRate, const double freq, const double gainDb, const double q, bool qAsBandWidth) {
        const auto amp = std::pow(10.0, gainDb / 40.0);
        const auto omega = 2.0 * M_PI * freq / sampleRate;
        const auto tsin = std::sin(omega);
        const auto tcos = std::cos(omega);
        double alpha = qAsBandWidth ? (tsin * std::sinh(std::log(2.0) / 2.0 * q * omega / tsin)) : (tsin / (2.0 * q));
        double beta = std::sqrt(amp) / q;

        switch (type) {
        case Type::LP:
            _coefs.b[0] = (1.0 - tcos) / 2.0;
            _coefs.b[1] = 1.0 - tcos;
            _coefs.b[2] = (1.0 - tcos) / 2.0;
            _coefs.a[0] = 1.0 + alpha;
            _coefs.a[1] = -2.0 * tcos;
            _coefs.a[2] = 1.0 - alpha;
            break;
        case Type::HP:
            _coefs.b[0] = (1 + tcos) / 2;
            _coefs.b[1] = -(1 + tcos);
            _coefs.b[2] = (1 + tcos) / 2;
            _coefs.a[0] = 1 + alpha;
            _coefs.a[1] = -2 * tcos;
            _coefs.a[2] = 1 - alpha;
        break;
        case Type::BP:
        case Type::BP2:
            _coefs.b[0] = alpha;
            _coefs.b[1] = 0;
            _coefs.b[2] = -alpha;
            _coefs.a[0] = 1 + alpha;
            _coefs.a[1] = -2 * tcos;
            _coefs.a[2] = 1 - alpha;
            break;
        case Type::BS:
            _coefs.b[0] = 1;
            _coefs.b[1] = -2 * tcos;
            _coefs.b[2] = 1;
            _coefs.a[0] = 1 + alpha;
            _coefs.a[1] = -2 * tcos;
            _coefs.a[2] = 1 - alpha;
            break;
        case Type::Peak:
            _coefs.b[0] = 1 + (alpha * amp);
            _coefs.b[1] = -2 * tcos;
            _coefs.b[2] = 1 - (alpha * amp);
            _coefs.a[0] = 1 + (alpha /amp);
            _coefs.a[1] = -2 * tcos;
            _coefs.a[2] = 1 - (alpha /amp);
            break;
        case Type::LS:
            _coefs.b[0] = amp * ((amp + 1) - (amp - 1) * tcos + beta * tsin);
            _coefs.b[1] = 2 * amp * ((amp - 1) - (amp + 1) * tcos);
            _coefs.b[2] = amp * ((amp + 1) - (amp - 1) * tcos - beta * tsin);
            _coefs.a[0] = (amp + 1) + (amp - 1) * tcos + beta * tsin;
            _coefs.a[1] = -2 * ((amp - 1) + (amp + 1) * tcos);
            _coefs.a[2] = (amp + 1) + (amp - 1) * tcos - beta * tsin;
            break;
        case Type::HS:
            _coefs.b[0] = amp * ((amp + 1) + (amp - 1) * tcos + beta * tsin);
            _coefs.b[1] = -2 * amp * ((amp - 1) + (amp + 1) * tcos);
            _coefs.b[2] = amp * ((amp + 1) + (amp - 1) * tcos - beta * tsin);
            _coefs.a[0] = (amp + 1) - (amp - 1) * tcos + beta * tsin;
            _coefs.a[1] = 2 * ((amp - 1) - (amp + 1) * tcos);
            _coefs.a[2] = (amp + 1) - (amp - 1) * tcos - beta * tsin;
            break;
        }
        _coefs.a[0] = _coefs.b[0] / _coefs.a[0];
        _coefs.a[1] = _coefs.b[1] / _coefs.a[0];
        _coefs.a[2] = _coefs.b[2] / _coefs.a[0];
        _coefs.a[3] = _coefs.a[1] / _coefs.a[0];
        _coefs.a[4] = _coefs.a[2] / _coefs.a[0];

        _history.in[0] = _history.in[1] = 0.0;
        _history.out[0] = _history.out[1] = 0.0;
    }

    float process(const float in) noexcept {
        float out = _coefs.b[0] * in + _coefs.b[1] * _history.in[0] + _coefs.b[2] * _history.in[1] - _coefs.a[1] * _history.out[0] - _coefs.a[2] * _history.out[1];

        _history.shift(in, out);
        return out;
    }

private:
    // Type            _type { Type::LP };
    Coefficients    _coefs {};
    History         _history {};
};

// static_assert(alignof(DSP::Biquad) == 8, "Biquad must be aligned to 8 bytes !");
// static_assert(sizeof(DSP::Biquad) == 80, "Biquad must take 80 bytes !");
