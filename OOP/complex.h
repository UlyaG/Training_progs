#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
using namespace std;

class Complex {
public:
	Complex();
	Complex(double x);
	Complex(double x, double y);
	
	friend istream& operator >> (istream&, Complex&);  
	friend ostream& operator << (ostream&, const Complex&);
	friend Complex operator+ (const Complex&, const Complex&);
	friend Complex operator- (const Complex&, const Complex&);
	friend Complex operator* (const Complex&, const Complex&);
	friend Complex operator/ (const Complex&, const Complex&);
	friend Complex operator/ (Complex&, int);
	Complex& operator= (const Complex&);
	Complex& operator= (const double&);
	friend bool operator< (Complex&, Complex&);
	friend bool operator> (Complex&, Complex&);
	friend bool operator== (Complex&, Complex&);
	friend bool operator== (const Complex& frst, int i); 
	Complex comSqrt();
	double module(); 
private: 
	double re;
	double im;
	double arg();
};

#endif COMPLEX_H