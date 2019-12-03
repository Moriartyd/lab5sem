#include "AStack.h"
#include <malloc.h>
#include <iostream>

template<typename T>
AStack<T>::AStack()
{
	elements = 0;
	arr = (T*)malloc(sizeof(T) * elements);
}

template<typename T>
AStack<T>::~AStack()
{
	cout << "this is dest" << endl;
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
