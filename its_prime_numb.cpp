#include <iostream>
#include <string>

std::string isprime(long);
int main()
{
	long numb;
	std::cin >> numb;
	std::cout << isprime(numb) << std::endl;
return 0;
}

std::string isprime(long numb)
{
	for (int i =2; i<numb/2; i++)
	{
		if ( numb % i == 0 ) 
		{
			return "Not prime";
		}
	}
	return "Prime";
}
