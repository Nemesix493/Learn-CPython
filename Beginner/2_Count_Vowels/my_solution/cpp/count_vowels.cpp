#include "count_vowels.hpp"
// Function definition
int countVowels(std::string string_to_count)
{
    int count = 0;
    std::string vowels = "aeiou";
    for(int i = 0; i < string_to_count.length(); i++)
    {
        if(vowels.find(string_to_count[i]) != std::string::npos)
        {
            count += 1;
        }
    }
    return count;
}