#include "linked_list.hpp"

//Constructor
LinkedList::LinkedList()
{
        this->first = nullptr;
}

//another constructor 
Node::Node(int value)
{
	this->data = value;
	this->next = nullptr;
}
//Copy Constructor
LinkedList::LinkedList(const LinkedList& other)
{
	Node* temp = other.first;
	while (temp!=nullptr)
	{
		push_back(temp->data);
		temp = temp->next;
	}
}
//Destructor
LinkedList::~LinkedList()
{
	Node* k = first;
	while (k != nullptr)
	{
		Node* n = k->next;
		delete k;
		k = n;
	}
}
//Add to the end value
void LinkedList::push_back(int value)
{
	Node* k = new Node(value);
	if(this->first == nullptr)
	{
		this->first = k;
	}
    else
	{
		Node* temp = first;

	    while (temp->next != nullptr) 
		{
			temp = temp->next;
		}

		temp->next = k;
	}	

}
//Remove value to the end
void LinkedList::pop_back()
{
	if (this->get_size() <= 1)
	{
		this->first = nullptr;
	}
	else
	{
		Node* n = first;
		Node* x = first;
		while(n->next != nullptr)
		{
			x = n;
			n = n->next;
		}
		// Now x == penultimate element , delete last element and set nullptr
		delete x->next;
		x->next = nullptr;
	}
}
//Print all array
void LinkedList::print ()
{
	Node* n = first;
	while (n != nullptr)
	{
		std::cout << n->data << std::endl;
		n = n->next;
	}
}
//Get Size
int LinkedList::get_size()
{
	int size = 0;
	Node* n = first;
	while (n != nullptr)
	{
		size++;
		n = n->next;
	}
	return size;
}
//Boolean function Is Empty
bool LinkedList::is_empty()
{
	if (first == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//Insert function
void LinkedList::insert(int index,int value)
{
	//be care , Don't give index Out of Range
	assert ((index >= 0) && (index <= get_size()));

	Node* n = new Node(value);
	if (index == 0)
	{
		n->next = first;
		first = n;
	}
	else
	{
		Node* temp = first;
		for (int i = 0; i < index - 1; i++)
		{
			temp = temp->next;
		}
		n->next = temp->next;
		temp->next = n;
	}
}
//Remove function 
void LinkedList::remove_index(int index)
{
	//be care , Don't give index Out of Range
	assert ((index >= 0) && (index < get_size() ));

	if (index == 0)
	{
		Node* n = first->next;
		delete first;
		first = n;
	}
	else
	{
		Node* n = first;
		Node* n_undo;
		for(int i = 0; i < index; i++)
		{
			n_undo = n;
			n = n->next;
		}
		n_undo->next = n->next;
		delete n;
	}
}
//Remove by value and flag
// "-a" Delete ALL , "-f" Delete First
// if you write another Flag: "-f" Is Automatically selected
void LinkedList::remove_value_flag(int value,std::string flag)
{
	Node* n = first;
	bool find = false;
	for (int i = 0; i < get_size() ; i++)
	{
		if(n->data == value)
		{
			remove_index(i);
			find = true;
			break;		
		}
	}
	// If flag -a Call Recursive this function while can find duplicates of value
	if (find==true && flag =="-a")
	{
		remove_value_flag(value,"-a");
	}
}

//Return Reference int for Get or Set data
int& LinkedList::operator [] (int index)
{
	//be care , Don't give index Out of Range
	assert ((index >= 0) && (index < get_size() ));

	Node* n = first;
	for(int i = 0; i < index; i++)
		{
			n = n->next;
		}
	return n->data;
}


