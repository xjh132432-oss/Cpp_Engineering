#include "student.h"

double average(int scores[], int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += scores[i];
    }

    return static_cast<double>(sum) / size;
}

int maximum(int scores[], int size)
{
    int max = scores[0];

    for (int i = 1; i < size; i++)
    {
        if (scores[i] > max)
        {
            max = scores[i];
        }
    }

    return max;
}

int minimum(int scores[], int size)
{
    int min = scores[0];

    for (int i = 1; i < size; i++)
    {
        if (scores[i] < min)
        {
            min = scores[i];
        }
    }

    return min;
}