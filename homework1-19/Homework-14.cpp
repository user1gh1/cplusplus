#include <iostream>
#include <cmath>
//14 Binary to deci
int bin_to_deci(long long num);

int main() 
{
    long long num = 0;
    std::cout << "Write Binary number" << std::endl;
    std::cin >> num;
    long long deci = bin_to_deci(num);
    std::cout << num << " in Decimal is "<< deci << std::endl;
    return 0;
}

int bin_to_deci(long long num)
{
    int deci = 0;
    int remainder;
    int i = 0;
    while(num!=0)
    {
        remainder = num % 10;
        deci += remainder * pow(2,i);
        i++;
        num = num / 10;
    }
    return deci;
}
