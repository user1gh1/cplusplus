#include <iostream>
#include <cmath>
//18.Armstrong numbers
int main()
{
    int sum = 0;
    int count = 0;
    int temp = 0;
    for (int i = 10; i < 10000; i++)
    {
        temp = i;
        while (temp!=0)
        {
            temp = temp / 10;
            count++;
        }
        temp = i;
        while (temp)
        {
            sum += pow(temp%10,count);
            temp = temp / 10;
        }
        if (sum == i) 
        {
            std::cout<< i <<std::endl;
        }
        sum = 0;
        count = 0;
        
    }
    return 0;
}
