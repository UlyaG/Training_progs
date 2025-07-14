#include "application.h"
#include "polinom.h"
#include "array.h"
#include <iostream>
using namespace std;

int ConsApp::exec() {
	setlocale(LC_ALL, "ru");
	Polinom pol;
	while (true) {
		switch (menu(pol.degree())) {
		case 1: 
			cin >> pol;
			cout << pol << endl;
			break;
		case 2: 
		{
			number value;
			cout << "Введите новое значение коэффициента a[n]: ";
			cin >> value;
			pol.editA(value);
			break;
		}
		case 3:
		{
			int index;
			cout << "Введите индекс изменяемого корня: ";
			cin >> index;
			number value; 
			cout << "Введите новое значение корня: ";
			cin >> value;
			pol.editR(index, value);
			break;
		}
		case 4:
		{
			number x;
			cout << "Введите значение х: ";
			cin >> x;
			cout <<"Значение полинома в точке " << x << ": " << pol.calculPol(x) << endl;
			break;
		}
		case 5:
		{
			int size;
			cout << "Введите новый порядок полинома: ";
			cin >> size;
			pol.editDegree(size);
			cin >> pol;
			break;
		}
		case 6:
		{
			cout << pol << endl;
			break;
		}
			break;
		case 0:
			return 0;
		default: 
			cout << "Ошибка: повторите ввод." << endl;
			break;
		}
	}
}

// новое меню
int ConsApp::menu(int n) {
	int ans;
	cout << "Выберите действие: " << endl
		<< "1) Задать полином (размерность " << n << ")." << endl
		<< "2) Изменить коэффициент." << endl
		<< "3) Изменить корень." << endl
		<< "4) Вычислить полином в заданной точке." << endl
		<< "5) Изменить порядок полинома." << endl
		<< "6) Вывести полином." << endl
		<< "0) Закончить работу с программой." << endl
		<< "Ввод: ";
	cin >> ans;
	return ans;
}