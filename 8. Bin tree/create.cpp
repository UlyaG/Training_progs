#include <iostream>
#include <fstream>
#include "Functions.h"
using namespace std;

Node* create(int key, Node* node, int& i) {
	if (key < node->key)
		if (node->left == 0) {
			node->left = new Node;
			node->left->key = key;
			node->left->left = 0;
			node->left->right = 0;
			i++;
			return node->left;
		}
		else create(key, node->left, i);
	if (key > node->key)
		if (node->right == 0) {
			node->right = new Node;
			node->right->key = key;
			node->right->left = 0;
			node->right->right = 0;
			i++;
			return node->right;
		}
		else create(key, node->right, i);
	return 0;
}

Node *createRandom() {
	int n = 0, i = 1;
	Node* root = new Node;
	while (n < 1) {
		cout << "Введите количество элементов: ";
		cin >> n;
		if (n < 1)
			cout << "В дереве не может быть меньше 1 элемента!" << endl;
	}
	srand(time(NULL));
	root->key = rand() % 199 - 99;
	root->left = 0;
	root->right = 0;
	while (i<n) {
		int key = rand() % 199 - 99;
		create(key, root, i);
	}
	return root;
}

Node* createInput() {
	int key, i = 1;
	Node* root = new Node;
	cout << "Начните ввод чисел." << endl
		<< "Разделяйте числа вводом ENTER." << endl
		<< "Для завершения введите любое число, выходящее за промежуток от -99 до 99." << endl;
	
	cin >> root->key;
	root->left = 0;
	root->right = 0;
	cin >> key;
	while ((key < 100)&&(key>-100)) {
		create(key, root, i);
		cin >> key;
	}
	return root;
}

Node* createFile() {
	string fileName; 
	Node* root = new Node;
	int key=0, i = 1, j=0;
	ifstream File;
	do {
		if ((!File.is_open()) && (j > 0))
			cout << "Файл не найден." << endl;
		else if (((root->key > 99) || (root->key < -99)) && (j > 0))
			cout << "Файл пуст или начинается с числа, выходящего за область допустимых значений." << endl;
		cout << "Введите полное название файла: ";
		cin >> fileName;
		File.open(fileName); 
		j++;
		File >> root->key;
	} while (!File.is_open() || (root->key > 99) || (root->key < -99));
	root->left = 0; 
	root->right = 0; 
	while (!File.eof() && (key < 100) && (key > -100)){
		File >> key;
		create(key, root, i);
	}
	File.close();
	return root;
}
