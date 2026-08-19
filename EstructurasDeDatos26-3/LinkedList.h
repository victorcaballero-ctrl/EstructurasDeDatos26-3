#pragma once
#include "Nodo.h"
class LinkedList
{
private:
	int _size;
	Nodo* _first;
	Nodo* _last;

public:
	LinkedList();
	void Add(int dato);
	int GetAt(int index);
	int GetSize();
	void Print();
	void SelectionSort();
	void InsertionSort();
	~LinkedList();
};

