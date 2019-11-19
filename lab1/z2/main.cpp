#include "class.h"

int	main(void)
{
	Tnode	node;
	unsigned	param;
	string		str;
	int c;
	int	f_m;

	c = 1;
	f_m = 1;
	// node = new Tnode(0, 0, 0, 0);
	while (c) {													
		if (f_m)  //Для того, чтобы меню выводилось 1 раз мы вводим условие
		{
			std::cout << "====================================МЕНЮ====================================" << endl;
			std::cout << " 1. Заполнить узел" << endl
				<< " 2. Вывести узел" << endl
				<< " 3. Добавить элемент" << endl
				<< " 4. Удалить элемент по заданному коду диагноза" << endl
				<< " 5. Переместить в новый список записи с номером Мед.Книжки" << endl
				<< " 6. Посчитать сколько раз обращались в определенную дату с определенным диагнозом" << endl
				<< " 0. Выхожд" << endl;
			std::cout << "============================================================================" << endl;
		}
		else
			std::cout << "Введите пункт меню: ";
		std::cin >> c;
		switch (c) {
			case 1:
				node.createnode();
				break;
			case 2:
				node.print_node();
				break;
			case 3:
				node.push_node();
				break;
			case 4:
				node.delete_by_code();
				break;
			case 5:
				Tnode	*tmp;
				tmp = tmp->move_to_new();
				tmp->print_node();
				break;
			case 6:
				node.count_codes();
				break;
			case 0:
				exit (1);
				break;
		}
	}
	return (0);
}