#include <iostream>
#include <string>

class human
{
public:
    std::string name;
    int age;
};

void bubblesort(human* arr,int n);

int main() 
{
    human anna,albert,tigran,samvel,john;
    anna.age = 31;
    albert.age = 23;
    tigran.age = 33;
    samvel.age = 41;
    john.age = 72;
    anna.name = "Anna";
    albert.name = "Albert";
    tigran.name = "Tigran";
    samvel.name = "Samvel";
    john.name = "John";
    int SIZE = 5;
    human arr[SIZE] = {anna,john,tigran,samvel,albert};
    bubblesort(arr, SIZE);    
    //show
    for (int i = 0; i < 5 ; i++)
		std::cout << arr[i].name<< " ";
    
    return 0;
}

void bubblesort(human* arr,const int SIZE)
{
	human tmp;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE-1; j++)
		{
			if (arr[j].age > arr[j+1].age)
			{   
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}
}