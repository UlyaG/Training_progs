#ifndef POLINOM_H
#define POLINOM_H
#include "array.h"

class Polinom {
public:
	Polinom();
	int degree();
	number calculPol(number);
	void editDegree(int);
	void editA(number);
	void editR(int, number);
	friend istream& operator >> (istream&, Polinom&);
	friend ostream& operator << (ostream&, Polinom&);
private:
	Array r; 
	Array a; 
	int n; 
	void calculA();
};

#endif POLINOM_H