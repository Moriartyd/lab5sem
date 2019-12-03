#include "AStack.h"
#include <malloc.h>
#include <iostream>

template<typename T>
AStack<T>::AStack()
{
	elements = 0;
	arr = 0;
}

template<typename T>
AStack<T>::~AStack()
{
}

template<typename T>
bool AStack<T>::empty()
{
	return (this->elements ? false : true);
}

template<typename T>
void AStack<T>::push(T el)
{
	this->elements++;
	if (elements == 1)
		this->arr = (T*)malloc(sizeof(T));
	else
		this->arr = (T*)realloc(this->arr, sizeof(T) * this->elements);
	this->arr[this->elements - 1] = el;
}

template<typename T>
T AStack<T>::top()
{
	return T(this->arr[this->elements - 1]);
}

template<typename T>
void AStack<T>::pop()
{
	this->elements--;
	if (!elements)
	{
		free(this->arr);
		this->arr = NULL;
	}
	else
		this->arr = (T*)realloc(this->arr, sizeof(T) * (this->elements));
}

template<typename T>
T AStack<T>::poll()
{
	T tmp;
	tmp = this->top();
	this->pop();
	return T(tmp);
}
