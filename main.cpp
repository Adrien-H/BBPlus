#include <iostream>
#include <map>
#include <regex>

std::regex get_bb_pattern(std::string lemma, std::string content_pattern = ".*") {
    std::string open = "(\\[" + lemma + "\\])";
    std::string content = "(" + content_pattern + ")";
    std::string close = "(\\[\\/" + lemma + "\\])";

    std::regex r (open + content + close);

    return r;
}

struct mark {
    std::string name;
    std::string bb_lemma;
    std::string html_lemma;
    std::string content_pattern;
    std::regex bb_pattern;
};

int main() {
    std::map<std::string, mark> marks;

    mark bold_mark;
    marks["b"] = bold_mark;
    marks["b"].name = "bold";
    marks["b"].bb_lemma = "b";
    marks["b"].html_lemma = "string";
    marks["b"].content_pattern = ".*";
    marks["b"].bb_pattern = get_bb_pattern(marks["b"].bb_lemma, marks["b"].content_pattern);

    std::cout << marks["b"].name << std::endl;
    std::cout << marks["b"].bb_lemma << std::endl;
    std::cout << marks["b"].html_lemma << std::endl;
    std::cout << marks["b"].content_pattern << std::endl;

    std::string text = "Salut la [b]planète[/b]";

    return 0;
}



