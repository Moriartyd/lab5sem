#pragma once
#ifndef MYTREE_H
#define MYTREE_H
#include <string>
#include <queue>
#include <iostream>
using namespace std;

#define B 12

class MyTree
{
public:
	MyTree();
	MyTree(int nodes);
	MyTree(const MyTree &tree);
	MyTree(string value);
	~MyTree();
	int find_tree(string value);
	int	get_leaves();
	int get_height();
	int rh();
	int get_bfactor();
	void fix_height();
	void show(int lvl);
	MyTree* rot_left();
	MyTree* rot_right();
	MyTree*	balance();
	MyTree*	insert(string value);
private:
	int height;
	string data;
	MyTree* l;
	MyTree* r;
};

#endif