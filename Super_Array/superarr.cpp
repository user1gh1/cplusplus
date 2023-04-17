#include "superarr.hpp"

SuperArr::SuperArr()
{
        this->m_size = 10;
		this->m_capacity = m_size * 2;
        this->m_sarr = new int [m_capacity];
        for (int i = 0 ; i < m_size; i++)
        {
            m_sarr[i]=i;
        }
}
//constructor with size of array
SuperArr::SuperArr(int size)
{
    this->m_size = size;
	this->m_capacity = size * 2;
    this->m_sarr = new int [m_capacity];
    for (int i = 0 ; i < m_size; i++)
    {
        m_sarr[i]=i;
    }
}
//Copy Constructor
SuperArr::SuperArr(const SuperArr& other)
{
    if (this->m_sarr!=nullptr)
    {
        delete [] m_sarr;
    }
	this->m_size = other.m_size;
	this->m_capacity = other.m_capacity;
	this->m_sarr = new int [m_capacity];
    for (int i = 0; i < m_capacity; i++)
    {
        this->m_sarr[i] = other.m_sarr[i];
    }
}
//destructor for delete dinamic arr
SuperArr::~SuperArr()
{
    delete [] this->m_sarr;
}
// function to print all arr
void SuperArr::Print()
{
    for (int i = 0 ; i < m_size; i++)
    {
        std::cout << m_sarr[i] << std::endl;
    }
}
// function to print index arr
void SuperArr::Print(int index)
{
    if (index >= this->m_size || index < 0)
    {
        std::cout << "out of range" << std::endl;
    }
    else
    {
        std::cout << m_sarr[index] << std::endl;
    }
}
void SuperArr::Set(int num, int index)
{
    if (index >= m_size || index < 0)
    {
        std::cout << "index out of range" << std::endl;
    }
    else
    {
        m_sarr[index] = num;
    }
}
int SuperArr::Get(int index)
{
    if (index >= m_size || index < 0)
    {
        std::cout << "index out of range" << std::endl;
    }
        return m_sarr[index];
}
void SuperArr::ShowSize()
{
    std::cout << "Size of array: " << m_size << "Capacity of array: " << m_capacity <<  std::endl; 
}
// function to delete index in arr
void SuperArr::Remove(int index)
{
    if (index >= m_size || index < 0)
    {
        std::cout << "index delete out of range" << std::endl;
    }
    else
    {
        m_size--;
        for (int i = index; i < m_size; i++)
        {
			m_sarr[i] = m_sarr[i+1]; 
        }
    }
}
void SuperArr::Insert(int numToAdd, int index)
{
    if (index > m_size || index < 0)
    {
        std::cout << "index delete out of range" << std::endl;
    }
    else if (m_size == m_capacity)
    {
        this->m_size++;
		this->m_capacity = m_size * 2;
        int* temp = new int[m_capacity];
        // Copy the contents of the old array up to the insertion point
        for (int i = 0; i < index; i++) {
            temp[i] = m_sarr[i];
        }
        // Add the new number at the insertion point
        temp[index] = numToAdd;
        // Copy the rest of the contents of the old array
        for (int i = index; i < m_size -1; i++) {
            temp[i + 1] = m_sarr[i];
        }
        delete[] m_sarr;
        m_sarr = temp;
    }
    else
    {
        //move all numbers from end-index by 1  
        this->m_size++;
        for (int i = m_size ; i > index ; i--) {
            m_sarr[i] = m_sarr[i-1];
        }
        m_sarr[index] = numToAdd;
    }
}
void SuperArr::PushBack(int num)
{
	if (m_size < m_capacity)
	{
		m_sarr[m_size] = num;
		m_size++;
	}
	else
	{
		Insert(num , m_size);
	}
}
//rewrite operator = for copy arr

SuperArr& SuperArr::operator=(const SuperArr& other)
{
    if (this->m_sarr!=nullptr)
    {
        delete [] m_sarr;
    }
    this->m_size = other.m_size;
    this->m_capacity = other.m_capacity;
    this->m_sarr = new int [m_capacity];

    for (int i = 0; i < m_capacity; i++)
    {
        this->m_sarr[i] = other.m_sarr[i];
    }
    return *this;
}
