#include <regex>

namespace app {

struct mark {
    std::string name;
    std::regex input_regex;
    std::string replace_pattern;
};

const int16_t MARKS_NB = 4;

auto get_marks() {
    mark marks[MARKS_NB];

    marks[0] = mark {
        .name = "bold",
        .input_regex = std::regex(
            "\\[b\\](.*?)\\[\\/b\\]", std::regex::icase
        ),
        .replace_pattern = "<strong class=\"bb-bold\">$1</strong>"
    };

    marks[1] = mark {
        .name = "italic",
        .input_regex = std::regex(
            "\\[i\\](.*?)\\[\\/i\\]", std::regex::icase
        ),
        .replace_pattern = "<em class=\"bb-italic\">$1</em>"
    };

    marks[2] = mark {
        .name = "link",
        .input_regex = std::regex(
            "\\[url\\]([^\\s+|\"]*?)\\[\\/url\\]", std::regex::icase
        ),
        .replace_pattern = "<a href=\"\\$1\" class=\"bb-link\">$1</a>"
    };

    marks[3] = mark {
        .name = "labelled_link",
        .input_regex = std::regex(
            "\\[url=\\\"([^\\s+|\"]*?)\\\"\\](.*?)\\[\\/url\\]", std::regex::icase
        ),
        .replace_pattern = "<a href=\"$1\" class=\"bb-labelled-link\">$2</a>"
    };

    return marks;
}

}