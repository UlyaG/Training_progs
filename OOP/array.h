#ifndef ARRAY_H
#define ARRAY_H
#include "number.h"

class Array {
public:
	Array(); // ����� �����
	Array(int);
	void editArr();
	number average();
	number sko();
	const number& showEl(int); // ����� �����
	void increaseSort();
	void decreaseSort();
	void editSize(int);
	void editElement(int, number);
	void showArr();
	int size();
private:
	int n;
	number* arr;
	number* createArr();
};

#endif