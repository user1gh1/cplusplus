#include <iostream>
#include <ctime>
int* get_max_numb(int*, int);

int main()
{
	srand(time(NULL));
	std::cout << "Write Length Array" << std::endl;
	// Input Size of dinamic array and fill random numbers for 0-99
	int size = 0;
	std::cin >> size;
	int *arr = new int[size];

	for (int i = 0 ; i < size ; i++)
	{
		arr[i]=rand()%100;
	}
	// In counts(array) keep how many times has been used numbers 0-9; 
	int* counts;
	counts = get_max_numb(arr,size);
	
	int max = counts[0];
	int maxindex = 0;
	// find max used number 
	for (int i = 0 ; i < 10 ; i++)
	{	
		if (max < counts[i]) max = counts[i], maxindex = i;
	}
	// print answer 
	std::cout<<"In array max used number is: " << maxindex << ".  Its has been used " << max << " Times.\n";
	
	return 0;
}

int* get_max_numb(int* arr, int size )
{
	static int counts[10];

	for (int i = 0 ; i < size ; i++)
	{
		if (arr[i] == 0) 
		{
		counts[0]++;
		continue;
		}
		while(arr[i] > 0)
		{
			int num = arr[i]%10;
			for( int x = 0 ; x < 10 ; x++)
			{	
				if (num == x) 
				{
					counts[x]++;
					arr[i]=arr[i]/10;
					break;
				}
			}
		}
	}
	return counts;
}
