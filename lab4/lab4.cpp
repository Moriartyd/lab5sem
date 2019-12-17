#include <iostream>
#include "MyTree.h"

int main()
{
    setlocale(LC_ALL, "RUS");
    int n;
    cin >> n;
    MyTree* tree = new MyTree(n);
    tree->show(0);
    return (0);
}
