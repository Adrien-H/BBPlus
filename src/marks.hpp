#ifndef MARKS_HPP_INCLUDED
#define MARKS_HPP_INCLUDED

#include <regex>

namespace bbplus {

struct mark {
    mark(std::string n, std::string i, std::string r) {
        name = n;
        input_regex = std::regex(i, std::regex::icase);
        replace_pattern = r;
    }
    std::string name;
    std::regex input_regex;
    std::string replace_pattern;
};

const int_fast8_t MARKS_NB = 4;

const mark MARKS[MARKS_NB] = {
    mark(
        "bold",
        "\\[b\\](.*?)\\[\\/b\\]",
        "<strong class=\"bb bb-bold\">$1</strong>"
    ),
    mark(
        "italic",
        "\\[i\\](.*?)\\[\\/i\\]",
        "<em class=\"bb bb-italic\">$1</em>"
    ),
    mark(
        "link",
        "\\[url\\]([^\\s+|\"]*?)\\[\\/url\\]",
        "<a href=\"$1\" class=\"bb bb-link\">$1</a>"
    ),
    mark(
        "labelled_link",
        "\\[url=\\\"([^\\s+|\"]*?)\\\"\\](.*?)\\[\\/url\\]",
        "<a href=\"$1\" class=\"bb bb-labelled-link\">$2</a>"
    )
};

}

#endif
