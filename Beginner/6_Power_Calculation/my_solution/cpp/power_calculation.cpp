#include "power_calculation.hpp"

long long int powerCalculation(int base, int exponent)
{
    if(exponent < 1)
    {
        return 1;
    }
    else
    {
        return base * powerCalculation(base, exponent - 1);
    }
}