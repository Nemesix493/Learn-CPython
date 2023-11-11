#include "average_calculation.hpp"

double averageCalculation(std::vector<int> int_list)
{
    int sum = 0;
    for(std::size_t i = 0; i < int_list.size(); i++)
    {
        sum += int_list.at(i);
    }
    return (double)sum / (double)int_list.size();
}