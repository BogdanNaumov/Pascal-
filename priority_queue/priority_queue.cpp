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
        cout << "�������� ��������:" << endl;
        cout << "1. �������� �������" << endl;
        cout << "2. ������� �������" << endl;
        cout << "3. ���������, ����� �� �������" << endl;
        cout << "4. ������� �������" << endl;
        cout << "0. �����" << endl;
        cout << "��� �����: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "������� ��������� � �������� ��������: ";
            cin >> priority >> value;
            pq.insert(priority, value);
            cout << "������� �������� � �������." << endl;
            system("pause");
            break;
        case 2:
            if (!pq.isEmpty()) {
                cout << "����������� �������: " << pq.pop() << endl;
                system("pause");
            }
            else {
                cout << "������� �����." << endl;
                system("pause");
            }
            break;
        case 3:
            if (pq.isEmpty()) {
                cout << "������� �����." << endl;
                system("pause");
            }
            else {
                cout << "������� �� �����." << endl;
                system("pause");
            }
            break;
        case 4:
            if (!pq.isEmpty()) {
                cout << "���������� �������:" << endl;
                cout << pq;
                system("pause");
            }
            else {
                cout << "������� �����." << endl;
                system("pause");
            }
            break;
        case 0:
            cout << "�����." << endl;
            break;
        default:
            cout << "�������� ����. ���������� ��� ���." << endl;
            system("pause");
        }

    } while (choice != 0);

    return 0;
}
