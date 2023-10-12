#include "prime_number_check.hpp"

bool primeNumberCheck(int number)
{
    if(number == 1 || number == 2)
    {
        return true;
    }
    if(number%2 != 0)
    {
        int max = (number + 1) / 2;
        for(int i = 3; i < max; i++)
        {
            if(number%i == 0)
            {
                return false;
            }
        }
        return true;
    }
    return false;
}