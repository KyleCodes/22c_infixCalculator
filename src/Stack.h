////////////////////////////////////////////
////////////////////////////////////////////
//            CLASS DEFINITIONS
////////////////////////////////////////////
////////////////////////////////////////////
////////////////////////////////////////////
//	STACK CLASS
////////////////////////////////////////////
// Stack.h
////////////////////////////////////////////

#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <string>
#include "Node.h"
using namespace std;


//CONTAINS THE STACK CLASS INHERITED FROM NODE.


template <class T>
class Stack : protected LinkedList<T>
{
public:
	Stack();
	~Stack(); // this destructor deletes everything from the stack
	void push(T);
	void pop();
	bool isStackEmpty();
	void Display();
	int peek();

};

template <class T>
Stack<T>::Stack()
{

}

template <class T>
Stack<T>::~Stack()
{
	Node *currPtr; // a curr pointer to move through the stack
	Node *nextNode;// a nextnode to have a value after the curr ptr is delete to keep deleting

	currPtr = head; // sets curr pointer to the top value

	while (currPtr != NULL)
	{
		nextNode = currPtr->next; //sets nextnode to the node after top
		delete currPtr; // deletes the current node
		currPtr = nextNode; // sets the current node to the node after it
	}
}


template <class T>
void Stack<T>::push(T input)
{
	this->insertFirst(input);
}

template <class T>
void Stack<T>::pop()
{
	this->removeFirst();
}
template <class T>

bool Stack<T>::isStackEmpty()
{
	bool status = this->isEmpty();
	return status;
}

template <class T>
void Stack<T>::Display()
{
	this->displayList();
}


template <class T>
int Stack<T>::peek()
{

	
	int temp;
	 temp = this->getTop();
	 return temp;
	

	/*Node *currPtr = this->top();
	return currPtr->data;*/
}

#endif
