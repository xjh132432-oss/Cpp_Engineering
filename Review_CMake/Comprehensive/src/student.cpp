#include "student.h"

#include <iostream>

Student::Student(const std::string& name, int age)
    : name_(name), age_(age)
{
}

void Student::print() const
{
    std::cout << "Name: "
              << name_
              << ", Age: "
              << age_
              << '\n';
}