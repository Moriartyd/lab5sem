#include "class.h"

unsigned	Tnode::get_id()
{
	return (this->id);
}

std::string	Tnode::get_date()
{
	return (this->date);
}

unsigned	Tnode::get_code()
{
	return (this->code);
}

Tnode*	Tnode::get_next()
{
	return (this->next);
}

Tnode::Tnode(unsigned i, std::string d, unsigned c, Tnode *n)
{
	id = i;
	this->date = d;
	this->code = c;
	this->next = n;
}

void	Tnode::move_data(Tnode *n)
{
	unsigned id;
	std::string date;
	unsigned code;
	Tnode	*tmp;

	id = this->id;
	date = this->date;
	code = this->code;
	tmp = this->next;
	
	this->id = n->get_id();
	this->date = n->get_date();
	this->code = n->get_code();
	this->next = n->get_next();
	delete n;
	n = new Tnode(id, date, code, tmp);
}

void	Tnode::push_node()
{
	unsigned	id;
	Tnode		*res;
	Tnode		*tmp;

	std::cout << "Введите номер Мед.Книжки (или просто введите '0'): ";
	std::cin >> id;
	res = new Tnode(id, NULL, 0, NULL);
	if (id)
	{
		res->next = this;
		move_data(res);
	}
	else
	{
		tmp = this;
		while (tmp->get_next())
			tmp = tmp->get_next();
		tmp->next = res;
		res->next = NULL;
	}
}

void	Tnode::delete_by_code()
{
	Tnode		*cur;
	Tnode		*prev;
	unsigned	code;

	std::cout << "\nВведите код обращения: "; std::cin >> code;
	cur = this;
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
				move_data(this->next);
				delete cur;
				cur = this;
			}
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}


Tnode*		Tnode::move_to_new()
{
	Tnode		*node;
    Tnode		*res;
    Tnode		*tmp;
    Tnode		*res_head;
    Tnode		*res_tmp;
	unsigned	code;

	std::cout << "\nВведите Номер мед карты";
	std::cin >> code;
    node = this;
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

void	 Tnode::count_codes()
{
	Tnode		*tmp;
	unsigned	counter;
	unsigned	code;
	std::string	data;

	counter = 0;
	std::cout << "\nВведите код обращения: "; std::cin >> code;
	std::cout << "Введите дату: "; std::cin >> data;
	tmp = this;
	while (tmp)
	{
		if (tmp->code == code && tmp->date == data)
			counter++;
		tmp = tmp->next;
	}
	std::cout << "Количество обращений: " << counter << std::endl;
}

void	Tnode::print_node()
{
	Tnode		*tmp;
	unsigned	i;

	i = 0;
	tmp = this;
	if (!tmp)
		std::cout << "Вы не заполнили список" << endl;
	while (tmp)
	{
		cout << "Запись №" << i << ": " << endl;
		cout << "\tНомер Мед.Книжки: " << tmp->id << endl;
		cout << "\tДата обращения: " << tmp->date << endl;
		cout << "\tКод диагноза: " << tmp->code << endl;
		if (!tmp->next)
			cout << "\n";
		tmp = tmp->get_next();
		i++;
    }
}

Tnode  *node_init(void)
{
	Tnode  *res;

	if (!(res = new Tnode(0, NULL, 0, NULL)))
		exit (-1);
	return (res);
}

Tnode  *add_new(unsigned id, string date, unsigned code)
{
	Tnode *res;

	if (!(res = (new Tnode(id, date, code, NULL))))
		exit (-1);
	return (res);
}

void	Tnode::createnode(void)
{
	Tnode  		*tmp;
	size_t  	i;
	size_t		n;
	unsigned	id;
	std::string	date;
	unsigned	code;

	std::cout << "Сколько элементов нужно создать: ";
	std::cin >> n;
	i = 0;
	while (++i <= n)
	{
		if (!i)
		{
			std::cout << "Для " << i << " элемента:\n";
			std::cout << "\tВведите номер Мед.Книжки: ";
			std::cin >> id;
			std::cout << "\tВведите дату: ";
			std::cin >> date;
			std::cout << "\tВведите код диагноза: ";
			std::cin >> code;
			this->id = id;
			this->date = date;
			this->code = code;
			tmp = this;
		}
		else
		{
			std::cout << "Для " << i << " элемента:\n";
			std::cout << "\tВведите номер Мед.Книжки: ";
			std::cin >> id;
			std::cout << "\tВведите дату: ";
			std::cin >> date;
			std::cout << "\tВведите код диагноза: ";
			std::cin >> code;
			tmp->next = add_new(id, date, code);
			tmp = tmp->next;
		}
	}
}
