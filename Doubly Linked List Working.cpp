// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

template <class T>
class node
{
private:
	T object;
	node * nextNode;
	node * prevNode;
public:

	T get();
	void set(T object);
	node *getNext();
	void setNext(node *nextNode);
	node *getPrev();
	void setPrev(node *prevNode);
};

template<class T>
inline T node<T>::get()
{
return object;
}

template<class T>
void node<T>::set(T object)
{
	this -> object = object;
}

template<class T>
node<T>* node<T>::getNext()
{
	return nextNode;
}

template<class T>
void node<T>::setNext(node* nextNode)
{
	this -> nextNode = nextNode;
}

template<class T>
node<T>* node<T>::getPrev()
{
	return prevNode;
}

template<class T>
void node<T>::setPrev(node* prevNode)
{
	this -> prevNode = prevNode;
}

template <class T>
class List
{
private:
	node<T> *headNode;
	node<T> *currentNode;
	int size;
public:
	List<T>();
	void add(T addObject);
	T get();
	bool next();
	bool previous();
	void start();
	void remove();
	int length() const;
};


template <class T>
List<T>::List() //Default constructor.
{
	headNode = new node<T>();  //Creates a new node and store its address in headNode.
	headNode->setNext(0);   //In the node created above stores the pointer value NULL or 0.
	currentNode = 0;   
	size = 0; //Size of list is 0.
}

template <class T>
void List<T>::add(T addObject)
{
	node<T> *newNode = new node<T>(); //To add a node in list first create new node.
	newNode->set(addObject);   //Insert the given value in the node.

	if (currentNode != NULL)  //If the pointer currentNode is not NULL or list is not empty then.
	{
		newNode->setNext(currentNode->getNext());  //Insert the value of next node in the pointer of newNode.  So that it points to the next node if any in the list. 
		newNode->setPrev(currentNode);  //Points prevNode to the previous node.
		
		if ( currentNode->getNext() != NULL)
		{
			 ( currentNode->getNext() ) -> setPrev(newNode);   //Set nex nodes Prev pointer to the new node.
		}
		currentNode->setNext(newNode);  //Point the current pointer to the newNode
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
	if (currentNode != NULL) //If currentNode is not at the last node in the list or list is not empty.
	{
		return currentNode->get();  //Return the value in the node where the currentNode pointer is.
	}
	return false; //Otherwise return false.

}

template <class T>
bool List<T>::next()
{
	// TODO: Add your implementation code here.
	if (currentNode == NULL) //If currentNode is on the last node in the list.
	{
		return false;
	}
	node<T> *temp = currentNode;
	currentNode = currentNode->getNext();  //Point the currentNode pointer to the next node in the list.
	if (currentNode == NULL || size == 0)  //If currentNode is on the last node or list is empty.
	{
		currentNode = temp;
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
	if (currentNode == NULL) //If currentNode is on the last node in the list.
	{
		return false;
	}
	currentNode = currentNode->getPrev();
	if (currentNode == NULL || size == 0)  //If currentNode is on the last node or list is empty.
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
	if (currentNode != NULL && currentNode != headNode)  
	{
		( currentNode->getPrev() ) -> setNext( currentNode->getNext() );
		( currentNode ->getNext() ) -> setPrev( currentNode->getPrev() );
		node<T> *temp = currentNode->getNext();
		delete currentNode;
		currentNode = temp; 
		size--;  //Decrease the size of list.
	}
}

template <class T>
int List<T>::length() const
{
	// TODO: Add your implementation code here.
	return size;    //returns the length of the list.
}


int main()
{
	List<int> l1;
	l1.add(5);
	l1.add(6);
	l1.add(7);
	l1.previous();
	l1.remove();
	l1.add(8);
	l1.add(45);
	l1.add(34);
	l1.add(233);
	l1.start();
	while (l1.next())
	{
		cout << l1.get() << endl;
	}
	cout << "Prev" << endl;
	while (l1.previous())
	{
		cout << l1.get() << endl;
	}
	cout << "Size: " << l1.length() << endl;
	return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
