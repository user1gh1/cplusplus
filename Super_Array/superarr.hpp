#pragma once
#include <iostream>

class SuperArr
{
private:
    int* m_sarr;
    int m_size;
	int m_capacity;
public:
    SuperArr();
    SuperArr(int size);
    ~SuperArr();
	SuperArr(const SuperArr& other);

    void Set(int num, int index);
    int Get(int index);
    void ShowSize();

	void PushBack(int num);
    void Print();
    void Print(int index);
    void Remove(int index);
    void Insert(int numToAdd, int index);
    SuperArr& operator=(const SuperArr& other);
};
