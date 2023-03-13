#include <iostream>
#include <string>
//11.Guess a number (roles changed)
int main() 
{
    int attempts = 0;
    std::cout<<"think random digit from 1 - 100: "<<std::endl;
    std::cout<<"I guess it in 7 or fewer attempts."<<std::endl;
    std::cout<<"Write big or small or correct"<<std::endl;
    int start = 1;
    int end = 100;
    std::string answer="";
    while (true)
    {
        attempts++;
        std::cout << "Is it "<< start+(end-start)/2 <<" ?"<<std::endl;
        std::cin >> answer;
        //answer="small";
        if (answer=="correct")
        {
            std::cout<<"I used "<< attempts <<" attempts" << std::endl;
            return 0;
        }
        else if(answer=="big")
        {
            end=end/2;
            continue;
        }
        else if(answer=="small")
        {
            start=start + (end-start)/2;
            continue;
        }
    }
    
    return 0;
}
