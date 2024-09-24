#include <iostream>

using namespace std;

class Complex {
private:
	double _real;
	double _imag;

public:
	Complex()
	{
		_real = 0.0;
		_imag = 0.0;
	}

	Complex(double real) : Complex()
	{
		this->_real = real;
	}

	Complex(double real, double imag) : Complex(real)
	{
		this->_imag = imag;
	}

	void setReal(double rea) {
		_real = rea;
	}

	void setImag(double ima) {
		_imag = ima;
	}

	double getReal() const {
		return _real;
	}

	double getImag() const {
		return _imag;
	}

	Complex operator+(const Complex& right) const {
		return Complex(_real + right._real, _imag + right._imag);
	}

	Complex operator-(const Complex& right) const {
		return Complex(_real - right._real, _imag - right._imag);
	}

	Complex operator*(const Complex& right) const {
		double newReal = _real * right._real - _imag * right._imag;
		double newImag = _real * right._imag + _imag * right._real;
		return Complex(newReal, newImag);
	}

	Complex operator/(const Complex& right) const {
		double denominator = right._real * right._real + right._imag * right._imag;
		double newReal = (_real * right._real + _imag * right._imag) / denominator;
		double newImag = (_imag * right._real - _real * right._imag) / denominator;
		return Complex(newReal, newImag);
	}
};

ostream& operator<<(ostream& os, const Complex& c) {
	os << c.getReal();
	if (c.getImag() >= 0)
		os << " + " << c.getImag() << "i";
	else
		os << " - " << -c.getImag() << "i";
	return os;
}

istream& operator>>(istream& is, Complex& c) {
	double real, imag;
	cout << "Enter real number: ";
	is >> real;
	cout << "Enter imaginary number: ";
	is >> imag;
	c.setReal(real);
	c.setImag(imag);
	return is;
}

int main() {
	Complex c1, c2;

	cout << "Enter first complex number:" << endl;
	cin >> c1;

	cout << "Enter second complex number:" << endl;
	cin >> c2;

	Complex result_add = c1 + c2;
	Complex result_sub = c1 - c2;
	Complex result_mul = c1 * c2;
	Complex result_div = c1 / c2;

	cout << "-------------" << endl;

	cout << "Addition: " << result_add << endl;
	cout << "Subtraction: " << result_sub << endl;
	cout << "Multiplication: " << result_mul << endl;
	cout << "Division: " << result_div << endl;

	cout << "-------------" << endl;
	
	cout << c1 << endl;
	cout << c2 << endl;

	return 0;
}


/*
Enter first complex number:
Enter real number: 3
Enter imaginary number: 8
Enter second complex number:
Enter real number: 4
Enter imaginary number: 7
-------------
Addition: 7 + 15i
Subtraction: -1 + 1i
Multiplication: -44 + 53i
Division: 1.04615 + 0.169231i
-------------
3 + 8i
4 + 7i

C:\Users\David\source\repos\ConsoleApplication2 task 2\x64\Debug\ConsoleApplication2 task 2.exe (процесс 6200) завершил работу с кодом 0 (0x0).
Нажмите любую клавишу, чтобы закрыть это окно:


*/

