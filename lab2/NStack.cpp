#include "NStack.h"
#include <stdlib.h>

template<typename T>
Node<T>::Node()
{
}

template<typename T>
Node<T>::~Node()
{
}

template<typename T>
void Node<T>::set_data(T d)
{
	data = d;
}

template<typename T>
void Node<T>::set_next(Node<T>* n)
{
	next = n;
}

template<typename T>
T Node<T>::get_data()
{
	return T(this->data);
}

template<typename T>
Node<T>* Node<T>::get_next()
{
	return (next);
}

template<typename T>
NStack<T>::NStack() :
	node(0), elements(0)
{
}

template<typename T>
NStack<T>::~NStack()
{
	Node<T>* tmp = node;
	while (tmp)
	{
		node = tmp;
		tmp = node->get_next();
		delete node;
	}
}

template<typename T>
bool NStack<T>::empty()
{
	return (this->elements ? false : true);
}

template<typename T>
void NStack<T>::push(T el)
{
	Node<T>* new_node = new Node<T>();
	new_node = (Node<T>*)malloc(sizeof(Node<T>));
	new_node->set_data(el);
	new_node->set_next(this->node);
	this->node = new_node;
	this->elements++;
}

template<typename T>
T NStack<T>::top()
{
	return this->node->get_data();
}

template<typename T>
void NStack<T>::pop()
{
	this->elements--;
	Node<T>* tmp = this->node->get_next();
	delete this->node;
	this->node = tmp;
}

template<typename T>
T NStack<T>::poll()
{
	T tmp;
	tmp = this->top();
	this->pop();
	return tmp;
}
