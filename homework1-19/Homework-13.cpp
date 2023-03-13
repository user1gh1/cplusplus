#include <iostream>
//13.Deci to binary
long long bin_to_deci(int num);

int main() 
{
    int num = 0;
    std::cout << "Write Decimal number" << std::endl;
    std::cin >> num;
    long long bin = bin_to_deci(num);

    std::cout << num << " in Binary is "<< bin << std::endl;
    return 0;
}

long long bin_to_deci(int num)
{
    long long bin = 0;
    int remainder;
    int i = 1;
    while(num!=0)
    {
        remainder = num % 2;
        bin += remainder*i;
        i = i * 10;
        num = num / 2;
    }
    return bin;
}
