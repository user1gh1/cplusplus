#include <iostream>
//17.Calculate  1+1/1!+...1/N!
double sum(double);
int main()
{
    int n = 0;
    std::cout << "Write n for calculate 1+1/1!+1/2!+1/3!+…+1/N!"<<std::endl;
    std::cin >> n;
    std::cout << sum(n) <<std::endl;
    return 0;
}
double sum(double n)
{
    double sum = 0;
    double fact = 1;
    for (int i = 1; i <= n; i++)
    {
       fact *= i;        
       sum += 1/fact;   
    }
    return sum;
}
