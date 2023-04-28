#include <iostream>
#include <string>
#include <cassert>

template<typename T>
class DoubleList
{
private:
//Node Class with his constructor
//2 pointer and Size
class Node {
	public:
		T data;
		Node* next;
		Node* prev;
		Node(T data)
		{
			this->data = data;
			this->next = nullptr;
			this->prev = nullptr;
		}
};
	Node* head;
	Node* tail;
	int size;
public:
			DoubleList();
			~DoubleList();
			void push_back(T value);
			void push_front(T value);
			void pop_back();
			void pop_front();
			T back();
			T front();
			int get_size();
			void insert(T value, int index);
			void reverse();
			void print();
			//index start from 0
			T& operator[](const int index);
};
template<typename T>
//constructor
DoubleList<T>::DoubleList()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}
template<typename T>
//destructor
DoubleList<T>::~DoubleList()
{
	while (head != nullptr)
	{
		Node* k = head;
		head = head->next;
		delete k;
	}
}
template<typename T>
//push from end
void DoubleList<T>::push_back(T value)
{
	Node* n = new Node(value);
	if (tail == nullptr)
	{
		head = tail = n;
	}
	else 
	{
		n->prev = tail;
		tail->next = n;
		tail = n;
	}
	size++;
}
template<typename T>
//push from start
void DoubleList<T>::push_front(T value)
{
	Node* n = new Node(value);
	if (head == nullptr)
	{
		head = tail = n;
	}
	else 
	{
		n->next = head;
		head->prev = n;
		head = n;
	}
	size++;
}
template<typename T>
void DoubleList<T>::pop_back()
{
	if (tail != nullptr)
	{
		Node* n = tail;
		tail = tail->prev;
		delete n;
		size--;
		if (tail == nullptr)
		{
			head = nullptr;
		}
		else 
		{
			tail->next = nullptr;
		}
	}
}
template<typename T>
void DoubleList<T>::pop_front()
{
	if (head != nullptr)
	{
		Node* n = head;
		head = head->next;
		delete n;
		size--;
		if (head == nullptr)
		{
			tail = nullptr;
		}
		else 
		{
			head->prev = nullptr;
		}
	}

}
template<typename T>
T DoubleList<T>::front()
{
	if (head != nullptr)
	{
		return head->data;
	}
}
template<typename T>
T DoubleList<T>::back()
{
	if (tail != nullptr)
	{
		return tail->data;
	}
}
template<typename T>
int DoubleList<T>::get_size()
{
	return size;
}
template<typename T>
void DoubleList<T>::insert(T value, int index)
{
	//be care , Don't give index Out of Range
	assert ((index >= 0) && (index <= size));
	if (index ==0) 
	{
		push_front(value);
	}
	else if(index == size)
	{
		push_back(value);
	}
	else
	{
		Node* n;
		if(index <= size/2)
		{
			n = head;
			for (int i = 0; i < index-1; i++)
			{
				n = n->next;
			}
		}
		else
		{
			n = tail;
			for (int i = size ; i > index; i--)
			{
				n = n->prev;
			}
		}
		Node* insertNode = new Node(value);
		insertNode->prev = n;
		insertNode->next = n->next;
		n->next->prev = insertNode;
		n->next = insertNode;
		size++;
	}
}
template<typename T>
void DoubleList<T>::reverse()
{
	Node* Headpt = head;
	Node* Tailpt = tail;
	for(int i = 0; i<size/2; i++)
	{
		T temp = Headpt->data;
		Headpt->data = Tailpt->data;
		Tailpt->data = temp;
		Headpt = Headpt->next;
		Tailpt = Tailpt->prev;
	}
}
template<typename T>
void DoubleList<T>::print()
{
	Node* k = head;
	while (k != nullptr)
	{
		std::cout << k->data << std::endl;
		k = k->next;
	}
}
template<typename T>
T& DoubleList<T>::operator[](const int index)
{
	Node* Headpt = head;
	for (int i = 0; i<index; i++)
	{
		Headpt = Headpt->next;
	}
	return Headpt->data;
}
