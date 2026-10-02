#include<iostream>
#include "student.h"
#include<vector>

double getAverage(const std::vector<Student>& student)
{
	
	double sum=0.0;

	if(student.empty())
	{
		return sum;
	}

	else
	{


		for(const auto& x:student)
		{
			sum+=x.score;
		}

		return sum/student.size();
	}


} 

const Student* getMax(const std::vector<Student>& student)
{	
	if(student.empty())
	{
		return nullptr;
	}

	double max=student[0].score;
	const Student* maxpeople=&student[0];

	for(int i=0;i<student.size();i++)
	{
		if(student[i].score>max)
		{
			max=student[i].score;
			maxpeople=&student[i];
		}	
	}
	return maxpeople;
}

const Student& getMin(const std::vector<Student>& student)
{
	double min=student[0].score;
	const Student* minpeople=&student[0];

	for(int i=0;i<student.size();i++)
	{
		if(student[i].score<min)
		{
			min=student[i].score;
			minpeople=&student[i];
		}	
	}
	return *minpeople;
}
void printAll(const std::vector<Student>& student)
{
	for(auto x: student)
	{
		 std::cout<<"Name:"<<x.name<<std::endl
                <<"Age:"<<x.age<<std::endl
                <<"Score:"<<x.score<<std::endl;
	}
}

void printstudent(const Student& student)
{
	std::cout<<"Name:"<<student.name<<std::endl
		<<"Age:"<<student.age<<std::endl
		<<"Score:"<<student.score<<std::endl;
}
