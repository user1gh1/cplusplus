#include "queue.hpp"
//Node Constructor
Node::Node(int value)
{
	data = value;
	next = nullptr;
}
//Constructor
Queue::Queue()
{
	first = nullptr;
	size = 0;
}
//Destructor
Queue::~Queue()
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
int Queue::get_size()
{
    return size;
}
//Return Boolean Size
bool Queue::empty()
{
    return size==0;
}
//Copy Constructor
Queue::Queue(const Queue& other)
{
    Node* k = other.first;
	if (k == nullptr)
	{
		first = nullptr;
	}
	else
	{
		while (k != nullptr)
		{
			enqueue(k->data);
		    k = k->next;
		}
	}
}
//Push
void Queue::enqueue(int value)
{
    Node* k = new Node(value);
    //if size 0 first and last = k
	if (size == 0)
	{
		first = k;
		last = k;
	}
	else 
	{
		last->next = k;
		last = k;
	}
	size++;
}
//Pop
int Queue::dequeue()
{
	//assert need because function int return
	assert(size>0);
	int value = first->data;
    Node* k = first;
    first = first->next;
    delete k;
	if (first == nullptr)
	{
		last = nullptr;
	}
	size--;
	return value;
}
//Top
int Queue::top()
{
    //assert need because function return int
    assert(size>0);
    return first->data;
}
//print
void Queue::print()
{
    Node* k = first;
    while (k != nullptr)
    {
        std::cout << k->data << std::endl;
        k = k->next;
    }
}

