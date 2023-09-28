#include "sum_of_even_numbers.hpp"

int sumOfEvenNumbers(std::vector<int> int_list)
{
    int result = 0;
    for(std::size_t i=0; i<int_list.size(); i++)
    {
        if(int_list.at(i)%2 == 0)
        {
            result += int_list.at(i);
        }
    }
    return result;
}