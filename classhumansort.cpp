#include <iostream>
#include <string>

class human
{
    std::string name;
    int age;
	public:
 	human()
	{
		name = "";
		age = 0;
	}
	human(int age , std::string name)
	{
		this->age = age;
		this->name = name;
	}
	human(std::string _name,int _age )
	{
		age = _age;
		name = _name;
	}
	bool human operator > (const human & other)
	{
		return (this.age > other.age)
	}
	bool human operator < (const human & other)
	{
		return (this.age < other.age)
	}
	int get_age()
	{
		return age;
	}
	std::string get_name()
	{
		return name;
	}
};

void bubblesort(human* arr,int n);

int main() 
{

    human anna ("Anna", 26);
    human albert ( 23, "Albert" );
    human tigran (33, "Tigran");
    human samvel (41, "Samvel");  
    human john (72, "John");

    int SIZE = 5;
    human arr[SIZE] = {anna,john,tigran,samvel,albert};
    bubblesort(arr, SIZE);    
    //show
    for (int i = 0; i < 5 ; i++)
		std::cout << arr[i].get_name() << " ";
    std::cout<<std::endl;    
    return 0;
}

void bubblesort(human* arr,const int SIZE)
{
	human tmp;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE-1; j++)
		{
			if (arr[j] > arr[j+1])
			{   
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}
}
