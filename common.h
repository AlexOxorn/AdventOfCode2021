//
// Created by alexoxorn on 2021-12-02.
//

#ifndef ADVENTOFCODE2021_COMMON_H
#define ADVENTOFCODE2021_COMMON_H

#include <fstream>
#include <iterator>
#include <iostream>
#include <unistd.h>
#include <optional>
#include <vector>
#include <ranges>
#include <ox/io.h>
#include <ox/std_abbreviation.h>

using namespace ox::std_abbreviations;

#define XSTR(a) STR(a)
#define STR(a) #a

#define GET_STREAM(name, type) ox::ifstream_container<type>{"../" XSTR(YEAR) "/day" XSTR(DAY) "/" #name ".txt"}

#define DEFINE_VECTOR_FROM_ISTREAM_INPUT_METHOD(name, type)\
std::vector<type> get_##name() {\
    static std::optional<std::vector<type>> input_vector;\
    if (!input_vector) {\
        auto ss = GET_STREAM(name, type);\
        input_vector.emplace(std::begin(ss), std::end(ss));\
    }\
    return input_vector.value();\
}

#define DEFINE_DEFAULT_GET_VECTORS(type)\
DEFINE_VECTOR_FROM_ISTREAM_INPUT_METHOD(input, type)\
DEFINE_VECTOR_FROM_ISTREAM_INPUT_METHOD(sample_input, type)

#define COMMON_HEADER\
    void puzzle1();\
    void puzzle2();\

#endif //ADVENTOFCODE2021_COMMON_H
