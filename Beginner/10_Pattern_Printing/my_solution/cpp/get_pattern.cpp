#include "get_pattern.hpp"

std::string getPattern(std::string pattern_name){
    std::unordered_map<std::string, std::string> patterns = {
        {"triangle", "   /\\\n  /  \\\n /    \\\n/______\\\n"},
        {"square", " ______\n|      |\n|      |\n|______|\n"},
        {"diamond", " ___\n/   \\\n\\   /\n \\_/\n"}
    };
    auto it = patterns.find(pattern_name);
    if (it != patterns.end()) {
        return it->second;
    } else {
        throw std::invalid_argument("\"" + pattern_name + "\" is not a valid pattern name !");
    }

}