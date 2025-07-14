#include "polinom.h"
#include "complex.h"
#include <iostream>
using namespace std;

Polinom::Polinom() {
	n = 2;
	r.editSize(n);
	a.editSize(n + 1);

	a.editElement(0, 3);
	a.editElement(1, -4);
	a.editElement(2, 1);
	r.editElement(0, 1);
	r.editElement(1, 3);
}

int Polinom::degree() {
	return n;
}

number Polinom::calculPol(number x)
{
	number p = 1;
	for (int i = 0; i < n; i++) 
		p = p * (x - r.showEl(i));
	p = p * a.showEl(n);
	return p;
}

void Polinom::editDegree(int newDegree)
{
	n = newDegree;
	r.editSize(n);
	a.editSize(n + 1);
}

void Polinom::editA(number value)
{
	a.editElement(n, value);
	calculA();
}

void Polinom::editR(int index, number value)
{
	r.editElement(index, value);
	calculA();
}


void summary(Array set, Array subset, int i, int subsetSize, number& sum, int n) {
	if (subset.size() == subsetSize) {
		number rez = 1;
		for (int i = 0; i < subsetSize; i++)
			rez = rez * subset.showEl(i);
		sum = sum + rez;
		return;
	}
	if (i >= n) {
		return;
	}
	subset.editSize(subset.size() + 1);
	subset.editElement(subset.size()-1, set.showEl(i));
	summary(set, subset, i + 1, subsetSize, sum, n);

	subset.editSize(subset.size() -	1);
	summary(set, subset, i + 1,subsetSize, sum, n);
}

number coef(Array r, int n, int m) {
	Array prod(0); //массив произведений
	number sum = 0; //сумма произведений 
	summary(r, prod, 0, m, sum, n);
	return sum;
}

void Polinom::calculA() {
	if (n > 1) {
		int m = 1;
		for (int i = n - 1; i >= 0; i--) {
			number b = coef(r, n, m);
			if (i % 2 == 1)
				b = 0-b;
			a.editElement(i, b * a.showEl(n));
			m++;
		}
	}
	if (n == 1) {
		a.editElement(0, 0 - a.showEl(n) * r.showEl(0));
	}
}


istream& operator >> (istream& is, Polinom& p) {
	cout << "Введите a[n]: ";
	number an;
	is >> an;
	p.a.editElement(p.n, an);
	for (int i = 0; i < p.n; i++) {
		cout << "Введите " << i << " корень полинома: ";
		number rn;
		is >> rn;
		p.r.editElement(i, rn);
	}
	p.calculA();
	return is;
}

ostream& operator << (ostream& os, Polinom& p) {
	cout << "Выберите тип формы полинома:" << endl
		<< "0) p(x) = a[n]x^n + ... + a[1]x + a[0]" << endl
		<< "1) p(x) = a[n](x-r[n]) ... (x-r[1])" << endl
		<< "Ввод: ";
	bool type;
	cin >> type;
	if (type) {
		cout << "p(x) = " << p.a.showEl(p.n);
		for (int i = 0; i < p.n; i++) {
			cout << "(x-"<<p.r.showEl(i)<<")";
		}
	}
	else {
		cout << "p(x) = ";
		for (int i = p.n-1; i >=0; i--) {			
			if (p.a.showEl(i + 1) == 1 )
				cout << "x^" << i+1 << "+";
			else if (p.a.showEl(i + 1) == 0)
				continue;
			else cout << p.a.showEl(i + 1) << "*x^" << i+1 << "+";
		}
		cout << p.a.showEl(0);
	}
	return os;
}