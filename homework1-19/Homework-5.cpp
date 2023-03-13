#include <iostream>
//5.Concanate numbers 
//35+47=3547;
int main() 
{
    long long num=0;
    long long num2=0;

	std::cout << "Enter first number for concatenate : "<< std::endl;
	std::cin >> num;
    std::cout << "Enter second number for concatenate : "<< std::endl;
	std::cin >> num2;

    int i = 1;
    do
    {
        num *= 10;
        i = i*10;
    } while (i <= num2);
    
    std::cout << "concatenate : "<< num+num2 << std::endl;
	return 0;
}

