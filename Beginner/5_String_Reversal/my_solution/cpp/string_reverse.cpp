#include "string_reverse.hpp"

std::string stringReverse(std::string original_string)
{
    std::string reversed_string;
    for(int i=original_string.length(); i>=0; i--)
    {
        reversed_string += original_string[i];
    }
    return reversed_string;
}