#pragma once
#include <iostream>
#include "Element.h"
#ifndef LIST
#define LIST
#define tab "\t"
using std::cout;
using std::cin;
using std::endl;
class List
{
	int Size;
	Element* Head;
	Element* Tail;
	int GetSize() { return Size; };
public:
	List(); 
	//List(const initializer_list<int>& il) :List(); //Контейнер как наш ForwardList
	//List(const List& other) :List() {};
	~List();

	// Methods
	void push_front(int Data);
	void push_back(int Data);

	void pop_front();
	void pop_back();
	

	void insert(int Data, int index);
	void erase(int index);
	

	void print();
	void clear();

	
	

};
#endif // !LIST

