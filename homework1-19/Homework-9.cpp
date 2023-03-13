#include <iostream>
//9. Draw Full Triangle
int main() 
{
    int column=0;
    std::cout << "Write Base of Isosceles Triangle (odd)"<< std::endl;
    std::cin >> column;

    if (column % 2 ==0)
    {
        std::cout << "Error. Need odd number for Isosceles Triangle"<< std::endl;
        return 1;
    }

    int row = column/2+1;
    char symb='*'; 
    char arr[row][column]={};
    int end=column;
    int start=0;

    //fill triangle
    for (int i = row-1 ; i >= 0 ; i--)
    {
        for (int j = start ; j < end ; j++)
        {
            arr[i][j]=symb;
        } 
        start++;
        end--;
    }

    //show
    for (int i = 0 ; i < row ; i++)
    {
        for (int j = 0 ; j < column ; j++)
        {
            std::cout << arr[i][j] << " " ;
        }
        std::cout << std::endl;
    }
	return 0;
}
