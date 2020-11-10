/**
 * @ Author: Pierre Veysseyre
 * @ Description: Biq.ipp
 */

using namespace DSP;

template<>
template<BiquadParam::FilterType Filter>
BiquadFilter BiquadFactory<double>::CreateFilter<Filter, BiquadParam::FormType::Inversed>(const double sampleRate, const double freq, const double gain, const double q, bool qAsBandWidth ) noexcept
{


}

// template<BiquadParam::FilterType Filter>
// BiquadFilter BiquadFactory<double>::CreateFilter<Filter, BiquadParam::FormType::Inversed>(const double sampleRate, const double freq, const double gain, const double q, bool qAsBandWidth ) noexcept
// {

// }

// template<typename T>
// template<BiquadParam::FilterType Filter, BiquadParam::FormType Type, BiquadFactory<T>::InternalForm Form>
// BiquadFactory<T>::BiquadFilter<Filter, Form> BiquadFactory::CreateFilter(const double sampleRate, const double freq, const double gain, const double q, bool qAsBandWidth = false) noexcept {
