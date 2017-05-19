#include "stdafx.h"
#include <conio.h>
#include <iostream>

using namespace std;

class Complex
{
public:
	double real;
	double im;

	Complex() { real = 0.0; im = 0.0; }

	Complex(double real, double im)
	{
		this->real = real;
		this->im = im;
	}

	void print(ostream&)
	{
		cout << real << " + i*(" << im << ')' << endl;
	}

	friend ostream& operator << (ostream&, const Complex&);

	Complex add(Complex res)
	{
		res.real = real + res.real;
		res.im = im + res.im;
		return res;
	}

	Complex sub(Complex res)
	{
		res.real = real - res.real;
		res.im = im - res.im;
		return res;
	}

	Complex mult(int c)
	{
		Complex res(0, 0);
		res.real = real * c;
		res.im = im * c;
		return res;
	}

	Complex div(int c)
	{
		Complex res(0, 0);
		try
		{
			if (c == 0) throw c;
		}
		catch (int c)
		{
			cout << endl << "ERROR!!! You can't divide by zero" << endl;
			return res;
		}
		res.real = real / c;
		res.im = im / c;
		return res;
	}

	Complex& operator = (Complex &c)
	{
		real = c.real;
		im = c.im;
		return (*this);
	}
	Complex& operator +=  (Complex &c)
	{
		real += c.real;
		im += c.im;
		return *this;
	}
	Complex operator + (const Complex &c)
	{
		return Complex(real + c.real, im + c.im);
	}
	Complex&operator -=(const Complex &c) {
		real -= c.real;
		im -= c.im;
		return *this;
	}
	Complex operator - (const Complex &c)
	{
		return Complex(real - c.real, im - c.im);
	}
	Complex operator *=(Complex &c) {
		double a = real, b = im, x = c.real, y = c.im;
		real = a*x - b*y;
		im = b*x + a*y;
		return *this;
	}
	Complex operator * (const Complex &c)
	{
		return Complex(real * c.real - im * c.im, real * c.im + im * c.real);
	}
	Complex operator /=(Complex &c) {
		Complex t(real, im);
		double r = c.real * c.real + c.im * c.im;
		real = (t.real * c.real + t.im * c.im) / r;
		im = (t.im * c.real - t.real * c.im) / r;
		return *this;
	}
	Complex operator / (const Complex &c)
	{
		Complex temp;
		double r = c.real * c.real + c.im * c.im;
		temp.real = (real * c.real + im * c.im) / r;
		temp.im = (im* c.real - real * c.im) / r;
		return temp;
	}

};

ostream & operator<<(ostream & ciout, Complex &numb)
{
	numb.print(ciout);
	return ciout;
}

int main(void)
{
	Complex result(0, 0);

	//cout << "   Complex number z = x + i*y" << endl << "x = ";
	//cin >> real;
	//cout << "y = ";
	//cin >> im;

	cout << "z = ";
	Complex complex_num(13, 7);
	cout << complex_num;

	//cout << endl << "   '+' Complex number c = x + i*y" << endl << "x = ";
	//cin >> real;
	//cout << "y = ";
	//cin >> im;
	cout << "c = ";
	Complex plus(4, 9);
	cout << plus;
	cout << "z + c = ";
	result = complex_num.add(plus);
	cout << result;

	//cout << endl << "   '-' Complex number c = x + i*y" << endl << "x = ";
	//cin >> real;
	//cout << "y = ";
	//cin >> im;
	cout << "d = ";
	Complex minus(3, 16);
	cout << minus;
	cout << "z - d = ";
	result = complex_num.sub(minus);
	cout << result;

	//cout << endl << "   '*' z*a = x*a + i*(y*a)" << endl << "a = ";
	//cin >> a;
	cout << "z*5 = ";
	result = complex_num.mult(5);
	cout << result;

	//cout << endl << "   '/' z/a = x/a + i*(y/a)" << endl << "a = ";
	//cin >> a;
	cout << "z/3 = ";
	result = complex_num.div(3);
	cout << result; 
	result = complex_num + plus;
	cout << "z + c = " << result;
	result = complex_num / plus;
	cout << "z / c = " << result;
	result = complex_num * plus;
	cout << "z * c = " << result;
	_getch();
	return 0;
}