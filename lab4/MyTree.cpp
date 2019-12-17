#include "MyTree.h"

using namespace std;

MyTree::MyTree(int nodes)
{
	int i = nodes;
	MyTree* tree = this;
	MyTree* tmp;
	string value;
	getchar();
	while (i)
	{
		tmp = tree;
		cout << "Введите " << nodes - i + 1 << "ое значение: ";
		getline(cin, value);
		if (i == nodes)
			tree->data = value;
		else
			tree = insert(value);
		if (tree != tmp)
		{
			cout << "При заданных значениях создать дерево невозможно!" << endl;
			exit(0);
		}
		i--;
	}
}

MyTree::MyTree(const MyTree& tree) :
	l(tree.l), r(tree.r), data(tree.data), height(tree.height)
{
}

MyTree::MyTree(string value) : 
	l(0), r(0), data(value), height(0)
{
}

MyTree::MyTree() :
	l(0), r(0), data(0), height(0)
{
}

MyTree::~MyTree()
{
}

int MyTree::find_tree(string value)
{
	MyTree *tree;
	int i = 0;
	tree = this;
	while (tree)
	{
		if (value < tree->data)
		{
			tree = tree->l;
			i++;
		}
		else if (value > tree->data)
		{
			tree = tree->r;
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
	while (1)
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
			continue;
		}
		if (q.empty())
			break;
	}
	return (i);
}

int MyTree::rh()
{
	return this ? height : 0;
}

int MyTree::get_bfactor()
{
	return (r->rh() - l->rh());
}

void MyTree::fix_height()
{
	height = l->rh() > r->rh() ? l->rh() + 1 : r->rh() + 1;
}

void MyTree::show(int lvl)
{
	if (this)
	{
		for (int i = 0; i < lvl; i++)
			cout << "\t";
		cout << data << endl;
		this->l->show(lvl - 1);
		r->show(lvl + 1);
		//r->show(lvl + 1);
		//for (int i = 0; i < lvl; i++)
		//	cout << "\t";
		//cout << data << endl;
		//l->show(lvl + 1);
	}
}

MyTree* MyTree::rot_left()
{
	MyTree* tmp = r;
	r = tmp->l;
	tmp->l = this;
	this->fix_height();
	tmp->fix_height();
	return tmp;
}

MyTree* MyTree::rot_right()
{
	MyTree* tmp = l;
	l = tmp->r;
	tmp->r = this;
	this->fix_height();
	tmp->fix_height();
	return tmp;
}

MyTree* MyTree::balance()
{
	this->fix_height();
	if (this->get_bfactor() == B)
	{
		if (r->get_bfactor() < 0)
			r = r->rot_right();
		return (this->rot_left());
	}
	if (this->get_bfactor() == -B)
	{
		if (l->get_bfactor() > 0)
			l = l->rot_left();
		return (this->rot_right());
	}
	return this;
}

MyTree* MyTree::insert(string value)
{
	if (value > data && r)
		r = r->insert(value);
	else if (value > data && !r)
		r = new MyTree(value);
	else if (value < data && l)
		l = l->insert(value);
	else
		l = new MyTree(value);
	height++;
	return balance();
}
