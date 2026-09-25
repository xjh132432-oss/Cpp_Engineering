#include "calculator.h"
#include "printer.h"

int main()
{
    printResult("add", add(10, 5));
    printResult("sub", sub(10, 5));
    printResult("multiply", multiply(10, 5));
    printResult("divide", divide(10, 5));
    printResult("square", square(6));

    return 0;
}