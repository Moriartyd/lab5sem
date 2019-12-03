#include "MyTree.h"
#include <queue>
#include <iostream>

using namespace std;

MyTree::MyTree(int nodes) :
	nodes(nodes), l(NULL), r(NULL), data(0)
{
}

MyTree::MyTree(const MyTree& tree) :
	l(tree.l), r(tree.r), data(tree.data)
{
}

int MyTree::find_tree(int value)
{
	MyTree tree;
	int i = 0;
	tree = *this;
	while (&tree)
	{
		if (value < tree.data)
		{
			tree = *(tree.l);
			i++;
		}
		else if (value > tree.data)
		{
			tree = *(tree.r);
			i++;
		}
		else
			return (i);
	}
	return (0);
}

int MyTree::get_leaves()
{
	int i = 0;
	MyTree top = *this;
	if (!&top)
		return (0);
	queue <MyTree*> q;
	do
	{
		if (!top.l && !top.r)
			i++;
		if (top.l)
			q.push(top.l);
		if (top.r)
			q.push(top.r);
		if (!q.empty())
		{
			top = *(q.front());
			q.pop();
		}
	} while (!q.empty());
	return (i);
}

int MyTree::get_height()
{
	MyTree tree = *this;
	int h1 = 0;
	int h2 = 0;
	if (!&tree)
		return (0);
	if (tree.l)
		h1 = tree.l->get_leaves();
	if (tree.r)
		h2 = tree.r->get_leaves();
	return (h1 > h2 ? h1 + 1 : h2 + 1);
}
