#include <iostream>
//8. Draw triangle
int main() 
{
    int row=0;

    std::cout << "Write Length of Triangle"<< std::endl;
    std::cin >> row;

    int column=row;
    char symb='*'; 
    char arr[row][column]={};
    int temp = 0;
    //fill triangle
    for (int i = 0 ; i < row ; i++)
    {
        for (int j = 0 ; j < column ; j++)
        {
            if ((i <= temp)&&(j <= temp))
            {
                arr[i][j]=symb;
            }
            else 
            {
                arr[i][j]=' ';
            }
        }
        temp++;
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
    //fill reverse triangle
    temp = 0;
    char arr2[row][column]={};
    for (int i = row-1 ; i >= 0 ; i--)
    {
        for (int j = column-1 ; j >= temp ; j--)
        {
                arr2[i][j]=symb;
        }
        temp++;
    }
    //show
    for (int i = 0 ; i < row ; i++)
    {
        for (int j = 0 ; j < column ; j++)
        {
            std::cout << arr2[i][j] << " " ;
        }
        std::cout << std::endl;
    }
    std::cin >> row;
	return 0;
}
