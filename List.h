#pragma once
#include "node.h"

template <class T>
class List
{
private:
	node<T> *headNode;
	node<T> *currentNode;
	node<T> *prevNode;
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

