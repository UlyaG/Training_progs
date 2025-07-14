#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Node {
	int key;
	Node* left;
	Node* right;
};

Node* menu_1(int);
void menu_2(int, Node*, int&);
void menu_3(int, Node*);
void menu_4(Node*);

Node* create(int, Node*, int&);
Node* del(int, Node*);
bool search(int, Node*);

Node* createRandom();
Node* createInput();
Node* createFile();

void outputConsole(Node*, int&, int);
void outputFileMain(Node*, int&, int);
void outputFileOp(Node*, int&, int, queue <string>&);

void straightPass(Node*);
void widePass(Node*);
void reversePass(Node*);

void taskGen(int);