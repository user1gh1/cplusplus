#include <iostream>
//15. Fibonacci
int main() 
{
    int a = 0;
    int b = 1;
    int num=0;
    std::cout<<"what is the consecutive number of Fibonacci you want: ?"<<std::endl;
    std::cin>>num;
    if (num==0)
    {
        std::cout<<"Fibonacci " << num <<": "<< 0 <<std::endl;
        return 0;
    } 
    for (int i = 1; i<num; i++)
    {
        int temp = b;
        b = a + b;
        a = temp;

    }
    std::cout<<"Fibonacci " << num <<": "<< b <<std::endl;  
    return 0;
}
