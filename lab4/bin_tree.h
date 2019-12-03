#pragma once

class Btree
{
public:
	Btree();
	~Btree();
	void	show();
private:
	Btree*	l; //Left
	Btree*	r; //Right
	int		data;
};

Btree::Btree() :
	l(0), r(0), data(0)
{
}

Btree::~Btree()
{
}



