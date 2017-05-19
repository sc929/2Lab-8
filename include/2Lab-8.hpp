#include <iostream>
#include <stdlib.h>
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

	Complex(const Complex& comp)
	{
		real = comp.real;
		im = comp.im;
	}

	void print(ostream&)
	{
		cout << real << " + i*(" << im << ')' << endl;
	}

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
	bool operator== (const Complex& c) {
		if ((real == c.real) && (im == c.im)) {
			return true;
		}
		else return false;
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
