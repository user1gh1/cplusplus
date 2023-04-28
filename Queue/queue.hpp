#pragma once 
#include <iostream>
#include <cassert>
#include <string>

class Node
{
public:
	int data;
	Node* next;

	Node(int value);
};

class Queue
{
private:
	int size = 0;
	Node*first;
	Node*last;
public:
	//constructor
	Queue();
	//destructor
	~Queue();
	//copy constructor
	Queue(const Queue& other);
	//Return size
    int get_size();
    //Print all elements
    void print();
    //Return true/false 
    bool empty();
    //Return element from the end
    int top();
    //Push element to the end 
    void enqueue(int value);
    //Delete element from the end
    int dequeue();
};
