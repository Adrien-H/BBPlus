#ifndef BBPLUS_HPP_INCLUDED
#define BBPLUS_HPP_INCLUDED

#include <regex>
#include "./marks.hpp"

namespace bbplus {

std::string parse(std::string input) {
    std::string output = input;
    for (int_fast8_t i = 0; i < MARKS_NB; ++i) {
        while (std::regex_search(output, MARKS[i].input_regex) == true) {
            output = std::regex_replace(
                output, MARKS[i].input_regex, MARKS[i].replace_pattern
            );
        }
    }

    return output;
}

bool validate(std::string input, std::string mark_name = "") {
    for (int_fast8_t i = 0; i < MARKS_NB; ++i) {
        if (mark_name == "" || mark_name == MARKS[i].name) {
            if (std::regex_match(input, MARKS[i].input_regex) == true) {
                return true;
            }
        }
    }
    return false;
}

}

#endif