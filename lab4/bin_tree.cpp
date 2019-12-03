#include "bin_tree.h"
#include <iostream>
#include <queue>

using namespace std;

void Btree::show()
{
	Btree top = *this;
	if (!&top)
		return ;
	queue <Btree *> q;
	do
	{
		cout << top.data << " ";
		if (top.l)
			q.push(top.l);
		if (top.r)
			q.push(top.r);
		if (!q.empty())
		{
			top = *(q.front());
			q.pop();
			cout << endl;
		}
	} while (!q.empty());
}