#include <iostream>
void addNumber(int , int , int*& , int&);
int main()
{
    int size = 10;

    std::cout << "We have arr with 10 random ints"<<std::endl;
    int *arr = new int[size];

    //fill array with random number in range 1-10
    for (int i = 0; i<size; i++)
        arr[i]=rand()%10+1;
    //show arr 
    for (int i = 0; i<size; i++)
        std::cout << arr[i] <<' ';
    std::cout << std::endl;
    //add number to input
    int num = 0;
    std::cout << "What number will be added : "<<std::endl;
    std::cin >> num;
	std::cout << std::endl;
    //add index input
    int addindex = 0;
    std::cout << "Write index where add : "<<std::endl;
    std::cin >> addindex;

    //check correctly input
    if ((addindex < 0) || (addindex > size)) 
	{
		std::cout << "wrong index "<<std::endl;
		return 1;
	}
    addNumber (num, addindex, arr, size);
    //show new arr 
    for (int i = 0; i<size; i++)
        std::cout << arr[i] <<' ';
    //space
    std::cout << std::endl;
    return 0;
}
void addNumber(int numToAdd, int position, int* &dynamicArray, int &size) {
    // Increase the size of the dynamic array by 1
    int* newArray = new int[size + 1];

    // Copy the contents of the old array up to the insertion point
    for (int i = 0; i < position; i++) {
        newArray[i] = dynamicArray[i];
    }

    // Add the new number at the insertion point
    newArray[position] = numToAdd;

    // Copy the rest of the contents of the old array
    for (int i = position; i < size; i++) {
        newArray[i + 1] = dynamicArray[i];
    }

    // Delete the old array and point it to the new array
    delete[] dynamicArray;
    dynamicArray = newArray;

    // Update the size of the dynamic array
    size++;
}
