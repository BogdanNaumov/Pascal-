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
        cout << "�������� ��������:" << endl;
        cout << "1. �������� �������" << endl;
        cout << "2. ������� �������" << endl;
        cout << "3. ���������, ���������� �� �������" << endl;
        cout << "4. ������� ������" << endl;
        cout << "0. �����" << endl;
        cout << "��� �����: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "������� �������� �������� ��� �������: ";
            cin >> value;
            sl.insert(value);
            cout << "������� �������� � ������." << endl;
            system("pause");
            break;
        case 2:
            cout << "������� �������� �������� ��� ��������: ";
            cin >> value;
            sl.remove(value);
            cout << "������� ������ �� ������." << endl;
            system("pause");
            break;
        case 3:
            cout << "������� �������� �������� ��� ������: ";
            cin >> value;
            if (sl.search(value)) {
                cout << "������� ������ � ������." << endl;
            }
            else {
                cout << "������� �� ������ � ������." << endl;
            }
            system("pause");
            break;
        case 4:
            cout << "���������� ������:" << endl;
            sl.printList();
            system("pause");
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