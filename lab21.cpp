#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

class ComplexNumber
{
public:
	double real;
	double imag;
	ComplexNumber(double, double);
	ComplexNumber operator+(const ComplexNumber &);
	ComplexNumber operator-(const ComplexNumber &);
	ComplexNumber operator*(const ComplexNumber &);
	ComplexNumber operator/(const ComplexNumber &);
	bool operator==(const ComplexNumber &);
	double abs();
	double angle();
};

ComplexNumber::ComplexNumber(double x = 0, double y = 0)
{
	real = x;
	imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c)
{
	return ComplexNumber(real + c.real, imag + c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c)
{
	return ComplexNumber(real - c.real, imag - c.imag);
}

//Write your code here

ComplexNumber ComplexNumber::operator*(const ComplexNumber &c)
{
	double e, f, g, h;
	e = c.real * real;
	f = c.real * imag;
	g = c.imag * imag;
	h = c.imag * real;
	return ComplexNumber(e - g, f + h);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c)
{
	double e, f, g, h, i;
	e = c.real * real;
	f = c.real * imag;
	g = c.imag * imag;
	h = c.imag * real;
	i = pow(c.real, 2) + pow(c.imag, 2);
	return ComplexNumber((e + g) / i, (f - h) / i);
}

ComplexNumber operator+(double s, const ComplexNumber &c)
{
	return ComplexNumber(s + c.real, c.imag);
}

ComplexNumber operator-(double s, const ComplexNumber &c)
{
	return ComplexNumber(s - c.real, -c.imag);
}

ComplexNumber operator*(double s, const ComplexNumber &c)
{
	return ComplexNumber(s * c.real, s * c.imag);
}

ComplexNumber operator/(double s, const ComplexNumber &c)
{
	double i;
	i = pow(c.real, 2) + pow(c.imag, 2);
	return ComplexNumber((s * c.real) / i, (s * (-c.imag)) / i);
}

bool ComplexNumber::operator==(const ComplexNumber &f)
{
	if (real == f.real && imag == f.imag)
	{
		return true;
	}
	else
	{
		return false;
	}
}

ComplexNumber operator==(double s, const ComplexNumber &f)
{
	if (s == f.real && f.imag == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

double ComplexNumber::abs()
{
	double r;
	r = sqrt(pow(real, 2) + pow(imag, 2));
	return r;
}

double ComplexNumber::angle()
{
	double e;
	e = atan2(imag, real) * 180 / M_PI;
	return e;
}

ostream &operator<<(ostream &a, const ComplexNumber &b)
{
	if ((b.real == 0) && (b.imag == 0))
	{
		return a << 0;
	}
	if (b.real != 0)
		a << b.real;
	if (b.imag == 0)
		return a;
	if (b.imag > 0 && b.real != 0)
	{
		a << "+";
	}
	a << b.imag;
	a << "i";
	return a;
}

int main()
{
	ComplexNumber a(1.5, 2), b(3.2, -2.5), c(-1, 1.2);
	cout << a << "\n";
	cout << b << "\n";
	cout << c << "\n";
	cout << a + 2.5 << "\n";
	cout << 2.5 + a << "\n";
	cout << a - 1.5 << "\n";
	cout << 1.5 - a << "\n";
	cout << b + ComplexNumber(0, 2.5) << "\n";
	cout << c - c << "\n";
	cout << "-----------------------------------\n";

	ComplexNumber d = (a + b) / c;
	ComplexNumber e = b / (a - c);
	cout << d << "\n";
	cout << e << "\n";
	cout << c * 2 << "\n";
	cout << 0.5 * c << "\n";
	cout << 1 / c << "\n";
	cout << "-----------------------------------\n";

	cout << ComplexNumber(1, 1).abs() << "\n";
	cout << ComplexNumber(-1, 1).abs() << "\n";
	cout << ComplexNumber(1.5, 2.4).abs() << "\n";
	cout << ComplexNumber(3, 4).abs() << "\n";
	cout << ComplexNumber(69, -9).abs() << "\n";
	cout << "-----------------------------------\n";

	cout << ComplexNumber(1, 1).angle() << "\n";
	cout << ComplexNumber(-1, 1).angle() << "\n";
	cout << ComplexNumber(-1, -1).angle() << "\n";
	cout << ComplexNumber(1, -1).angle() << "\n";
	cout << ComplexNumber(5, 2).angle() << "\n";
	cout << "-----------------------------------\n";

	cout << (ComplexNumber(1, 1) == ComplexNumber(1, 2)) << "\n";
	cout << (ComplexNumber(1, 1) == 1) << "\n";
	cout << (0 == ComplexNumber()) << "\n";
}
