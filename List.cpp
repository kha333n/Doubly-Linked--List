#include "List.h"

using namespace std;

template <class T>
List<T>::List() //Default constructor.
{
	headNode = new node<T>();  //Creates a new node and store its address in headNode.
	headNode->setNext(0);   //In the node created above stores the pointer value NULL or 0.
	currentNode = 0;   
	prevNode = 0;   //currentNode and PrevNode are also has NULL pointer.
	size = 0; //Size of list is 0.
}

template <class T>
void List<T>::add(T addObject)
{
	node<T> *newNode = new node<T>(); //To add a node in list first create new node.
	newNode->set(addObject);   //Insert the given value in the node.

	if (currentNode != 0)  //If the pointer currentNode is not NULL or list is not empty then.
	{
		newNode->setNext(currentNode->getNext());  //Insert the value of next node in the pointer of newNode.  So that it points to the next node if any in the list. 
		newNode->setPrev(currentNode);  //Points prevNode to the previous node.
		( currentNode->getNext() ) -> setPrev(newNode);   //Set nex nodes Prev pointer to the new node.
		currentNode->setNext(newNode);   //Point the current pointer to the newNode
		currentNode = newNode;  //Insert this new node in the currentNode
	}
	else  //if the list is empty and creating its first node.
	{
		newNode->setNext(0);  //There is no node after this node therefore next pointer of this node is NULL
		headNode->setNext(newNode);  //This is first node, therefore it is head of list.
		newNode->setPrev(0);	 //No node before this, therefore we also pointed lastCurrentNode to headNode.
		currentNode = newNode;  //CurrentNode pointer is also here.
	}
	size++;  //increase the size of the list.
}

template<class T>
T List<T>::get()
{
	// TODO: Add your implementation code here.
	if (currentNode != 0) //If currentNode is not at the last node in the list or list is not empty.
	{
		return currentNode->get();  //Return the value in the node where the currentNode pointer is.
	}
	return false; //Otherwise return false.

}

template <class T>
bool List<T>::next()
{
	// TODO: Add your implementation code here.
	if (currentNode == 0) //If currentNode is on the last node in the list.
	{
		return false;
	}
	currentNode = currentNode->getNext();  //Point the currentNode pointer to the next node in the list.
	if (currentNode == 0 || size == 0)  //If currentNode is on the last node or list is empty.
	{
		return false;
	}
	else
	{
		return true;  //When next command success. return true.
	}
}

template<class T>
bool List<T>::previous()
{
	if (currentNode == 0) //If currentNode is on the last node in the list.
	{
		return false;
	}
	currentNode = currentNode->getPrev();
	if (currentNode == 0 || size == 0)  //If currentNode is on the last node or list is empty.
	{
		return false;
	}
	else
	{
		return true;  //When next command success. return true.
	}
}

template <class T>
void List<T>::start() //Points the pointers to the start of the list.
{
	// TODO: Add your implementation code here.
	currentNode = headNode;
}

template <class T>
void List<T>::remove()
{
	// TODO: Add your implementation code here.
	if (currentNode != 0 && currentNode != headNode)  
	{
		( currentNode->getPrev() ) -> setNext( currentNode->getNext() );
		( currentNode ->getNext() ) -> setPrev( currentNode->getPrev() );
		currentNode = currentNode->getNext();
		delete currentNode; 
		size--;  //Decrease the size of list.
	}
}

template <class T>
int List<T>::length() const
{
	// TODO: Add your implementation code here.
	return size;    //returns the length of the list.
}