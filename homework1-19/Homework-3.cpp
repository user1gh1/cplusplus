#include <iostream>
#include <string>
//3.1 Input number N and print all prime numbers in the range 1-N
bool isprime(long);
long minprime(long&);

int main()
{
	long numb;
	std::cin >> numb;
	long min=numb;

	if (isprime(numb))
		std::cout << "Your number: " << numb << " Is prime" << std::endl;
	else 
		std::cout << "Your number: " << numb << " Is not prime" << std::endl;
	
	std::cout << "All primes in range from 1 to " << numb << " is: "; 
	while (min>1)
	{
			std::cout << minprime(min) << " ";
			min--;
	}
    std::cin >> numb;

	return 0;
}

long minprime(long &min)
{
	for (int i = 2; i<=min/2 ; i++)
	{
		if ( min % i == 0 ) 
		{
			--min;
			i=1;
			continue;
		}
	}
	return min;
}

bool isprime(long numb)
{
	for (int i = 2; i<=numb/2; i++)
	{
		if ( numb % i == 0 ) 
		{
			return false;
		}
	}
	return true;
}
