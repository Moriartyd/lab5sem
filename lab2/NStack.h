#pragma once
#ifndef NSTACK_H
#define NSTACK_H

template <typename T>
class			Node
{
public:
				Node();
				~Node();
	void		set_data(T d);
	void		set_next(Node<T>* n);
	T			get_data();
	Node<T>*	get_next();
private:
	Node*		next;
	T			data;
};

template <typename T>
class			NStack
{
public:
				NStack();
				~NStack();
	bool		empty();
	void		push(T el);
	T			top();
	void		pop();
	T			poll();
private:
	Node<T>*	node;
	int			elements;
};

#endif