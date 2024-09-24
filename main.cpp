#include <iostream>

using namespace std;

class Fraction {
private:
	int _numerator;
	int _denominator;

public:
	Fraction()
	{
		_numerator = 0;
		_denominator = 1;
	}

	Fraction(int num) : Fraction()
	{
		_numerator = num;
	}

	Fraction(int num, int den) : Fraction(num)
	{
		_denominator = den;
	}


	void setNum(int num)
	{
		_numerator = num;
	}

	void setDen(int den)
	{
		_denominator = den;
	}


	int getNum() const
	{
		return _numerator;
	}

	int getDen() const
	{
		return _denominator;
	}

	Fraction operator+(const Fraction& right) const {
		int num = _numerator * right._denominator + right._numerator * _denominator;
		int denom = _denominator * right._denominator;
		return Fraction(num, denom);
	}

	Fraction operator-(const Fraction& right) const {
		int num = _numerator * right._denominator - right._numerator * _denominator;
		int denom = _denominator * right._denominator;
		return Fraction(num, denom);
	}

	Fraction operator*(const Fraction& right) const {
		int num = _numerator * right._numerator;
		int denom = _denominator * right._denominator;
		return Fraction(num, denom);
	}

	Fraction operator/(const Fraction& right) const {
		int num = _numerator * right._denominator;
		int denom = _denominator * right._numerator;
		return Fraction(num, denom);
	}
};

ostream& operator<<(ostream& os, const Fraction& frac) {
	os << frac.getNum() << "/" << frac.getDen();
	return os;
}

istream& operator>>(istream& is, Fraction& frac) {
	int num, denom;
	cout << "Enter numerator: ";
	is >> num;
	cout << "Enter denominator: ";
	is >> denom;
	frac.setNum(num);
	frac.setDen(denom);
	return is;
}

int main() {
	Fraction f1;
	Fraction f2;
	cin >> f1;
	cin >> f2;

	Fraction result_add = f1 + f2;
	Fraction result_sub = f1 - f2;
	Fraction result_mul = f1 * f2;
	Fraction result_div = f1 / f2;

	cout << "Addition: " << result_add << endl;
	cout << "Subtraction: " << result_sub << endl;
	cout << "Multiplication: " << result_mul << endl;
	cout << "Division: " << result_div << endl;

	return 0;
}

/*
Enter numerator: 4
Enter denominator: 8
Enter numerator: 3
Enter denominator: 9
Addition: 60/72
Subtraction: 12/72
Multiplication: 12/72
Division: 36/24

C:\Users\David\source\repos\ConsoleApplication2 task 2\x64\Debug\ConsoleApplication2 task 2.exe (процесс 4324) завершил работу с кодом 0 (0x0).
Нажмите любую клавишу, чтобы закрыть это окно:
*/