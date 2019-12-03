#include "NStack.h"

template<typename T>
inline Node<T>::Node()
{
}

template<typename T>
inline Node<T>::~Node()
{
}




template<typename T>
NStack<T>::NStack() :
	elements(0), node(0)
{
}

template<typename T>
NStack<T>::~NStack()
{
}

template<typename T>
bool NStack<T>::empty()
{
	return (this->elements ? false : true);
}

template<typename T>
void NStack<T>::push(T el)
{
	Node* new_node = new Node();
	new_node = (Node*)malloc(sizeof(struct s_node));
	new_node->data = el;
	new_node->next = this->node;
	this->node = new_node;
	this->elements++;
}

template<typename T>
T NStack<T>::top()
{
	return this->node->data;
}

template<typename T>
void NStack<T>::pop()
{
	this->elements--;
	struct s_node* tmp = this->node->next;
	free(this->node);
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
