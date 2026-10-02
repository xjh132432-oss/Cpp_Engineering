#pragma once
#include<vector>
#include<string>

struct Student{

        int age ;
        std::string name;
        double score;
        };

void printstudent(const Student& student);

void printAll(const std::vector<Student>& student);

double getAverage(const std::vector<Student>& student);

const Student* getMax(const std::vector<Student>& student);

const Student& getMin(const std::vector<Student>& student);
