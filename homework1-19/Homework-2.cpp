#include <iostream>
//2. Inverse the number
//E.g. Input 163 - Output 361
void reverseint(long long&,long long&);
int main ()
{
    long long inpt=0;
    long long rvrs=0;
    std::cin>>inpt;

    if (inpt < 0)
    {   
    inpt = -inpt;
    reverseint(inpt, rvrs);
    rvrs = -rvrs;
    }
    else reverseint(inpt, rvrs);

    std::cout<<"Reverse= "<< rvrs <<std::endl;   
    return 0;
}
void reverseint(long long&inpt,long long&rvrs)
{
    while (inpt>0)
    {
        rvrs = (rvrs*10) + inpt%10;
        inpt = inpt/10;
    }
}
