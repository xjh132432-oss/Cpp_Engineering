#include "student.h"
#include<iostream>


int main()
{
    std::vector<Student> student;
    
    int choice=0;

    while(choice!=5)
    {   
        std::cout<<"1. 添加学生"<<std::endl
                <<"2. 查看所有学生"<<std::endl
                <<"3. 查询学生"<<std::endl
                <<"4. 查看分析"<<std::endl
                <<"5. 退出"<<std::endl;

        std::cin>>choice;

        switch (choice)
        {
        case 1:
            addStudent(student);
            break;
        case 2:
            ShowAll(student);
            break;
        case 3:
            FindStudent(student);
            break;
        case 4:
            ShowStatistics(student);
            break;
        case 5:
            break;
        default :
            std::cout<<"wrong code!"<<std::endl;
            break;
        
        }
    }
    

    return 0;
}