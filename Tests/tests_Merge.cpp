/**
 * @ Author: Antoine La Mache
 * @ Description: Unit tests of merge function
 */

#include <vector>

#include <gtest/gtest.h>

#include <MLAudio/DSP/Merge.hpp>

using namespace Audio;

template<typename Type, std::size_t Range>
std::vector<Type> GenerateIncreasingRange(void)
{
    std::vector<Type> vec;
    Type value {};

    vec.resize(Range);
    for (auto &it : vec)
        it = ++value;
    return vec;
}

template<typename Type, std::size_t Range>
std::vector<Type> GenerateDecreasingRange(void)
{
    std::vector<Type> vec;
    Type value {};

    vec.resize(Range);
    for (auto &it : vec)
        it = --value;
    return vec;
}

TEST(MergeVariadic, float)
{
    constexpr std::size_t BufferSize = 64ul;

    float ratio = 0.5f;
    std::vector<float> output(BufferSize, 0.0f);
    std::vector<float> first    = GenerateIncreasingRange<float, 64>();
    std::vector<float> second   = GenerateDecreasingRange<float, 64>();
    std::vector<float> third    = GenerateDecreasingRange<float, 64>();

    DSP::Merge<float, BufferSize>(
        output.data(), first.data(), ratio, second.data()
    );
    for (auto i = 0ul; i < BufferSize; ++i) {
        ASSERT_EQ(
            output.at(i),
            (first.at(i) * ratio / 2.0f) + (second.at(i) * 1.0f / 2.0f)
        );
    }
}
/*
    using Tuple = std::tuple<float *, float>;
    
    DSP::Merge<float, 4, Tuple, 0ul>(output, Tuple(first.data(), ratio));
    for (int i = 0; i < 4; ++i)
        ASSERT_EQ(output.at(i), expected.at(i));
    output.clear();
    for (int i = 0; i < 4; i++)
        output.push_back(0);
    DSP::Merge<float, 4, Tuple, 0ul>(output, std::tuple<float *, float, float *>(first.data(), ratio, second.data()));
    for (int i = 0; i < 4; ++i)
        ASSERT_EQ(output.at(i), expected.at(i) + second.at(i));
}
TEST(MergeVariadic, int)
{
    using Tuple = std::tuple<int *, int>;
    float ratio = 0.5f;
    std::vector<int> expected = {0, 1, 1, 2};
    std::vector<int> output(4,0);
    std::vector<int> first = {1,2,3,4};
    std::vector<int> second = {4,3,2,1};
    std::vector<int> third = {4,3,2,1};
    DSP::Merge<int, 4, Tuple, 0ul>(output, Tuple(first.data(), ratio));
    for (int i = 0; i < 4; ++i)
        ASSERT_EQ(output.at(i), expected.at(i));
    output.clear();
    for (int i = 0; i < 4; i++)
        output.push_back(0);
    DSP::Merge<int, 4, Tuple, 0ul>(output, std::tuple<int *, float, int *>(first.data(), ratio, second.data()));
    for (int i = 0; i < 4; ++i)
        ASSERT_EQ(output.at(i), expected.at(i) + second.at(i));

}
*/