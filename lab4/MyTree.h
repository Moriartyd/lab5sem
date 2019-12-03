#pragma once

class MyTree
{
public:
	MyTree();
	MyTree(int nodes);
	MyTree(const MyTree &tree);
	~MyTree();
	int find_tree(int value);
	int	get_leaves();
	int get_height();
private:
	int nodes;
	int data;
	MyTree* l;
	MyTree* r;
};

MyTree::MyTree() :
	l(0), r(0), data(0)
{
}

MyTree::~MyTree()
{
}