// doubleLinkList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>
#include "Link.h"
using namespace std;

int main()
{
	Link* link = new Link;

	for (int i = 0; i < 20; i++)
	{
		link->addItem((i + 10), i);
	}
	link->printItems();
	cout << " " << endl;
	link->deleteItem(5);
	link->printItems();

}

