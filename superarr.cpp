#include <iostream>
class SuperArr
{
	private:
	int *sarr;
	int size;
	//constructor without args
	public:
	SuperArr()
	{
		this->size = 10;
		this->sarr = new int [size];
		for (int i = 0 ; i < size; i++)
		{
			sarr[i]=i;
		}
	}
	//constructor with size of array
	SuperArr(int size)
	{
		this->size = size;
		this->sarr = new int [size];
		for (int i = 0 ; i < size; i++)
		{
			sarr[i]=i;
		}
	}
	//destructor for delete dinamic arr
	~SuperArr()
	{
		delete [] this->sarr;
	}
	// function to print all arr
	void Print()
	{
		for (int i = 0 ; i < size; i++)
		{
			std::cout << sarr[i] << std::endl;
		}
	}
	// function to print index arr
	void Print(int index)
	{
		if (index >= this->size || index < 0)
		{
			std::cout << "out of range" << std::endl;
		}
		else
		{
			std::cout << sarr[index] << std::endl;
		}
	}
	// function to delete index in arr
	void Indexdelete(int index)
	{
		if (index >= size || index < 0)
		{
			std::cout << "index delete out of range" << std::endl;
		}
		else
		{
			size--;
			int* temp = new int [size];
			//copy arr without deleted index
			for (int i = 0, j = 0; i<size; i++,j++)
			{
				if (j == index) j++;
				temp[i]=sarr[j];
			}
		    //delete old arr
			delete [] sarr;
		    //replace pointer on new arr
		    sarr = temp;
		}
	}
	void AddNumber(int numToAdd, int index) 
	{
		if (index > size || index < 0)
		{
			std::cout << "index delete out of range" << std::endl;
		}
		else
		{
			this->size++;
			int* temp = new int[size];
			// Copy the contents of the old array up to the insertion point
			for (int i = 0; i < index; i++) {
				temp[i] = sarr[i];
				std::cout << "new : " << temp[i] << " old : " << sarr[i] << std::endl;
			}
			// Add the new number at the insertion point
			temp[index] = numToAdd;
			// Copy the rest of the contents of the old array
			for (int i = index; i < size -1; i++) {
				temp[i + 1] = sarr[i];
				std::cout << "new : " << temp[i+1] << " old : " << sarr[i] << std::endl;

			}
			delete[] sarr;
			sarr = temp;
		}
	}

	// Rewrite operator = for copy arr
	SuperArr& operator =(const SuperArr &other)
	{
		if (this->sarr!=nullptr)
		{
			delete [] sarr;
		}
		this->size = other.size;
		this->sarr = new int [size];
		
		for (int i = 0; i < size; i++)
		{
			this->sarr[i] = other.sarr[i];
		}
		return *this;
	}
};

int main()
{
	SuperArr sarr;
	SuperArr sarr2(2);
	sarr.AddNumber(999,1);
	sarr.Print();
	
	sarr.Indexdelete(1);
	sarr.Print();

	return 0;
}
