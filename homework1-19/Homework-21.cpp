#include <iostream>
bool check_sort(int*,int);
int main () 
{
	std::cout<<"Write length of array"<<std::endl;
	int size = 0;
	std::cin>>size;
	int *arr = new int[size];

	std::cout<<"Fill array for check , sorted or not"<< std::endl;
	for (int i = 0 ; i<size; i++)
	{
		std::cin>>arr[i];	
	}
	if (check_sort(arr,size)) 
		std::cout<< "Yes it's sorted" << std::endl;
	else 
		std::cout<< "No it's not sorted" << std::endl;
	return 0;
}
bool check_sort(int* arr,int size)
{
	// check if in array only 1 number 
	if (size == 1) return true;
	// check ascending or descending order
	if (arr[0] > arr[size-1])
	{
		for (int i = 0; i < size-1;  i++)
		{
			if (arr[i] < arr[i+1]) return false;
		}
		return true;
	}
	else 
	{
		for (int i = 0; i < size-1;  i++)
		{
			if (arr[i] > arr[i+1]) return false;
		}
		return true;
	}
}
