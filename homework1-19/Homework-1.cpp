#include <iostream>
//1. Calculate sum of the digits
int main ()
{
    int inpt=0;
    int sum=0;
	std::cout<<"Enter the number: "<<std::endl;
    std::cin>>inpt;
    while (inpt>0)
    {
        sum += inpt%10;
        inpt = inpt/10;
    }
    std::cout<<"Sum= "<< sum <<std::endl;   
    return 0;
}
