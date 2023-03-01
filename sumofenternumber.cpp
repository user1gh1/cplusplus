#include<iostream>

int main()
{
	int num=0;
	int sum=0;
	std::cin>>num;
	while (num>0) {
		sum += num%10;
		num = num/10;
	}

	std::cout<<"sum = "<<sum<<std::endl;
	return 0;
}
