#include <iostream>
#include <chrono>
#include "Functions.h"
using namespace std;
using namespace chrono;

void errorInput() {
	cout << "������!" << endl
		<< "��������� ����: ";
}

Node* menu_1(int item) {
	cout << "�������� ������ �������� ��������� ������:" << endl
		<< "1. ��������� ���������� ����������." << endl
		<< "2. ��������� ���������� ����������." << endl
		<< "3. ��������� ���������� �� �����." << endl
		<< "����: ";
	while ((item < 1) || (item > 3)) {
		cin >> item;
		switch (item) {
		case 1:
			return createRandom();
			break;
		case 2:
			return createInput();
			break;
		case 3:
			return createFile();
			break;
		default:
			errorInput();
		}
	}
}

void menu_2(int item, Node* root, int &rep) {
	cout << "�������� ��������:" << endl
		<< "1. ������� ������." << endl
		<< "2. �������� � ����������." << endl
		<< "3. ���������� ����� ������." << endl
		<< "4. ������� ����� ������." << endl
		<< "5. ������������� ������� � ��������� ������ � ����������." << endl
		<< "����: ";
	int i = 1;
	while ((item < 1) || (item > 5)) {
		cin >> item;
		switch (item) {
		case 1:
			cout << "��������� �������� ������: " << endl
				<< "(����� ��������� � ���� tree.txt)" << endl;
			outputConsole(root, i, 0);
			outputFileMain(root, i, 0);
			rep = 2;
			break;
		case 2:
			menu_3(item, root);
			rep = 2;
			break;
		case 3:
			menu_4(root);
			rep = 2;
			break;
		case 4:
			rep = 1;
			break;
		case 5:
			cout << "������� ������� �������������?" << endl
				<< "����: ";
			cin >> i;
			taskGen(i);
			rep = 0;
			break;
		default:
			errorInput();
		}
	}
}

void menu_3(int item, Node* root) {
	cout << "�������� ��������:" << endl
		<< "1. �������� ������� (������� �������� �������)." << endl
		<< "2. ������� ������� (������� �������� ��������)." << endl
		<< "3. ������� �������� ������ ��������." << endl
		<< "����: ";
	int key, i=1;
	time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> startInp, endInp;
	nanoseconds timeInp;
	time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> startDel, endDel;
	nanoseconds timeDel;
	time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> startSrch, endSrch;
	nanoseconds timeSrch;
	item = 0;
	while ((item < 1) || (item > 3)) {
		cin >> item;
		switch (item) {
		case 1:
			cout << "������� ����� ��� �������: ";
			cin >> key;

			startInp = steady_clock::now();
			create(key, root, key);
			endInp = steady_clock::now();
			timeInp = duration_cast<nanoseconds>(endInp - startInp);
			cout << "����� �������: " << timeInp.count() << " ���������." << endl;

			cout << "��� ������ ������:" << endl;
			outputConsole(root, i, 0);
			outputFileMain(root, i, 0);
			break;
		case 2:
			cout << "������� ����� ��� ��������: ";
			cin >> key;

			startDel = steady_clock::now(); 
			root = del(key, root);
			endDel = steady_clock::now(); 
			timeDel = duration_cast<nanoseconds>(endDel - startDel);
			cout << "����� ��������: " << timeDel.count() << " ���������." << endl;

			cout << "��� ������ ������:" << endl;
			outputConsole(root, i, 0);
			outputFileMain(root, i, 0);
			break;
		case 3:
			cout << "������� ����� ��� ������: ";
			cin >> key;
			startSrch = steady_clock::now();
			endSrch = steady_clock::now();
			timeSrch = duration_cast<nanoseconds>(endSrch - startSrch);
			
			if (!search(key, root))
				cout << "����� �� �������!" << endl;

			cout << "����� ������: " << timeSrch.count() << " ���������." << endl;
			break;
		default:
			errorInput();
		}
	}
}

void menu_4(Node* root) {
	cout << "�������� ��� ������:" << endl
		<< "1. ������." << endl
		<< "2. ��������." << endl
		<< "3. � ������." << endl
		<< "����: ";
	int item = 0;
	while ((item < 1) || (item > 3)) {
		cin >> item;
		switch (item) {
		case 1: 
			cout << "������ ����� ������: " << endl;
			straightPass(root);
			break;
		case 2:
			cout << "�������� ����� ������: " << endl;
			reversePass(root);
			break;
		case 3: 
			cout << "����� ������ � ������: " << endl;
			widePass(root);
			break;
		default: 
			errorInput();
		}
	}
	cout << endl;
}