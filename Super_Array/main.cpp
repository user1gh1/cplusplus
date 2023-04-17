#include <iostream>
#include "superarr.hpp"

int main()
{
    SuperArr sarr(10);
    sarr.Print();
    sarr.ShowSize();
	sarr.Insert(77,4);

    std::cout << sarr.Get(10) << std::endl;
    
    sarr.Set(99,4);
    for(int i = 0; i < 10; i++)
    {
        sarr.Insert(77,4);
    }

    sarr.ShowSize();
    sarr.Print();

	SuperArr sarr2 (sarr);
    return 0;
}

