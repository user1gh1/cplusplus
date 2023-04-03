#include <iostream>
void delinarr (int *&, int &, int);
int main() 
{
    int size = 10;
    
    std::cout << "Write size of array (automatically filled with random numbers)"<<std::endl;
    std::cin >> size;
	//checking for correctness size
	if (size==0)
	{
		std::cout<<"Error: Size should be natural number and not 0"<<std::endl;
		return 1;
	}
    int *arr = new int[size];

    //fill array with random number in range 1-10
    for (int i = 0; i<size; i++)
        arr[i]=rand()%10+1;
    //show arr 
    for (int i = 0; i<size; i++)
        std::cout << arr[i] <<' ';
    std::cout << std::endl;
    //delete index input
    int delindex = 9;
    std::cout << "Write index to remove: "<<std::endl;
    std::cin >> delindex;

    //check correctly input
    if ((delindex < 0) || (delindex > size-1)) return 1;

    //function delinarr Call 
    delinarr (arr,  size , delindex);

    //show new arr 
    for (int i = 0; i<size; i++)
        std::cout << arr[i] <<' ';

    //space
    std::cout << std::endl;
    return 0;
}

void delinarr (int *&arr, int &size , const int delindex)
{
    size--;
    int *arr2 = new int[size];
    //copy arr without deleted index
    for (int i = 0, j = 0; i<size; i++,j++)
    {
        if (j == delindex) j++;
        arr2[i]=arr[j];
    }
    //delete old arr
    delete [] arr;
    //replace pointer on new arr
    arr = arr2;
}
