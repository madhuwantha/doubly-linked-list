#pragma once
#include "Node.h"

#include <iostream>
using namespace std;


class Link
{
public:
	Link();

	Node* head;
	Node* tail;
	int size;


	void addItem(int v, int pos);
	void addToFirst(int v);
	void addToLast(int v);
	void deleteItem(int pos);
	void deleteFirst();
	void deleteLast();
	void printItems();


	~Link();
};

