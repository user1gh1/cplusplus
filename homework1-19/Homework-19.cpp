#include <iostream>
//19.find maxnumber and how times used
int main()
{
    int num = 0;
    std::cout<<"Enter the number: "<<std::endl;
    std::cin>>num;
    int temp = num;
    int max = 0;
    int count =0;
    while (temp!=0)
    {
        if (max < temp%10) max = temp % 10;
        temp = temp/10;
    }
    temp = num;
    while (temp!=0)
    {
        if (max == temp%10) count++;
        temp= temp/10;
    }
    std::cout<<"In number "<< num << " maxnumber is " << max << " Retry " << count << " Times." << std::endl;
    return 0;
}
