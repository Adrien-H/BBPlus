#include <iostream>
#include <regex>
#include "./src/bbplus.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Must specify command." << std::endl;
        return 1;
    }

    const std::string ARG_PARSE = "parse";
    const std::string ARG_VALIDATE = "validate";

    const std::string ARG_PARSE_INTERACTIVE = "parse-interactive";
    const std::string ARG_VALIDATE_INTERACTIVE = "validate-interactive";

    if (argv[1] == ARG_PARSE || argv[1] == ARG_VALIDATE) {
        if (argc < 2) {
            std::cerr << "Not enough arguments." << std::endl;
            return 1;
        }

        const std::string INPUT = argv[2];

        if (argv[1] == ARG_PARSE) {
            const std::string OUTPUT = bbplus::parse(INPUT);
            std::cout << OUTPUT;
            return 0;
        }
        if (argv[1] == ARG_VALIDATE) {
            const bool OUTPUT = bbplus::validate(INPUT);
            std::cout << OUTPUT;
            return 0;
        }
    }

    if (argv[1] == ARG_PARSE_INTERACTIVE || argv[1] == ARG_VALIDATE_INTERACTIVE) {
        std::string input;
        if (argv[1] == ARG_PARSE_INTERACTIVE) {
            std::cout << "Waiting for inputs to be parsed..." << std::endl;
            std::string output;
            while (true) {
                std::getline(std::cin, input);
                output = bbplus::parse(input);
                std::cout << output;
            }
        }
        if (argv[1] == ARG_VALIDATE_INTERACTIVE) {
            std::cout << "Waiting for inputs to be validated..." << std::endl;
            bool output;
            while (true) {
                std::getline(std::cin, input);
                output = bbplus::validate(input);
                std::cout << output;
            }
        }
    }

    std::cout << "Unknown instruction \"" << argv[1] << "\"." << std::endl;
    return 1;
}
