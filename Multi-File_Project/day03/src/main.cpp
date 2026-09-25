#include <iostream>
#include "calculator.h"

int main()
{
    std::cout << "add: " << add(10, 5) << '\n';
    std::cout << "sub: " << sub(10, 5) << '\n';
    std::cout << "multiply: " << multiply(10, 5) << '\n';
    std::cout << "divide: " << divide(10, 5) << '\n';
    std::cout << "square: " << square(6) << '\n';
    return 0;
}