/**
 * @ Author: Pierre Veysseyre
 * @ Description: Biquad implementation
 */

template<>
float DSP::Biquad<DSP::BiquadParam::InternalForm::Direct1>::process(const float in) noexcept
{
    float out = _coefs.b[0] * in + _coefs.b[1] * _regs[0] + _coefs.b[2] * _regs[1] -
                _coefs.a[1] * _regs[2] - _coefs.a[2] * _regs[3];


    // Shift registers
    _regs[1] = _regs[0];
    _regs[0] = in;
    _regs[3] = _regs[2];
    _regs[2] = out;
    return out;

}

template<>
float DSP::Biquad<DSP::BiquadParam::InternalForm::Transposed2>::process(const float in) noexcept
{
    const float out = in * _coefs.a[0] + _regs[0];

    _regs[0] = in * _coefs.a[1] + _regs[1] - _coefs.b[1] * out;
    _regs[1] = in * _coefs.a[2] - _coefs.b[2] * out;
    return out;
}



template<>
DSP::BiquadParam::Coefficients DSP::BiquadParam::GenerateCoefficients<DSP::BiquadParam::FilterType::LowPass>(const double sampleRate, const double freq, const double gain, const double q, bool qAsBandWidth) noexcept
{
    const auto omega = 2.0 * M_PI * freq / sampleRate;
    const auto tsin = std::sin(omega);
    const auto tcos = std::cos(omega);
    const double alpha = qAsBandWidth ? (tsin * std::sinh(std::log(2.0) / 2.0 * q * omega / tsin)) : (tsin / (2.0 * q));

    BiquadParam::Coefficients coefs {};
    coefs.b[0] = (1.0 - tcos) / 2.0;
    coefs.b[1] = 1.0 - tcos;
    coefs.b[2] = (1.0 - tcos) / 2.0;
    coefs.a[0] = 1.0 + alpha;
    coefs.a[1] = -2.0 * tcos;
    coefs.a[2] = 1.0 - alpha;

    coefs.b[0] = coefs.b[0] / coefs.a[0];
    coefs.b[1] = coefs.b[1] / coefs.a[0];
    coefs.b[2] = coefs.b[2] / coefs.a[0];
    coefs.a[1] = coefs.a[1] / coefs.a[0];
    coefs.a[2] = coefs.a[2] / coefs.a[0];

    return coefs;
}

template<>
DSP::BiquadParam::Coefficients DSP::BiquadParam::GenerateCoefficients<DSP::BiquadParam::FilterType::HighPass>(const double sampleRate, const double freq, const double gain, const double q, bool qAsBandWidth) noexcept
{
    const auto omega = 2.0 * M_PI * freq / sampleRate;
    const auto tsin = std::sin(omega);
    const auto tcos = std::cos(omega);
    const double alpha = qAsBandWidth ? (tsin * std::sinh(std::log(2.0) / 2.0 * q * omega / tsin)) : (tsin / (2.0 * q));

    BiquadParam::Coefficients coefs {};
    coefs.b[0] = (1 + tcos) / 2;
    coefs.b[1] = -(1 + tcos);
    coefs.b[2] = (1 + tcos) / 2;
    coefs.a[0] = 1 + alpha;
    coefs.a[1] = -2 * tcos;
    coefs.a[2] = 1 - alpha;

    coefs.b[0] = coefs.b[0] / coefs.a[0];
    coefs.b[1] = coefs.b[1] / coefs.a[0];
    coefs.b[2] = coefs.b[2] / coefs.a[0];
    coefs.a[1] = coefs.a[1] / coefs.a[0];
    coefs.a[2] = coefs.a[2] / coefs.a[0];

    return coefs;
}

template<>
DSP::BiquadParam::Coefficients DSP::BiquadParam::GenerateCoefficients<DSP::BiquadParam::FilterType::BandPass>(const double sampleRate, const double freq, const double gain, const double q, bool qAsBandWidth) noexcept
{
    const auto omega = 2.0 * M_PI * freq / sampleRate;
    const auto tsin = std::sin(omega);
    const auto tcos = std::cos(omega);
    const double alpha = qAsBandWidth ? (tsin * std::sinh(std::log(2.0) / 2.0 * q * omega / tsin)) : (tsin / (2.0 * q));

    BiquadParam::Coefficients coefs {};
    coefs.b[0] = alpha;
    coefs.b[1] = 0;
    coefs.b[2] = -alpha;
    coefs.a[0] = 1 + alpha;
    coefs.a[1] = -2 * tcos;
    coefs.a[2] = 1 - alpha;

    coefs.b[0] = coefs.b[0] / coefs.a[0];
    coefs.b[1] = coefs.b[1] / coefs.a[0];
    coefs.b[2] = coefs.b[2] / coefs.a[0];
    coefs.a[1] = coefs.a[1] / coefs.a[0];
    coefs.a[2] = coefs.a[2] / coefs.a[0];

    return coefs;
}

