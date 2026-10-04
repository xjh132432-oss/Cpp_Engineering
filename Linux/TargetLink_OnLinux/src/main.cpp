#include<iostream>
#include "student.h"
#include<vector>
#include<string>

int main()
{
	std::vector<Student> student(5);
	
	for(int i=0;i<5;i++)
	{
		std::string name;
		int age;
		double score;

		std::cin>>name>>age>>score;

		student[i].name=name;
		student[i].age=age;
		student[i].score=score;
	}
	std::vector<Student> empty;

	const Student* max=getMax(empty);
	Student min=getMin(student);
	
	std::cout<<"Min:"<<std::endl
		 << "Name:" << min.name << std::endl
              << "Age:" << min.age << std::endl
              << "Score:" << min.score << std::endl
	      <<std::endl;
	if(max==nullptr)
	{
		std::cout<<"empty vector!"<<std::endl;
	}
	else{
	std::cout<<"Max:"<<std::endl
		 << "Name:" << max->name << std::endl
              << "Age:" << max->age << std::endl
              << "Score:" << max->score << std::endl
	      <<std::endl;
	}
	//std::cout<<"Average:"<<getAverage(student);

	

	std::cout<<getAverage(empty)<<std::endl;

	return 0;
}
