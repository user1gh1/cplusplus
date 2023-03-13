#include <iostream>
//4.Palindrome
bool palindrom_check(long long);

int main() 
{
    long long num=0;
	std::cout << "Enter a number: "<< std::endl;
	std::cin >> num;
	if (palindrom_check(num))
		std::cout << num << " is Palindrome" << std::endl;
	else 
		std::cout << num << " is Not Palindrome" << std::endl;
	return 0;
}

bool palindrom_check(long long num)
{
    long long reverse=0;
	long long numcopy=num;
	while(num>0)
	{
		reverse = (reverse*10) + num%10;
	    num = num/10;
	}
	return (reverse==numcopy);
}
