#include "Stack.hpp"
//node constructor
Node::Node(int value)
{
    data = value;
    next = nullptr;
}
//Constructor
Stack::Stack()
{
        first = nullptr;
		size = 0;
}
//Destructor
Stack::~Stack()
{
	Node* k = first;
	while (k != nullptr)
	{
	    Node* n = k->next;
		delete k;
		k = n;
	}
}
//Return Size
int Stack::get_size()
{
	return size;
}
//Return Boolean Size
bool Stack::empty()
{
	return size==0;
}
//Copy Constructor
Stack::Stack(const Stack& other)
{
	Node* k = other.first;
	while (k != nullptr)
	{
		push(k->data);
		k = k->next;
	}
}
//Push
void Stack::push(int value)
{
	Node* k = new Node(value);
	//if size 0 k next = nullptr
	k->next = first;
	first = k;
	size++;
}
//Pop
void Stack::pop()
{
if (size>0)
{
	Node* k = first;
	first = first->next;
	delete k;
}
}
//Top
int Stack::top()
{
	//assert need because function return int
	assert(size>0);
	return first->data;
}
//print
void Stack::print()
{
	Node* k = first;
	while (k != nullptr)
	{
		std::cout << k->data << std::endl;
		k = k->next;
	}
}

