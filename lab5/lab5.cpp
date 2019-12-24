#include <iostream>
#include "THash.h"

void    show_menu()
{
    cout << "====================================МЕНЮ====================================" << endl;
    cout << " 1. Вставить элемент" << endl
        << " 2. Вывод таблицы" << endl
        << " 3. Список индексов" << endl
        << " 4. Найти элемент по ключу" << endl
        << " 5. Удалить элемент по ключу" << endl
        << " 0. Выход" << endl;
    cout << "============================================================================" << endl;
    cout << "Ваш выбор: ";
}

void    insert(THash<string, string, string>*& hashTable)
{
    string name, num, model;

    cout << "Введите имя: "; cin >> name;
    cout << "Введите модель: "; cin >> model;
    cout << "Введите номер: "; cin >> num;
    hashTable->push(name, model, num);
}

void    find_element(THash<string, string, string>*& hashTable)
{
    string key;
    cout << "Введите ключ: "; cin >> key;
    hashTable->find(key);
}

void    del_element(THash<string, string, string>*& hashTable)
{
    string key;
    cout << "Введите ключ: "; cin >> key;
    hashTable->del(key);
}

int main()
{
    setlocale(LC_ALL, "RUS");
    THash<string, string, string>* hashTable = new THash<string, string, string>();
    int menu = 1;

    while (menu) {
        show_menu();
        cin >> menu;
        switch (menu)
        {
        case 1:
            insert(hashTable);
            break;
        case 2:
            hashTable->show();
            break;
        case 3:
            hashTable->show_ind();
            break;
        case 4:
            find_element(hashTable);
            break;
        case 5:
            del_element(hashTable);
            break;
        default:
            exit(0);
            break;
        }
    }
    return (0);
}
