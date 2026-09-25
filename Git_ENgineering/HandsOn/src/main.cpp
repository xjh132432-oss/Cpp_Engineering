#include <iostream>
#include "calculator.h"

int main()
{
    std::cout << "add: "
              << add(10, 20)
              << std::endl;

    std::cout << "multiply: "
              << multiply(10, 20)
              << std::endl;

    std::cout<<"substract:"
             <<substract(20,10)
             <<std::endl;

    std::cout<<"square:"
             <<square(10)
             <<std::endl;

    return 0;
}