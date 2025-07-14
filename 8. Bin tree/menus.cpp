#include <iostream>
#include <chrono>
#include "Functions.h"
using namespace std;
using namespace chrono;

void errorInput() {
	cout << "Ошибка!" << endl
		<< "Повторите ввод: ";
}

Node* menu_1(int item) {
	cout << "Выберите способ создания бинарного дерева:" << endl
		<< "1. Заполнить случайными значениями." << endl
		<< "2. Заполнить введенными значениями." << endl
		<< "3. Заполнить значениями из файла." << endl
		<< "Ввод: ";
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
	cout << "Выберите действие:" << endl
		<< "1. Вывести дерево." << endl
		<< "2. Работать с элементами." << endl
		<< "3. Произвести обход дерева." << endl
		<< "4. Создать новое дерево." << endl
		<< "5. Сгенерировать задания и закончить работу с программой." << endl
		<< "Ввод: ";
	int i = 1;
	while ((item < 1) || (item > 5)) {
		cin >> item;
		switch (item) {
		case 1:
			cout << "Созданное бинарное дерево: " << endl
				<< "(также сохранено в файл tree.txt)" << endl;
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
			cout << "Сколько заданий сгенерировать?" << endl
				<< "Ввод: ";
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
	cout << "Выберите действие:" << endl
		<< "1. Вставить элемент (вывести скорость вставки)." << endl
		<< "2. Удалить элемент (вывести скорость удаления)." << endl
		<< "3. Вывести скорость поиска элемента." << endl
		<< "Ввод: ";
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
			cout << "Введите число для вставки: ";
			cin >> key;

			startInp = steady_clock::now();
			create(key, root, key);
			endInp = steady_clock::now();
			timeInp = duration_cast<nanoseconds>(endInp - startInp);
			cout << "Время вставки: " << timeInp.count() << " наносекуд." << endl;

			cout << "Вид нового дерева:" << endl;
			outputConsole(root, i, 0);
			outputFileMain(root, i, 0);
			break;
		case 2:
			cout << "Введите число для удаления: ";
			cin >> key;

			startDel = steady_clock::now(); 
			root = del(key, root);
			endDel = steady_clock::now(); 
			timeDel = duration_cast<nanoseconds>(endDel - startDel);
			cout << "Время удаления: " << timeDel.count() << " наносекуд." << endl;

			cout << "Вид нового дерева:" << endl;
			outputConsole(root, i, 0);
			outputFileMain(root, i, 0);
			break;
		case 3:
			cout << "Введите число для поиска: ";
			cin >> key;
			startSrch = steady_clock::now();
			endSrch = steady_clock::now();
			timeSrch = duration_cast<nanoseconds>(endSrch - startSrch);
			
			if (!search(key, root))
				cout << "Число не найдено!" << endl;

			cout << "Время поиска: " << timeSrch.count() << " наносекуд." << endl;
			break;
		default:
			errorInput();
		}
	}
}

void menu_4(Node* root) {
	cout << "Выберите тип обхода:" << endl
		<< "1. Прямой." << endl
		<< "2. Обратный." << endl
		<< "3. В ширину." << endl
		<< "Ввод: ";
	int item = 0;
	while ((item < 1) || (item > 3)) {
		cin >> item;
		switch (item) {
		case 1: 
			cout << "Прямой обход дерева: " << endl;
			straightPass(root);
			break;
		case 2:
			cout << "Обратный обход дерева: " << endl;
			reversePass(root);
			break;
		case 3: 
			cout << "Обход дерева в ширину: " << endl;
			widePass(root);
			break;
		default: 
			errorInput();
		}
	}
	cout << endl;
}