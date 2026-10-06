#include<iostream>
#include "student.h"


void addStudent(std::vector<Student>& student)
{
	Student addman;
	std::string name;
	int age;
	double score;

	std::cout<<"name:"<<std::endl;
	std::cin>>name;

	for(const auto& x:student)
	{
		if(x.name==name)
		{		
			std::cout<<"the people exited!"<<std::endl;
			return;
		}
	}

	std::cout<<"age:"<<std::endl;
	std::cin>>addman.age;
	
	std::cout<<"score:"<<std::endl;
	std::cin>>addman.score;
	
	addman.name=name;

	student.push_back(addman);
}

void ShowAll(const std::vector<Student>& student)
{
	if(student.empty())
	{
		std::cout<<"data is empty!"<<std::endl;

		return;
	}
	for(const auto& x:student)
	{
		std::cout<<"name:"<<" "<<x.name<<std::endl
				<<"age:"<<" "<<x.age<<std::endl
				<<"score:"<<" "<<x.score<<std::endl;
	}

	return;
}

void FindStudent(const std::vector<Student>& student)
{
	std::string name;

	std::cout<<"Enter name:"<<"\n";
	std::cin>>name;

	for(const auto& x:student)
	{
		if(x.name==name)
		{
			std::cout<<"name:"<<" "<<x.name<<","
				<<"age:"<<" "<<x.age<<","
				<<"score:"<<" "<<x.score<<std::endl;

				return;
		}
	}

	std::cout<<"Student not found"<<"\n";
	
	return;
}

void ShowStatistics(const std::vector<Student>& student)
{
	if(student.empty())
	{
		std::cout<<"data is empty!"<<std::endl;

		return;
	}

	double sum=0.0;
	double max=student[0].score;
	double min=student[0].score;

	for(const auto& x:student)
	{
		sum+=x.score;
		if(x.score>=max) max=x.score;
		if(x.score<=min) min=x.score;
	}

	std::cout<<"Average: "<<sum/student.size()<<"\n"
			<<"Max score: "<<max<<"\n"
			<<"Min score: "<<min<<"\n";

	return;
}