template<>
DSP::BiquadParam::Coefficients DSP::BiquadParam::GenerateCoefficients<DSP::BiquadParam::FilterType::BandStop>(const double sampleRate, const double freq, const double gain, const double q, bool qAsBandWidth) noexcept
{
    const auto omega = 2.0 * M_PI * freq / sampleRate;
    const auto tsin = std::sin(omega);
    const auto tcos = std::cos(omega);
    const double alpha = qAsBandWidth ? (tsin * std::sinh(std::log(2.0) / 2.0 * q * omega / tsin)) : (tsin / (2.0 * q));

    BiquadParam::Coefficients coefs {};
    coefs.b[0] = 1;
    coefs.b[1] = -2 * tcos;
    coefs.b[2] = 1;
    coefs.a[0] = 1 + alpha;
    coefs.a[1] = -2 * tcos;
    coefs.a[2] = 1 - alpha;

    coefs.b[0] = coefs.b[0] / coefs.a[0];
    coefs.b[1] = coefs.b[1] / coefs.a[0];
    coefs.b[2] = coefs.b[2] / coefs.a[0];
    coefs.a[1] = coefs.a[1] / coefs.a[0];
    coefs.a[2] = coefs.a[2] / coefs.a[0];

    return coefs;
}

template<>
DSP::BiquadParam::Coefficients DSP::BiquadParam::GenerateCoefficients<DSP::BiquadParam::FilterType::Peak>(const double sampleRate, const double freq, const double gain, const double q, bool qAsBandWidth) noexcept
{
    const auto amp = std::pow(10.0, gain / 40.0);
    const auto omega = 2.0 * M_PI * freq / sampleRate;
    const auto tsin = std::sin(omega);
    const auto tcos = std::cos(omega);
    const double alpha = qAsBandWidth ? (tsin * std::sinh(std::log(2.0) / 2.0 * q * omega / tsin)) : (tsin / (2.0 * q));

    BiquadParam::Coefficients coefs {};
    coefs.b[0] = 1 + (alpha * amp);
    coefs.b[1] = -2 * tcos;
    coefs.b[2] = 1 - (alpha * amp);
    coefs.a[0] = 1 + (alpha /amp);
    coefs.a[1] = -2 * tcos;
    coefs.a[2] = 1 - (alpha /amp);

    coefs.b[0] = coefs.b[0] / coefs.a[0];
    coefs.b[1] = coefs.b[1] / coefs.a[0];
    coefs.b[2] = coefs.b[2] / coefs.a[0];
    coefs.a[1] = coefs.a[1] / coefs.a[0];
    coefs.a[2] = coefs.a[2] / coefs.a[0];

    return coefs;
}

template<>
DSP::BiquadParam::Coefficients DSP::BiquadParam::GenerateCoefficients<DSP::BiquadParam::FilterType::LowShelf>(const double sampleRate, const double freq, const double gain, const double q, bool qAsBandWidth) noexcept
{
    const auto amp = std::pow(10.0, gain / 40.0);
    const auto omega = 2.0 * M_PI * freq / sampleRate;
    const auto tsin = std::sin(omega);
    const auto tcos = std::cos(omega);
    const double beta = std::sqrt(amp) / q;

    BiquadParam::Coefficients coefs {};
    coefs.b[0] = amp * ((amp + 1) - (amp - 1) * tcos + beta * tsin);
    coefs.b[1] = 2 * amp * ((amp - 1) - (amp + 1) * tcos);
    coefs.b[2] = amp * ((amp + 1) - (amp - 1) * tcos - beta * tsin);
    coefs.a[0] = (amp + 1) + (amp - 1) * tcos + beta * tsin;
    coefs.a[1] = -2 * ((amp - 1) + (amp + 1) * tcos);
    coefs.a[2] = (amp + 1) + (amp - 1) * tcos - beta * tsin;

    coefs.b[0] = coefs.b[0] / coefs.a[0];
    coefs.b[1] = coefs.b[1] / coefs.a[0];
    coefs.b[2] = coefs.b[2] / coefs.a[0];
    coefs.a[1] = coefs.a[1] / coefs.a[0];
    coefs.a[2] = coefs.a[2] / coefs.a[0];

    return coefs;
}

template<>
DSP::BiquadParam::Coefficients DSP::BiquadParam::GenerateCoefficients<DSP::BiquadParam::FilterType::HighShelf>(const double sampleRate, const double freq, const double gain, const double q, bool qAsBandWidth) noexcept
{
    const auto amp = std::pow(10.0, gain / 40.0);
    const auto omega = 2.0 * M_PI * freq / sampleRate;
    const auto tsin = std::sin(omega);
    const auto tcos = std::cos(omega);
    const double beta = std::sqrt(amp) / q;

    BiquadParam::Coefficients coefs {};
    coefs.b[0] = amp * ((amp + 1) + (amp - 1) * tcos + beta * tsin);
    coefs.b[1] = -2 * amp * ((amp - 1) + (amp + 1) * tcos);
    coefs.b[2] = amp * ((amp + 1) + (amp - 1) * tcos - beta * tsin);
    coefs.a[0] = (amp + 1) - (amp - 1) * tcos + beta * tsin;
    coefs.a[1] = 2 * ((amp - 1) - (amp + 1) * tcos);
    coefs.a[2] = (amp + 1) - (amp - 1) * tcos - beta * tsin;

    coefs.b[0] = coefs.b[0] / coefs.a[0];
    coefs.b[1] = coefs.b[1] / coefs.a[0];
    coefs.b[2] = coefs.b[2] / coefs.a[0];
    coefs.a[1] = coefs.a[1] / coefs.a[0];
    coefs.a[2] = coefs.a[2] / coefs.a[0];

    return coefs;
}
