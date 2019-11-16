
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

