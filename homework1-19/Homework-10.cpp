#include <iostream>
#include <ctime>
//10.guess the number
int guess(int , int);
int main() 
{
    std::srand(time(NULL));
    int rndm = rand() % 90 + 10; //random 2digit number
    int attempts = 0;
    std::cout<<"Level 1:try to guess two digit number\n"<<guess(rndm , attempts)<<std::endl;
    rndm = rand() % 900 + 100; //random 3digit number
    attempts = 0;
    std::cout<<"Level 2:try to guess three digit number\n"<<guess(rndm , attempts)<<std::endl;
    rndm = rand() % 9000 + 1000; //random 4digit number
    attempts = 0;
    std::cout<<"Level 3:try to guess four digit number\n"<<guess(rndm , attempts)<<std::endl;
    return 0;
}

int guess(int rndm, int attempts)
{
    int num=0;
    while (true)
    {   
        attempts++;
        std::cin>>num;
        if (num==rndm)
        {
           std::cout<<"correct"<<std::endl;
           break;
           return attempts; 
        }
        else if (num>rndm)
        {
            if (num-rndm>10) std::cout<<"So High"<<std::endl;
            else std::cout<<"High"<<std::endl;
        }
        else if (num<rndm)
        {
            if (rndm-num>10) std::cout<<"So Low"<<std::endl;
            else std::cout<<"Low"<<std::endl;
        }
    }
    return attempts;
}
