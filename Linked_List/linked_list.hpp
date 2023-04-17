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

class LinkedList 
{
private:
	Node* first;
public:
	//add value to the end
	void push_back(int value);
	//remove value to the end
	void pop_back();
	//constructor
	LinkedList();
	//copy constructor
	LinkedList(const LinkedList& other);
	//destructor
	~LinkedList();
	//Print
	void print();
	//Size check
	int get_size();
	//Empty check
	bool is_empty();
	//Insert function
	void insert(int index,int value);
	//Remove function 
	void remove_index(int index);
	//Remove by value and flag
	void remove_value_flag(int value,std::string flag);
	//Overwriting operator for Get and Set in once
	int& operator [] (int index);
};
