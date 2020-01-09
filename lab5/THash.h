#include <string>
#include <iostream>

using namespace std;

int	ft_atoi(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	return (0);
}

template <typename TValue1, typename TValue2, typename TKey>
class THash
{
	template <typename Value1, typename Value2, typename Key>
	struct Owner
	{
		Owner(Value1 n=0, Value2 m=0, Key nu=0, Owner* nex=0) :name(n), model(m), num(nu), next(nex) {}

		Value1 name;
		Value2 model;
		Key	   num;
		Owner* next;
	};

	int						HashFunc(TKey key)
	{
		int hash;
		unsigned i = 0;

		hash = 0;
		while (i < key.length())
		{
			hash += ft_atoi(key[i]);
			i++;
		}
		hash = hash % cnt;
		return (hash);
	}
	int cnt = 3;
	int size = 0;
	Owner<TValue1, TValue2, TKey>** table;
public:
	THash();
	void push(TValue1 n, TValue2 m, TKey nu);
	void show();
	void find(TKey key);
	void del(TKey key);
	void show_ind();
	void reHash();
	~THash();
};

template<typename TValue1, typename TValue2, typename TKey>
inline THash<TValue1, TValue2, TKey>::THash()
{
	if (!(table = new Owner<TValue1, TValue2, TKey> * [cnt]))
		exit(-1);
	int i = 0;
	while (i < cnt)
	{
		table[i] = 0;
		i++;
	}
}

template<typename TValue1, typename TValue2, typename TKey>
inline void THash<TValue1, TValue2, TKey>::push(TValue1 n, TValue2 m, TKey nu)
{
	if (size && double(size) / cnt > 0.75)
		this->reHash();

	int index = HashFunc(nu);
	Owner<TValue1, TValue2, TKey>* el = new Owner<TValue1, TValue2, TKey>(n, m, nu);
	size++;
	if (!table[index])
	{
		table[index] = el;
		table[index]->next = 0;
		return;
	}
	Owner<TValue1, TValue2, TKey>* tmp = table[index];
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = el;
	el->next = 0;
}

template<typename TValue1, typename TValue2, typename TKey>
void THash<TValue1, TValue2, TKey>::show()
{
	Owner<TValue1, TValue2, TKey>* tmp;
	int j;
	for (int i = 0; i<cnt;i++)
	{
		if (table[i])
		{
			j = 0;
			cout << "Элемент №" << i << ":" << endl;
			tmp = table[i];
			while (tmp)
			{
				if (j > 0)
					cout << "Элемент №" << i <<"/" << j << ":" << endl;
				cout << "\tИмя: " << tmp->name << endl;
				cout << "\tМарка: " << tmp->model << endl;
				cout << "\tНомер: " << tmp->num << endl;
				tmp = tmp->next;
				j++;
			}
		}
	}
}

template<typename TValue1, typename TValue2, typename TKey>
inline void THash<TValue1, TValue2, TKey>::find(TKey key)
{
	Owner<TValue1, TValue2, TKey>*	tmp;
	int								index;

	index = HashFunc(key);
	tmp = table[index];
	if (!tmp)
		cout << "Элемент не найден :(" << endl;
	else
	{
		while (tmp && tmp->num != key)
			tmp = tmp->next;
		if (tmp)
		{
			cout << "Владелец автомобиля:" << endl;
			cout << "\tИмя: " << tmp->name << endl;
			cout << "\tМарка: " << tmp->model << endl;
			cout << "\tНомер: " << tmp->num << endl;
		}
		else
			cout << "Элемент не найден :(" << endl;
	}
}

template<typename TValue1, typename TValue2, typename TKey>
inline void THash<TValue1, TValue2, TKey>::del(TKey key)
{
	Owner<TValue1, TValue2, TKey>* tmp;
	Owner<TValue1, TValue2, TKey>* prev;

	int ind;

	ind = HashFunc(key);
	tmp = table[ind];
	prev = 0;
	while (tmp && tmp->num != key)
	{
		prev = tmp;
		tmp = tmp->next;
		size--;
	}
	if (tmp && tmp == table[ind])
	{
		table[ind] = table[ind]->next;
		delete tmp;
		size--;
	}
	else if (tmp && !tmp->next)
	{
		prev ? prev->next = 0 : 0;
		delete tmp;
		size--;
	}
	else if (tmp)
	{
		prev ? prev = tmp->next : 0;
		delete tmp;
	}
	else
		cout << "Элемент не найден :(" << endl;
	tmp = 0;
}

template<typename TValue1, typename TValue2, typename TKey>
inline void THash<TValue1, TValue2, TKey>::show_ind()
{
	Owner<TValue1, TValue2, TKey>* tmp;
	int i;
	int j;

	i = 0;
	while (i < cnt)
	{
		if (table[i])
		{
			cout << i;
			j = 0;
			tmp = table[i];
			while (tmp)
			{
				j++;
				tmp = tmp->next;
			}
			if (j > 1)
				cout << "/" << j << "\t";
		}
		i++;
	}
	cout << endl;
}

template<typename TValue1, typename TValue2, typename TKey>
void THash<TValue1, TValue2, TKey>::reHash()
{
	Owner<TValue1, TValue2, TKey>** new_table;
	Owner<TValue1, TValue2, TKey>* tmp;
	TKey	code;
	TValue1 name;
	TValue2 model;
	int index;

	new_table = new Owner<TValue1, TValue2, TKey> * [cnt*2];
	for (int i = 0; i < cnt*2; i++)
		new_table[i] = 0;
	cnt *= 2;
	for (int i = 0; i < cnt / 2; i++)
	{
		while (table[i])
		{
			name = table[i]->name;
			model = table[i]->model;
			code = table[i]->num;
			index = HashFunc(code);
			Owner<TValue1, TValue2, TKey>* new_element = new Owner<TValue1, TValue2, TKey>(name, model, code, 0);
			Owner<TValue1, TValue2, TKey>* place = new_table[index];
			if (!place)
			{
				new_table[index] = new_element;
				new_element->next = 0;
				size++;
			}
			else
			{
				while (place->next)
					place = place->next;
				place->next = new_element;
			}
			table[i] = table[i]->next;
		}
	}
	Owner<TValue1, TValue2, TKey> **temp = 0;
	temp = table;
	table = new_table;
	for (int i = 0; i < cnt/2; i++)
		delete[] temp[i];
	delete[] temp;
}

template<typename TValue1, typename TValue2, typename TKey>
inline THash<TValue1, TValue2, TKey>::~THash()
{
	for (int i = 0; i < cnt; i++)
		delete[] table[i];
	delete[] table;
}
