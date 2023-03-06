#include <iostream>
#include <string>

bool isprime(long);
long minprime(long);
long maxprime(long);
int main()
{
	long numb;
	std::cin >> numb;
	long min=numb-1;
	long max=numb+1;
	if (isprime(numb))
	{
		std::cout << "Your number: " << numb << " Is prime" << std::endl;
	}
	else 
	{
		std::cout << "Nearest high prime number: " << maxprime(max) <<std::endl;
		std::cout << "Nearest low prime number: " << minprime(min) <<std::endl;

	}
	return 0;
}

long maxprime(long max)
{
	for (int i = 2; i<=max/2 ; i++)
	{
		if ( max % i == 0 ) 
		{
			++max;
			i=1;
			continue;
		}
	}
	return max;
}

long minprime(long min)
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
