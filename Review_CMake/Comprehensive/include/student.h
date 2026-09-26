#pragma once

#include <string>

class Student
{
public:
    Student(const std::string& name, int age);

    void print() const;

private:
    std::string name_;
    int age_;
};