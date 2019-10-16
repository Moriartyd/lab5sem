#include "lab1.h"

void	push_node(t_node *head)
{
	t_node		*res;
	t_node		*tmp;
	unsigned	id;

	std::cout << "Введите номер Мед.Книжки (или просто введите '0'): ";
	std::cin >> id;
	res = new t_node;
	res->id = id;
	if (id)
	{
		res->next = head;
		head = res;
	}
	else
	{
		tmp = head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = res;
		res->next = NULL;
	}
}

void	delete_by_code(t_node *head)
{
	t_node		*cur;
	t_node		*prev;
	unsigned	code;

	std::cout << "\nВведите код обращения: "; std::cin >> code;
	cur = head;
	prev = NULL;
	while (cur)
	{
		if (cur->code == code)
		{
			if (prev)
			{
				prev->next = cur->next;
				delete cur;
				cur = prev->next;
			}
			else
			{
				head = head->next;
				delete cur;
				cur = head;
			}
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}

t_node	*move_to_new(t_node *head)
{
	t_node		*node;
    t_node		*res;
    t_node		*tmp;
    t_node		*res_head;
    t_node		*res_tmp;
	unsigned	code;

	std::cout << "\nВведите Номер мед карты";
	std::cin >> code;
    node = head;
    tmp = 0;
    res = 0;
    res_head = 0;
    res_tmp = 0;
    while (node)
    {
        if (node->code == code)
        {
            if (tmp)
                tmp->next = node->next;
            res = node;
            res->next = 0;
            if (!res_head)
            {
                res_head = res;
                res_tmp = res_head;
            }
            else
            {
                while (res_tmp->next)
                    res_tmp = res_tmp->next;
                res_tmp->next = res;
            }
        }
        tmp = node;
        node = node->next;
    }
    return (res_head);
}

void	 count_codes(t_node *head)
{
	t_node		*tmp;
	unsigned	counter;
	unsigned	code;
	std::string	data;

	counter = 0;
	std::cout << "\nВведите код обращения: "; std::cin >> code;
	std::cout << "Введите дату: "; std::cin >> data;
	tmp = head;
	while (tmp)
	{
		if (tmp->code == code && tmp->date == data)
			counter++;
		tmp = tmp->next;
	}
	std::cout << "Количество обращений: " << counter << std::endl;
}
