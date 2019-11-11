#pragma once
template <class T>
class node
{
private:
	T object;
	node * nextNode = nullptr;
	node * prevNode = nullptr;
public:

	T get();
	void set(T object);
	node *getNext();
	void setNext(node *nextNode);
	node *getPrev();
	void setPrev(node *prevNode);
};

