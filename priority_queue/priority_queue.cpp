#include <iostream>
#include <cstdlib>
#include "..//priority_queue/priority_queue.h"  

using namespace std;


int main() {
    setlocale(LC_ALL, "rus");
    PriorityQueue<int> pq;
    int choice;
    int priority, value;

    do {
        system("cls");
        cout << "Выберите действие:" << endl;
        cout << "1. Вставить элемент" << endl;
        cout << "2. Извлечь элемент" << endl;
        cout << "3. Проверить, пуста ли очередь" << endl;
        cout << "4. Вывести очередь" << endl;
        cout << "0. Выйти" << endl;
        cout << "Ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введите приоритет и значение элемента: ";
            cin >> priority >> value;
            pq.insert(priority, value);
            cout << "Элемент добавлен в очередь." << endl;
            system("pause");
            break;
        case 2:
            if (!pq.isEmpty()) {
                cout << "Извлеченный элемент: " << pq.pop() << endl;
                system("pause");
            }
            else {
                cout << "Очередь пуста." << endl;
                system("pause");
            }
            break;
        case 3:
            if (pq.isEmpty()) {
                cout << "Очередь пуста." << endl;
                system("pause");
            }
            else {
                cout << "Очередь не пуста." << endl;
                system("pause");
            }
            break;
        case 4:
            if (!pq.isEmpty()) {
                cout << "Содержимое очереди:" << endl;
                cout << pq;
                system("pause");
            }
            else {
                cout << "Очередь пуста." << endl;
                system("pause");
            }
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
