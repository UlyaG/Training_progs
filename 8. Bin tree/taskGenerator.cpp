#include <iostream>
#include <queue>
#include <string>
#include <fstream>
#include "Functions.h"
using namespace std;

void createStringTree(int arr[9], queue <string> &file) {
	Node* root = new Node;
	root->key = arr[0];
	root->left = 0;
	root->right = 0;
	int j = 0;
	for (int i = 1; i < 9; i++) {
		create(arr[i], root, j);
	}
	outputFileOp(root, j, 0, file);
}

void createArrTree(int arr[9], Node* root) {
	root->key = arr[0];
	root->left = 0;
	root->right = 0;
	int j = 0;
	for (int i = 1; i < 9; i++) {
		create(arr[i], root, j);
	}
}

void straightPassArr(Node* node, int arr[9], int i) {
	if (node) {
		arr [i] = node->key;
		i++;
		straightPassArr(node->left, arr, i);
		straightPassArr(node->right, arr, i);
	}
}

void reversePassArr(Node* node, int arr[9], int i) {
	if (node) {
		reversePassArr(node->left, arr, i);
		reversePassArr(node->right, arr, i); 
		arr[i] = node->key;
		i++;
	}
}

void widePassArr(Node* node, int arr[9], int i) {
	if (node) {
		reversePassArr(node->left, arr, i);
		arr[i] = node->key;
		i++;
		reversePassArr(node->right, arr, i);
	}
}

void task(int type, int arr[9], int key, queue <string> &file) {
	string element;
	switch (type) {
	case 0:
		file.push("Как будет выглядеть бинарное дерево для следующей последовательности?");
		for (int i = 0; i < 9; i++) {
			element = element + to_string(arr[i]) + ' ';
		}
		file.push(element);
		break;
	case 1:
		file.push("Как будет выглядеть прямой обход следующего дерева?");
		createStringTree(arr, file);
		break;
	case 2:
		file.push("Как будет выглядеть обратный обход следующего дерева? ");
		createStringTree(arr, file);
		break;
	case 3:
		file.push("Как будет выглядеть обход в ширину следующего дерева?");
		createStringTree(arr, file);
		break;
	case 4:
		file.push("Как будет выглядеть следующее дерево после удаления " + to_string(key) + "?");
		createStringTree(arr, file);
		break;
	case 5:
		file.push("Как будет выглядеть следующее дерево после вставки " + to_string(key) + "?");
		createStringTree(arr, file);
		break;
	}
	file.push(" ");
}

void answ(int type, int arr[9], int key, queue <string> &file) {
	string element;
	Node* root = new Node;
	int i = 0;
	switch (type) {
	case 0:
		createStringTree(arr, file);
		break;
	case 1:
		createArrTree(arr, root);
		straightPassArr(root, arr, 0);
		for (i = 0; i < 9; i++) {
			element = element + to_string(arr[i]) + ' '; 
		}
		file.push(element); 
		break;
	case 2:
		createArrTree(arr, root);
		reversePassArr(root, arr, 0);
		for (int i = 0; i < 9; i++) {
			element = element + to_string(arr[i]) + ' ';
		}
		file.push(element);
		break;
	case 3:
		createArrTree(arr, root);
		widePassArr(root, arr, 0);
		for (i = 0; i < 9; i++) {
			element = element + to_string(arr[i]) + ' ';
		}
		file.push(element);
		break;
	case 4:
		createArrTree(arr, root); 
		root = del(key, root);
		
		outputFileOp(root, i, 0, file);
		break;
	case 5:
		createArrTree(arr, root);
		i = 0;
		create(key, root, i);
		i = 0;
		outputFileOp(root, i, 0, file);
		break;
	}
	file.push(" ");
}

void taskGen(int n) {
	queue <string> fileTask;
	queue <string> fileAnsw;
	srand(time(NULL));
	for (int i = 1; i <= n; i++) {
		fileTask.push("Задание #" + to_string(i));
		fileAnsw.push("Ответ #" + to_string(i));
		int type = rand() % 6;
		int arr[9], key=0;
		for (int j = 0; j < 9; j++)
			arr[j] = rand() % 99;
		if (type == 4)
			key = arr[rand() % 9];
		if (type == 5)
			key = rand() % 99;
		task(type, arr, key, fileTask);
		answ(type, arr, key, fileAnsw);
	}
	ofstream File;
	File.open("outputTask.txt");
	while (!(fileTask.empty())) {
		File << fileTask.front() << endl;
		fileTask.pop();
	}
	File.close(); 
	File.open("outputAns.txt");
	while (!(fileAnsw.empty())) { 
		File << fileAnsw.front() << endl; 
		fileAnsw.pop();   
	}
	File.close(); 
}