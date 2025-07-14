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
			cout << "������� ����� �������� ������������ a[n]: ";
			cin >> value;
			pol.editA(value);
			break;
		}
		case 3:
		{
			int index;
			cout << "������� ������ ����������� �����: ";
			cin >> index;
			number value; 
			cout << "������� ����� �������� �����: ";
			cin >> value;
			pol.editR(index, value);
			break;
		}
		case 4:
		{
			number x;
			cout << "������� �������� �: ";
			cin >> x;
			cout <<"�������� �������� � ����� " << x << ": " << pol.calculPol(x) << endl;
			break;
		}
		case 5:
		{
			int size;
			cout << "������� ����� ������� ��������: ";
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
			cout << "������: ��������� ����." << endl;
			break;
		}
	}
}

// ����� ����
int ConsApp::menu(int n) {
	int ans;
	cout << "�������� ��������: " << endl
		<< "1) ������ ������� (����������� " << n << ")." << endl
		<< "2) �������� �����������." << endl
		<< "3) �������� ������." << endl
		<< "4) ��������� ������� � �������� �����." << endl
		<< "5) �������� ������� ��������." << endl
		<< "6) ������� �������." << endl
		<< "0) ��������� ������ � ����������." << endl
		<< "����: ";
	cin >> ans;
	return ans;
}