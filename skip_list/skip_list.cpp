#include<iostream>
#include <cstdlib>
#include"../skip_list/skip_list.h"
using namespace std;


int main() {
    setlocale(LC_ALL, "rus");
    SkipList<int> sl(20, 0.5); 
    int choice;
    int value;

    do {
        system("cls");
        cout << "Выберите действие:" << endl;
        cout << "1. Вставить элемент" << endl;
        cout << "2. Удалить элемент" << endl;
        cout << "3. Проверить, содержится ли элемент" << endl;
        cout << "4. Вывести список" << endl;
        cout << "0. Выйти" << endl;
        cout << "Ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введите значение элемента для вставки: ";
            cin >> value;
            sl.insert(value);
            cout << "Элемент добавлен в список." << endl;
            system("pause");
            break;
        case 2:
            cout << "Введите значение элемента для удаления: ";
            cin >> value;
            sl.remove(value);
            cout << "Элемент удален из списка." << endl;
            system("pause");
            break;
        case 3:
            cout << "Введите значение элемента для поиска: ";
            cin >> value;
            if (sl.search(value)) {
                cout << "Элемент найден в списке." << endl;
            }
            else {
                cout << "Элемент не найден в списке." << endl;
            }
            system("pause");
            break;
        case 4:
            cout << "Содержимое списка:" << endl;
            sl.printList();
            system("pause");
            break;
        case 0:
            cout << "Выход." << endl;
            break;
        default:
            cout << "Неверный ввод. Попробуйте еще раз." << endl;
            system("pause");
        }

    } while (choice != 0);

    return 0;
}