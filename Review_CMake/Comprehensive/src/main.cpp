#include "student.h"

void printStudent(const Student& student);

int main()
{
    Student student("Alice", 20);

    printStudent(student);

    return 0;
}