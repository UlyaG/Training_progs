#include "complex.h"
#include <cmath>

istream& operator>> (istream& is, Complex& c) {
	is.exceptions(std::ios::failbit | std::ios::badbit);
	try {
		is >> c.re;
		if (is.peek() == '\n') {
			c.im = 0;
			is.ignore();
		}
		else
			is >> c.im;
	}
	catch (const ios::failure& e) {
		cin.clear();
		is.ignore(INT_MAX, '\n');
		cin >> c.re;
		if (is.peek() == '\n') {
			c.im = 0;
			is.ignore();
		}
		else
			is >> c.im;
	}	
	return is;
};

ostream& operator<< (ostream& os, const Complex& c) {
	if (c.im < 0)
		os <<'(' << c.re << c.im << "i)";
	if (c.im > 0) 
		os << '(' << c.re << '+' << c.im << "i)";
	if ((c.im == 0))
		if (c.re < 0)
			os <<'(' << c.re << ')';
		else os << c.re;
	
	return os;
};


Complex operator+ (const Complex & frst, const Complex & scnd) {
	return Complex(frst.re+scnd.re, frst.im+scnd.im);
}

Complex operator- (const Complex& frst, const Complex& scnd) {
	return Complex(frst.re - scnd.re, frst.im - scnd.im);
}

Complex operator* (const Complex& frst, const Complex& scnd) {
	return Complex(frst.re * scnd.re - frst.im*scnd.im, frst.im*scnd.re + frst.re*scnd.im);
}

Complex operator/ (const Complex& frst, const Complex& scnd) {
	return Complex((frst.re * scnd.re + frst.im * scnd.im) / (scnd.re * scnd.re + scnd.im * scnd.im),
		(scnd.re * frst.im - frst.re * scnd.im) / (scnd.re * scnd.re + scnd.im * scnd.im));
}

Complex operator/ (Complex& frst, int scnd) {
	return Complex(frst.re/scnd, frst.im/scnd);
}

Complex& Complex::operator= (const Complex& scnd) {
	if (this != &scnd) {
		re = scnd.re;
		im = scnd.im;
	}
	return *this;
}

Complex& Complex::operator=(const double& scnd)
{
	if (&re != &scnd) {
		re = scnd;
		im = 0;
	}
	return *this;
}

bool operator< (Complex& frst, Complex& scnd) {
	if ((frst.im == 0) && (scnd.im == 0))
		return frst.re < scnd.re;
	else if (frst.module() == scnd.module())
		return frst.arg() < scnd.arg();
	else 
		return frst.module() < scnd.module();
}

bool operator> (Complex& frst, Complex& scnd) {
	if ((frst.im == 0) && (scnd.im == 0))
		return frst.re > scnd.re;
	else if (frst.module() == scnd.module())
		return frst.arg() > scnd.arg();
	else
		return frst.module() > scnd.module();
}

bool operator== (Complex& frst, Complex& scnd) {
	return (frst.re == scnd.re) && (frst.im == scnd.im);
}

bool operator== (const Complex& frst, int i) {
	Complex scnd = i;
	return (frst.re == scnd.re) && (frst.im == scnd.im);
}


Complex::Complex() {
	re = 0;
	im = 0;
}

Complex::Complex(double x) {
	re = x;
	im = 0;
}

Complex::Complex(double x, double y) {
	re = x;
	im = y;
}

double Complex::module() {
	if (im == 0)
		return re;
	else
		return sqrt(re * re + im * im);
}

double Complex::arg() {
	return acos(re / module());
}

Complex Complex::comSqrt() {
	Complex a(sqrt(module()) * cos(arg() / 2), sqrt(module()) * sin(arg() / 2));
	return a;
}