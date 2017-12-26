#include <iostream>
#include <map>
#include <regex>

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

const int16_t MARKS_NB = 4;

mark MARKS[MARKS_NB] = {
    mark(
        "bold",
        "\\[b\\](.*?)\\[\\/b\\]",
        "<strong class=\"bb-bold\">$1</strong>"
    ),
    mark(
        "italic",
        "\\[i\\](.*?)\\[\\/i\\]",
        "<em class=\"bb-italic\">$1</em>"
    ),
    mark(
        "link",
        "\\[url\\]([^\\s+|\"]*?)\\[\\/url\\]",
        "<a href=\"\\$1\" class=\"bb-link\">$1</a>"
    ),
    mark(
        "labelled_link",
        "\\[url=\\\"([^\\s+|\"]*?)\\\"\\](.*?)\\[\\/url\\]",
        "<a href=\"$1\" class=\"bb-labelled-link\">$2</a>"
    )
};

std::string parse(std::string input) {
    std::string output = input;
    for (int_fast16_t i = 0; i < MARKS_NB; i++) {
        while (std::regex_search(output, MARKS[i].input_regex) == true) {
            output = std::regex_replace(
                output, MARKS[i].input_regex, MARKS[i].replace_pattern
            );
        }
    }

    return output;
}

bool validate(std::string input, std::string mark_name = "") {
    for (int_fast16_t i = 0; i < MARKS_NB; ++i) {
        if (mark_name == "" || mark_name == MARKS[i].name) {
            if (std::regex_match(input, MARKS[i].input_regex) == true) {
                return true;
            }
        }
    }
    return false;
}

int main(int argc, char* argv[]) {

    if (argc < 3) {
        std::cerr << "Not enough arguments." << std::endl;
        return 1;
    }

    const std::string ARG_PARSE = "parse";
    const std::string ARG_VALIDATE = "validate";
    const std::string INPUT = argv[2];

    if (argv[1] == ARG_PARSE) {
        const std::string OUTPUT = parse(INPUT);
        std::cout << OUTPUT << std::endl;
        return 0;
    }
    if (argv[1] == ARG_VALIDATE) {
        const bool OUTPUT = validate(INPUT);
        std::cout << OUTPUT << std::endl;
        return 0;
    }

    std::cout << "Unknown instruction \"" << argv[1] << "\"." << std::endl;
    return 1;
}
