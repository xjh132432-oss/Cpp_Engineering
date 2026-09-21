#include <iostream>
#include "calculator.h"

int main()
{
    std::cout << "add: "
              << add(3, 5)
              << '\n';

    std::cout << "multiply: "
              << multiply(3, 5)
              << '\n';

    return 0;
}