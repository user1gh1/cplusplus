#include <iostream>
//16.For each number add 0 
//for example input 125 = output 502010:
int main() 
{
    int num=0;
    std::cout<<"Enter the number: "<<std::endl;
    std::cin>>num;
    int recursive=0;
    while (num!=0)
    {
        recursive = (recursive*10)+num%10;
        recursive *=10;
        num=num/10;
    }
    std::cout<<"Answer is: " << recursive <<std::endl;  
    return 0;
}
