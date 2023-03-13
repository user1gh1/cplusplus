#include <iostream>
//6.Power of 2;
//check it is a power of 2.
int main() 
{
    long long num=0;

	std::cout << "Enter number for check : is it power of 2 ? "<< std::endl;
	std::cin >> num;
    
    int j = 0;
    for (int i = 2; i<=num; i=i*2 )
    {
        j++;
        if (i==num)
        { 
            std::cout << num << " It's power of 2 " << "^ " << j << std::endl;
            return 0;
        }
    }
    std::cout << num << " It's not power of 2 " << std::endl;
	return 0;
}

