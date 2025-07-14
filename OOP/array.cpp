#include "array.h"
#include "complex.h"
#include <iostream>
using namespace std;

Array::Array() {
	n = 0;
	arr = createArr();
}

Array::Array(int size) {
	n = size;
	arr = createArr();
}

number* Array::createArr() {
	return new number[n];
};

void Array::editArr() {
	for (int i = 0; i < n; i++) {
		cout << "¬ведите " << i << " элемент массива: ";
		cin >> arr[i];
	}
}

number Array::average() {
	number sum = 0;
	for (int i = 0; i < n; i++) {
		sum = sum + arr[i];
	}
	return (sum / n);
}

number Array::sko() {
	number sum = 0;
	number av = average();
	for (int i = 0; i < n; i++) {
		sum = sum + (arr[i] - av) * (arr[i] - av);
	}
	sum = sum / (n - 1);
	return sum.comSqrt();
}

const number& Array::showEl(int j) {
	return arr[j];
}

void Array::decreaseSort() {
	bool notComp = 1;
	while (notComp) {
		notComp = 0;
		for (int i = 0; i < n - 1; i++) {
			if (arr[i] < arr[i + 1]) {
				number c = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = c;
				notComp = 1;
			}
		}
	}
}

void Array::increaseSort() {
	bool notComp = 1;
	while (notComp) {
		notComp = 0;
		for (int i = 0; i < n - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				number c = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = c;
				notComp = 1;
			}
		}
	}
}

void Array::editSize(int newSize) {
	number* newArr = new number[newSize];
	if (newSize > n) {
		for (int i = 0; i < n; i++) {
			newArr[i] = arr[i];
		}
	}
	else {
		for (int i = 0; i < newSize; i++) {
			newArr[i] = arr[i];
		}
	}
	arr = newArr;
	n = newSize;
}

void Array::editElement(int j, number value) {
	arr[j] = value;
}

void Array::showArr() {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\t";
	}
	cout << endl;
}

int Array::size() {
	return n;
}