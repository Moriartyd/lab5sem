#pragma once

#include <iostream>
using namespace std;

typedef struct		s_node
{
	int				info;
	struct s_node* next;
}					t_node;

t_node* node_init(void)
{
	t_node* res;

	if (!(res = new t_node))
		exit(-1);
	res->info = 0;
	res->next = NULL;
	return (res);
}

t_node* add_new(int info)
{
	t_node* res;

	if (!(res = new t_node))
		exit(-1);
	res->info = info;
	res->next = NULL;
	return (res);
}

t_node* creatennode(void)
{
	t_node* head;
	t_node* tmp;
	size_t  	i;
	size_t		n;
	int			info;

	std::cout << "Сколько элементов нужно создать: ";
	std::cin >> n;
	i = 0;
	head = NULL;
	tmp = NULL;
	while (++i <= n)
	{
		if (!head)
		{
			head = node_init();
			std::cout << "Для " << i << " элемента:\n";
			std::cout << "\tВведите информацию: ";
			std::cin >> info;
			head->info = info;
			tmp = head;
		}
		else
		{
			std::cout << "Для " << i << " элемента:\n";
			std::cout << "\tВведите информацию: ";
			std::cin >> info;
			tmp->next = add_new(info);
			tmp = tmp->next;
		}
	}
	return (head);
}

void	print_node(t_node* head)
{
	t_node* tmp;

	tmp = head;
	if (!head)
		cout << "Нет элементов" << endl;
	while (tmp)
	{
		cout << tmp->info;
		if (!tmp->next)
			cout << "\n";
		else
			cout << " ";
		tmp = tmp->next;
	}
}
