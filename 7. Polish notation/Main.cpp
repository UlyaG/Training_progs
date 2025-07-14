#include <iostream>
#include "Functions.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    string simple;
    string prefix;
    string reverse;
    while (1) {
        cout << "Выберите действие:" << endl
            << "1. Преобразовать введенное простое выражение." << endl
            << "2. Проверка на корректность введенного выражения." << endl
            << "3. Вычислить введенное выражение." << endl
            << "Ввод: ";
        int item1 = 0;
        int item2;
        while ((item1 < 1) || (item1 > 3)) {
            cin >> item1;
            cout << endl;
            switch (item1) {
            case 1: 
                cout << "Введите выражение: ";
                cin >> simple;
                prefix = fromSimpToPrefix(simple);
                reverse = fromSimpToReverse(simple);
                cout << "Прямая польская нотация: " << prefix << endl;
                cout << "Обратная польская нотация: " << reverse << endl;
                break;
            case 2:
                cout << "Какого вида выражение будет вводиться?" << endl
                    << "1. Простого." << endl
                    << "2. Прямой польской нотации." << endl
                    << "3. Обратной польской нотации" << endl
                    << "Ввод: ";
                item2 = 0;
                while ((item2 < 1) || (item2 > 3)) {
                    cin >> item2;
                    cout << endl;
                    switch (item2) {
                    case 1:
                        break;
                    case 2:
                        break;
                    case 3:
                        break;
                    default: 
                        errorInput();
                    }
                }
                break;
            case 3: 
                cout << "Какого вида выражение будет вводиться?" << endl
                    << "1. Простого." << endl
                    << "2. Прямой польской нотации." << endl
                    << "3. Обратной польской нотации" << endl
                    << "Ввод: ";
                item2 = 0;
                while ((item2 < 1) || (item2 > 3)) {
                    cin >> item2;
                    switch (item2) {
                    case 1:
                        break;
                    case 2:
                        break;
                    case 3:
                        break;
                    default:
                        errorInput();
                    }
                }
                break;
            default:
                errorInput();
            }
        }
    }
    return 0;
}

