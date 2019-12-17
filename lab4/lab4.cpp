#include <iostream>
#include "MyTree.h"

void    show_menu()
{
    std::cout << "====================================МЕНЮ====================================" << endl;
    std::cout << " 1. Создать дерево из n узлов" << endl
        << " 2. Вывести дерево" << endl
        << " 3. Добавить элемент" << endl
        << " 4. Узнать длину пути от корня до определенного узла" << endl
        << " 5. Узнать число листьев" << endl
        << " 6. Узнать высоту дерева" << endl
        << " 0. Выход" << endl;
    std::cout << "============================================================================" << endl;
    std::cout << "Ваш выбор: ";
}

MyTree* create()
{
    int n;
    cout << "Сколько узлов вы хотите создать: "; cin >> n;
    MyTree* res = new MyTree(n);
    cout << "Узел создан" << endl;
    return (res);
}

MyTree* add(MyTree *&tree)
{
    string value;
    getchar();
    cout << "Введите значение, которое хотите добавить: ";
    getline(cin, value);
    tree = tree->insert(value);
    cout << "Элемент добавлен" << endl;
    return (tree);
}

void get_long(MyTree tree)
{
    string value;
    getchar();
    cout << "Введите значение узла, для которого хотите узнать длину пути: ";
    getline(cin, value);
    cout << "Длина пути: " << tree.find_tree(value) << endl;
}

void get_leaves(MyTree tree)
{
    cout << "Число листьев у дерева: " << tree.get_leaves() << endl;
}

void get_height(MyTree tree)
{
    cout << "Высота дерева: " << tree.rh() << endl;
}

int main()
{
    setlocale(LC_ALL, "RUS");
    int menu = 1;
    MyTree* tree = 0;
    while (menu) {
        show_menu();
        cin >> menu;
        switch (menu)
        {
            case 1:
                tree = create();
                break;
            case 2:
                tree->show(tree->rh());
                break;
            case 3:
                tree = add(tree);
                break;
            case 4:
                get_long(*tree);
                break;
            case 5:
                get_leaves(*tree);
                break;
            case 6:
                get_height(*tree);
                break;
        default:
            exit(0);
            break;
        }
    }
    return (0);
}
