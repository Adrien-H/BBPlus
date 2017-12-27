#include <iostream>
#include <regex>
#include "./src/bbplus.hpp"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Not enough arguments." << std::endl;
        return 1;
    }

    const std::string ARG_PARSE = "parse";
    const std::string ARG_VALIDATE = "validate";
    const std::string INPUT = argv[2];

    if (argv[1] == ARG_PARSE) {
        const std::string OUTPUT = bbplus::parse(INPUT);
        std::cout << OUTPUT << std::endl;
        return 0;
    }
    if (argv[1] == ARG_VALIDATE) {
        const bool OUTPUT = bbplus::validate(INPUT);
        std::cout << OUTPUT << std::endl;
        return 0;
    }

    std::cout << "Unknown instruction \"" << argv[1] << "\"." << std::endl;
    return 1;
}
