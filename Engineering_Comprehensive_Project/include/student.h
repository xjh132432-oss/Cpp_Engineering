#pragma once
#include<string>
#include<vector>


struct Student
{
	std::string name;
	int age;
	double score;
};
void addStudent(std::vector<Student>& student);
void ShowAll(const std::vector<Student>& student);
void FindStudent(const std::vector<Student>& student);
void ShowStatistics(const std::vector<Student>& student);
