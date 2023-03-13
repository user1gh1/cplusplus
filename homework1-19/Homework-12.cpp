#include <iostream>
//12. Occurence of numbers
//Write a program which will allow user to input numbers in range 1-10 
//(as much as the user would like to, till -1 is entered).
//Calculate and print how many times each of the numbers have been entered.1
int main() 
{
    int SIZE = 10;
    int arr[SIZE]={};
    int inpt=0;
    while (inpt!=-1)
    {
        std::cout<<"Write number from 1 to 10"<<std::endl;
        std::cin>>inpt;
        if (inpt>0 && inpt<11)
            arr[inpt-1]++;
    }
    for (int i = 0; i<SIZE; i++)
        std::cout<<arr[i]<<' ';

    return 0;
}
