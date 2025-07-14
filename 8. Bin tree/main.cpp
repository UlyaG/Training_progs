#include <iostream>
#include "Functions.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	int rep = 1;
	Node* root = new Node;

	while (rep == 1) {

		int item = 0;
		root = menu_1(item); //создание дерева

		rep = 2;
		while (rep == 2) {

			item = 0;
			menu_2(item, root, rep); //работа с деревом
		}
	}
}