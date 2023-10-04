#include "factorial_calculation.hpp"

// function definition

int factorialCalculation(int index)
{
    if(index > 1)
    {
        return index * factorialCalculation(index - 1);
    }
    else
    {
        return 1;
    }
}