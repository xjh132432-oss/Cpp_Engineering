#include<iostream>
#include<unistd.h>

int main()
{
	while(true)
	{
		std::cout<<"process is running"<<std::endl;
		
		sleep(2);
	}

	return 0;
}
