#include <iostream>
#include "student.h"
#include "printer.h"

int main()
{
    const int size = 5;
    int scores[size];

    std::cout << "Enter 5 scores: ";

    for (int i = 0; i < size; i++)
    {
        std::cin >> scores[i];
    }

    double avg = average(scores, size);
    int max = maximum(scores, size);
    int min = minimum(scores, size);

    printScoreInfo(avg, max, min);

    return 0;
}