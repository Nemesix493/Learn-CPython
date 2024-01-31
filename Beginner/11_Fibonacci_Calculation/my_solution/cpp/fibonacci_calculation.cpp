#include "fibonacci_calculation.hpp"

int fibonacciCalculation(int index){
    if(index <= 1){
        return 1;
    }
    return fibonacciCalculation(index - 1) + fibonacciCalculation(index - 2);
}