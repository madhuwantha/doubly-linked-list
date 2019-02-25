#include "pch.h"
#include "Link.h"


Link::Link()
{
	head = tail = NULL;
	size = 0;
}

void Link::addItem(int v, int pos)
{
	if (pos > size || pos < 0)
	{
		cout << "positionnot valid" << endl;
		return;
	}
	else
	{
		if (head == NULL || pos == 0)
		{
			addToFirst(v);
		}
		else if (pos == size)
		{
			addToLast(v);
		}
		else
		{
			Node* current = new Node;
			current = head;
			for (int i = 0; i < pos; i++)
			{
				current = current->next;
			}
			Node* temp = new Node;
			temp->key = v;
			temp->next = current->next;
			temp->prev = current;
			current->next->prev = temp;
			current->next = temp;
			size++;

		}

	}

}

void Link::addToFirst(int v)
{
	Node* temp = new Node;
	temp->key = v;

	
	if (head == NULL)
	{
		head = temp;
		tail = temp;
		temp->next  = NULL;
	}
	else
	{
		head->prev = temp;
		head = temp;
	}
	temp->prev = NULL;
	size++;
}

void Link::addToLast(int v)
{
	if (head == NULL)
	{
		addToFirst(v);
	}
	else
	{
		Node* temp = new Node;
		temp->key = v;
		tail->next = temp;
		temp->prev = tail;
		temp->next = NULL;
		tail = temp;
		size++;

	}
}

void Link::deleteItem(int pos)
{
	if (pos >= size || pos < 0)
	{
		cout << " position is not valid" << endl;
		return;
	}
	else
	{
		if (pos == 0)
		{
			deleteFirst();
		}
		else if (pos == size - 1)
		{
			deleteLast();
		}
		else
		{
			Node* current = new Node;
			current = head;
			Node* temp = new Node;
			for (int i = 1; i < pos; i++)
			{
				current = current->next;
			}
			temp = current->next;
			current->next = current->next->next;
			current->next->next->prev = current;
			delete temp;
			size--;

		}
	}
}

void Link::deleteFirst()
{
	if (head != NULL)
	{
		Node*  temp = new Node;
		temp = head;
		head = head->next;
		head->next->prev = NULL;
		delete temp;
		size--;
	}
}

void Link::deleteLast()
{
	tail = tail->prev;
	tail->next->prev = NULL;
	delete tail->next;
	tail->next = NULL;
	size--;
}

void Link::printItems()
{
	Node* current;
	current = head;
	while (current != NULL)    // traversal 
	{
		cout << current->key << " ";
		current = current->next;
	}
}




Link::~Link()
{
}
