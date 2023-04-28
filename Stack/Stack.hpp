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

class Stack
{
private:
	int size;
	Node* first;
public:
	//constructor
	Stack();
    //destructor
    ~Stack();
    //copy constructor
    Stack(const Stack& object);
    //Return size
    int get_size();
    //Print all elements
    void print();
    //Return true/false 
    bool empty();
    //Return element from the end
	int top();
    //Delete element from the end
	void pop();
    //Push element to the end 
	void push(int value);
};	

