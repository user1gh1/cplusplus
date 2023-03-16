#include <iostream>
int binary_s(int*,int,int);
int main () 
{
	int size = 10;
	int arr[size]={1,2,3,4,5,6,7,8,9,10};
	int numb = 0; 
	std::cin>>numb;
	std::cout<<binary_s(arr,size,numb)<<"\n";

	return 0;
}

int binary_s(int* arr, int size, int numb)
{
	int st = 0;
	int end = size-1;
	int mid = 0;
	
	while ( st <= end ) 
	{
		mid = (end-st)/2 + st;
		
		if ( arr[mid] == numb ) 
		{
			return mid;
		}
		else if ( arr[mid] > numb )
		{
			end = mid - 1;
		}
		else 
		{
			st = mid +1;
		}
			
	}
	return -1;
}
