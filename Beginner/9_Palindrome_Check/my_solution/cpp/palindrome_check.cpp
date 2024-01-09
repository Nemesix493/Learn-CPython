#include "palindrome_check.hpp"

std::string getReverseString(std::string string_to_reverse){
    std::string reversed_string;
    for(int i=string_to_reverse.length()-1; i>=0; i--)
    {
        reversed_string += string_to_reverse[i];
    }
    return reversed_string;
}

bool palindromeCheck(std::string palindrome_to_check){
    return palindrome_to_check.compare(getReverseString(palindrome_to_check)) == 0;
}