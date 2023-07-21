#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Fraction
{
	int numerator, denominator;

public:
	Fraction() :Fraction(0, 1) {}

	Fraction(int num, int denom)
	{
		if (denom == 0) throw exception("Division by zero");
		numerator = num;
		denominator = denom;
		simplify();
	}

	void addFraction(Fraction otherFraction)
	{
		numerator = numerator * otherFraction.denominator + otherFraction.numerator * denominator;
		denominator = denominator * otherFraction.denominator;
		simplify();
	}

	Fraction operator+(Fraction other)
	{
		Fraction temp(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
		temp.simplify();
		return temp;
	}

	Fraction operator++()
	{
		numerator += denominator;
		return *this;
	}

	Fraction operator++(int a)
	{
		Fraction temp = *this;
		numerator += denominator;
		return temp;
	}

	friend ostream& operator<< (ostream& os, const Fraction fraction);

private:
	int nod(int a, int b)
	{
		while (a != 0 && b != 0)
		{
			if (a > b)
				a = a % b;
			else
				b = b % a;
		}
		return a + b;
	}

	void simplify()
	{
		int n = nod(numerator, denominator);
		denominator /= n;
		numerator /= n;
	}
};

ostream& operator<< (ostream& os, const Fraction fraction)
{
	os << fraction.numerator << '/' << fraction.denominator;
	return os;
}


int main()
{
	Fraction a;
	Fraction b(5, 10);
	Fraction c(2, 5);

	a = b + c;


	cout << a << '\n';
	//a.addFraction(c);
	cout << a++ << '\n';
	cout << a << '\n';
	cout << b << '\n';



	system("pause");
	return 0;
}