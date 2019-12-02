#include <iostream>
#include <string>
#include <malloc.h>
#include "node.h"

using namespace std;

//Пример вызова функции head = del_nodes(head, NULL, info);
t_node				*del_nodes(t_node* node, t_node *prev, int info)
{
	if (!node)
		return (NULL);
	if (node->info == info)
	{
		t_node* tmp = node->next;
		delete node;
		return (del_nodes(tmp, prev, info));
	}
	else
		node->next = del_nodes(node->next, node, info);
	return (node);
}

//Пример вызова функции is_pal(s, 0, s.length() - 1);
int					is_pal(string s, size_t start, size_t end)
{
	if (start >= end)
		return (1);
	if (s[start] == s[end])
		return (is_pal(s, ++start, --end));
	else
		return (0);
}

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "=============Демонстрация первого задания============" << endl;
	string s;
	cout << "Введите какую-либо строку: ";
	cin >> s;
	int res = is_pal(s, 0, s.length() - 1);
	if (res)
		cout << "Данная строка - палиндром" << endl;
	else
		cout << "Данная строка не является палиндромом" << endl;
	cout << "=======================Конец=======================\n" << endl;
	cout << "=============Демонстрация второго задания============" << endl;
	t_node* head;
	int		info;
	head = creatennode();
	print_node(head);
	cout << "Введите информацию, по которой нужно удалить элементы: "; cin >> info;
	head = del_nodes(head, NULL, info);
	print_node(head);
	return (0);
}
