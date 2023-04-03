#include <iostream>
void sort (int*,int);

int main()
{
	int size=0;
	std::cout<<"Write array size"<<std::endl;
	std::cin>>size;
	int *ptrarray = new int[size];
	for (int i = 0; i< size; i++)
		std::cin>>ptrarray[i];
	sort(ptrarray,size);
	for (int i = 0; i< size; i++)
		std::cout<<ptrarray[i]<<' ';
	
	std::cout<<std::endl;
	delete [] ptrarray;
	return 0;
}

void sort (int *arr , int size)
{
	char y = '0';
	std::cout<<"Want reverse sort ? press : y"<<std::endl;
	std::cin>>y;
	for (int i = 0 ; i < size-1; i++)
	{
		int temp = arr[i];
		if (y=='y')
			{
				if (temp < arr[i+1])
				{
					arr[i] = arr[i+1];
					arr[i+1] = temp;
					i = -1;
				}
			}
		else
			{
				if (temp > arr[i+1])
				{
					arr[i] = arr[i+1];
					arr[i+1] = temp;
					i = -1;
				}
			}

	}
}

