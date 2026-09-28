#include<iostream>

int add(int a,int b)
{
	return a+b;
}

int main()
{
	int x=10;
	int y=20;

	int sum=add(x,y);

	std::cout<<sum<<std::endl;

	return 0;
}
