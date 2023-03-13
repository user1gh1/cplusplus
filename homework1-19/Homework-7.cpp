#include <iostream>
//7.Draw Rectangle
int main() 
{
    int row=12;
    int column=3;
    char symb='#'; 
    char arr[row][column]={} ;

    std::cout << "Write Int(Length) of Rectangle"<< std::endl;
    std::cin >> row;
    std::cout << "Write Int(Height) of Rectangle"<< std::endl;
    std::cin >> column;
    std::cout << "Write Char(Symbol) of Rectangle"<< std::endl;
    std::cin >> symb;
    //write symb or space for draw rectangle
    for (int i = 0 ; i < row ; i++)
    {
        for (int j = 0 ; j < column ; j++)
        {
            if ((i==0 || i==row-1) || (j==0 || j==column-1))
            {
                arr[i][j]=symb;
            }
            else 
            {
                arr[i][j]=' ';
            }
        }
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
