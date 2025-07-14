#include <iostream>
#include <iomanip>
#include <queue>
#include <string>
#include <fstream>
#include "Functions.h"
using namespace std;


void outputConsole(Node* node, int &i, int side) {
	if (node!=0) {
		i++;
		outputConsole(node->right, i, 1);
		if (side==1)
			cout << setw(i * 3) << "Г  " << node->key << endl;
		if (side == 2)
			cout << setw(i * 3) << "L  " << node->key << endl;
		if (side == 0)
			cout << setw(i * 3) << node->key << endl;
		outputConsole(node->left, i, 2);
		i--;
	}
}

void outputFileOp(Node* node, int& i, int side, queue <string> &file) {
	if (node != 0) {
		i++;
		outputFileOp(node->right, i, 1, file);
		if (side == 1)
			file.push(string(i * 3, ' ') + "Г  " + to_string(node->key));
		if (side == 2)
			file.push(string(i * 3, ' ') + "L  " + to_string(node->key));
		if (side == 0)
			file.push(string(i * 3, ' ') + to_string(node->key));
		outputFileOp(node->left, i, 2, file);
		i--;
	}
}

void outputFileMain(Node* node, int& i, int side) {
	ofstream File;
	File.open("tree.txt");
	queue <string> fileStr;
	outputFileOp(node, i, 0, fileStr);
	while (!(fileStr.empty())) {
		File << fileStr.front() << endl;
		fileStr.pop();
	}
	File.close();
}

Node* maxNode(Node* node) {
	while (node->right) {
		node = node->right;
	}
	return node;
}

int delSit(int key, Node* node) {
	if ((key < node->key) && (node->left != 0)) {
		switch (delSit(key, node->left)) {
		case 1: 
			node->left = 0;
			break;
		case 2:
			node->left = node->left->left;
			break;
		case 3:
			node->left = node->left->right;
			break;
		case 4:
			node->left->key = maxNode(node->left->left)->key;
			node = del(maxNode(node->left->left)->key, node->left->left);
			break;
		}
		return 5;
	}
	else if ((key > node->key) && (node->right != 0)) {
		switch (delSit(key, node->right)) {
		case 1: 
			node->right = 0;
			break;
		case 2: 
			node->right = node->left->left;
			break;
		case 3:
			node->right = node->left->right;
			break;
		case 4: 
			node->right->key = maxNode(node->right->left)->key;
			del(maxNode(node->right->left)->key, node->right->left);
			break;
		}
		return 5;
	}
	else if (key == node->key) {
		if ((node->left == 0) && (node->right == 0))
			return 1;
		if ((node->left != 0) && (node->right == 0))
			return 2;
		if ((node->left == 0) && (node->right != 0))
			return 3;
		if ((node->left != 0) && (node->right != 0))
			return 4;
	}
	else return 0;
	
}

Node* del(int key, Node* node) {
	if (delSit(key, node) == 0)
		cout << "Число не найдено!";
	else return node;
}

bool search(int key, Node* node) {
	if ((key < node->key) && (node->left != 0))
		search(key, node->left);
	if ((key > node->key) && (node->right != 0))
		search(key, node->right);
	if (key == node->key)
		return 1;
	return 0;
}

void straightPass(Node* node) {
	if (node) {
		cout << node->key << ' ';
		straightPass(node->left);
		straightPass(node->right);
	}
}

void widePass(Node* node) {
	if (node) {
		straightPass(node->left);
		cout << node->key << ' ';
		straightPass(node->right);
	}
}

void reversePass(Node* node) {
	if (node) {
		straightPass(node->left);
		straightPass(node->right);
		cout << node->key << ' ';
	}
}