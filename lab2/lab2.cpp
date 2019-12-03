// lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "AStack.cpp"
#include "NStack.cpp"
#include <string>
#include <stack>

using namespace std;

int is_num(char c)
{
	return (c >= '0' && c <= '9' ? 1 : 0);
}

int is_op(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

int prior(char c)
{
	switch (c)
	{
	case '+':
	case '-': return 1;
	case '*':
	case '%':
	case '/': return 2;
	}
	return (0);
}

template <class T>
string opn(string s, T *st)
{
	string	out;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (is_num(s[i]))
		{
			out += s[i];
			j++;
		}
		else if (s[i] != ' ')
		{
			if (j != 0 && is_num(out[j - 1]))
			{
				out += ' ';
				j++;
			}
			if (is_op(s[i]))
			{
				if (st->empty() || prior(st->top()) < prior(s[i]))
					st->push(s[i]);
				else
				{
					while (!st->empty() && (prior(st->top()) >= prior(s[i])))
					{
						out += st->top(); st->pop();
						j++;
					}
					st->push(s[i]);
				}
			}
		}
		i++;
	}
	while (!st->empty())
	{
		out += st->top(); st->pop();
	}
	out += '\0';
	return (out);
}
template <class T>
int	calculate(string s, T *st)
{
	int i;
	int l, r;
	char* endptr;

	endptr = NULL;
	i = 0;
	while (s[i])
	{
		while (s[i] == ' ')
			i++;
		if (is_num(s[i]))
		{
			int num = strtol(&s[i], &endptr, 10);
			st->push(num);
			i += endptr - &s[i];
		}
		else
		{
			if (is_op(s[i]))
			{
				r = st->top(); st->pop();
				l = st->top(); st->pop();
				switch (s[i])
				{
				case '+':
					st->push(l + r);
					break;
				case '-':
					st->push(l - r);
					break;
				case '*':
					st->push(l * r);
					break;
				case '/':
					st->push(l / r);
					break;
				case '%':
					st->push(l % r);
					break;
				}
			}
			i++;
		}
	}
	return (st->top());
}

int main()
{
	setlocale(LC_ALL, "RUS");
	int steck;
	AStack<char>* st1 = new AStack<char>();
	NStack<char>* st2 = new NStack<char>();
	stack<char>* st3 = new stack<char>;
	cout << "Какой стек вы хотите использовать?\
			\n1. На массиве\
			\n2. На односвязном списке\
			\n3. На встроенном контейнере" << endl;
	cin >> steck;
	string s;
	cout << "Введите выражение: ";
	getchar();
	getline(cin, s);
	string out;
	switch (steck)
	{
	case (1):
		out = opn(s, st1);
		break;
	case (2):
		out = opn(s, st2);
		break;
	case (3):
		out = opn(s, st3);
		break;
	default:
		cout << "Что-то пошло нетак" << endl;
		exit(-1);
		break;
	}
	cout << "Выражение в постфиксной форме: " << out << endl;
	AStack<int>* st4 = new AStack<int>();
	NStack<int>* st5 = new NStack<int>();
	stack <int>* st6 = new stack<int>;
	int res;
	switch (steck)
	{
	case (1):
		res = calculate(out, st4);
		break;
	case (2):
		res = calculate(out, st5);
		break;
	case (3):
		res = calculate(out, st6);
		break;
	}
	cout << "Результат выражения: " << res << endl;;
	return (0);
}
