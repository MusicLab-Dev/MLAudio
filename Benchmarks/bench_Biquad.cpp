/**
 * @ Author: Matthieu Moinvaziri
 * @ Description: Benchmark of the Biquad (filter) class
 */

#include <iostream>

#include <benchmark/benchmark.h>

#include <MLAudio/Biquad.hpp>

using namespace DSP;

static void BlockProcessBasic(benchmark::State &state)
{
        // std::cout << (static_cast<float>(state.range(1)) / state.range(0) * 1'000'000.f) << " ns" << std::endl;
    // auto filter = BiquadFactory<>::CreateFilter<BiquadParam::FilterType::LowPass, BiquadParam::FormType::Inversed>(static_cast<double>(state.range()), 0.25, 0.0, 0.707);

    // auto filter = Biquad<BiquadParam::BiquadForm::DirectForm1, BiquadParam::FilterType::LowPass>();
    // auto filter = Biquad<BiquadParam::InternalForm::Transposed2>();

    // benchmark::DoNotOptimize(filter);
    for (auto _ : state) {
        // for (auto i = 0u; i < state.range(1) * 1000000000; ++i)
            // filter.process(static_cast<float>(i));
    }
}

BENCHMARK(BlockProcessBasic)
    ->Args({ 44100, 512 })
    ->Args({ 44100, 1024 })
    ->Args({ 44100, 2048 })
    ->Args({ 44100, 4096 })

    ->Args({ 48000, 512 })
    ->Args({ 48000, 1024 })
    ->Args({ 48000, 2048 })
    ->Args({ 48000, 4096 })

    ->Args({ 92000, 512 })
    ->Args({ 92000, 1024 })
    ->Args({ 92000, 2048 })
    ->Args({ 92000, 4096 })
;

// static void BlockProcessBasicFMA(benchmark::State &state)
// {
//     auto filter = Biquad<BiquadParam::BiquadForm::TransposedForm2, BiquadParam::FilterType::LowPass>();
//     benchmark::DoNotOptimize(filter);
//     for (auto _ : state) {
//         // auto tmp = 1.0;
//         for (auto i = 0u; i < state.range(1) * 1000000000; ++i)
//             filter.process(static_cast<float>(i));
//     }
// }

// BENCHMARK(BlockProcessBasicFMA)
//     ->Args({ 44100, 512 })
//     ->Args({ 44100, 1024 })
//     ->Args({ 44100, 2048 })
//     ->Args({ 44100, 4096 })

//     ->Args({ 48000, 512 })
//     ->Args({ 48000, 1024 })
//     ->Args({ 48000, 2048 })
//     ->Args({ 48000, 4096 })

//     ->Args({ 92000, 512 })
//     ->Args({ 92000, 1024 })
//     ->Args({ 92000, 2048 })
//     ->Args({ 92000, 4096 })
// ;
