#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#include "Queue.h"
#include <iostream>
using namespace std;

//-------------------- Node class ---------------//
class Node
{
public:
	Node(int data, Node* next, Node* previous)
	{
		this-> data = data;
		this->next = next;
		this->previous = previous;
	}

	int getData() const
	{
		return data;
	}

	void setData(int data)
	{
		this->data = data;
	}

	Node* getNext() const
	{
		return next;
	}
	
	void setNext(Node* next)
	{
		this->next = next;
	}

	Node* getPrevious() const
	{
		return previous;
	}

	void setPrevious(Node* previous)
	{
		this->previous = previous;
	}

private:
	int data;
	Node* next;
	Node* previous;
};

//--------------------Linked Queue ---------------//
class LinkedQueue
{
public:
	LinkedQueue()
	{
		front = nullptr;
		back = nullptr;
	}

	virtual ~LinkedQueue()
	{
		makeEmpty();
	}

	void enqueue(int newEntry)
	{
		Node* newNode = new Node(newEntry, back, nullptr);

		if (isEmpty())
		{
			front = newNode;
		}
		else
		{
			back->setNext(newNode);
		}

		back = newNode;
	}

	int dequeue()
	{
		int data = 0;

		if (!isEmpty())
		{
			Node* tempToRemove = front;
			data = front->getData();
			front = front->getNext();

			delete tempToRemove;

			if (front == nullptr)
			{
				back = nullptr;
			}
			else
			{
				front->setPrevious(nullptr);
			}
		}
		else
		{
			cout << "You cannot dequeue from an empty queue!" << endl;
		}

		return data;
	}

	int peekFront() const
	{
		int data = 0;

		if (!isEmpty())
		{
			data = front->getData();
		}
		else
		{
			cout << "You cannot peek the front of an empty queue!" << endl;
		}

		return data;
	}

	bool isEmpty() const
	{
		return front == back;
	}

	void makeEmpty()
	{
		while (!isEmpty())
		{
			dequeue();
		}
	}

private:
	Node* front;
	Node* back;
};
#endif
