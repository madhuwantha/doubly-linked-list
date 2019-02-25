#pragma once
#include <iostream>
using namespace std;

class Node
{
public:
	int key;
	Node* next;
	Node* prev;
	Node();
	~Node();
};

