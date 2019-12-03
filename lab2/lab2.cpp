// lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "AStack.cpp"
//#include "NStack.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	AStack<int> *st = new AStack<int>();
	int	elements;
	int i;
	int data;

	std::cout << "Сколько элементов вы хотите добавить в стек: "; std::cin >> elements;
	i = 0;
	while (i < elements)
	{
		std::cout << "Введите " << i + 1 << " элемент: ";
		std::cin >> data;
		st->push(data);
	}
	delete &st;
	return (0);
}
