#include<iostream>
#include "calculator.h"
#include<unistd.h>

using namespace std;

int main()
{	
	int sum=add(10,5);
	int diff=substract(10,5);
	
	cout<<"add:"<<sum<<endl;
	cout<<"substract:"<<diff<<endl;
	
	sleep(120);

	return 0;
}
