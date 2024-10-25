#include <iostream>
using namespace std;

class Complex{
public:
	Complex();
	Complex(double realPart);
	Complex(double realPart, double imaginaryPart);
	double get_real() {return real;} 
	double get_imaginary() {return imaginary;}
	friend Complex operator+(const Complex a, const Complex b);
	friend Complex operator-(const Complex a, const Complex b);
	friend bool operator==(const Complex a, const Complex b);
	friend ostream& operator <<(ostream& output, const Complex a);
	friend istream& operator >>(istream& input, Complex& a);
	friend Complex operator*(const Complex a ,const Complex b);
private:
	double real;
	double imaginary;
};

Complex::Complex()
{
	real = 0.0;
	imaginary = 0.0;
}
Complex::Complex(double realPart)
{
	real = realPart;
	imaginary = 0.0;
}
Complex::Complex(double realPart, double imaginaryPart)
{
	real = realPart;
	imaginary = imaginaryPart;
}

ostream& operator<<(ostream& output, const Complex a)
{
	output << a.real << " + " << a.imaginary << "* i";
	return output;
}
istream& operator>>(istream& input, Complex& a)
{
	input >> a.real;
	input >> a.imaginary;
	return input;
}

Complex operator+(const Complex a, const Complex b)
{
	Complex sum;
	sum.real = a.real + b.real;
	sum.imaginary = a.imaginary + b.imaginary;
	return sum;
}
Complex operator-(const Complex a, const Complex b)
{
	Complex sum;
	sum.real = a.real - b.real;
	sum.imaginary = a.imaginary - b.imaginary;
	return sum;
}
bool operator==(const Complex a, const Complex b)
{

	return ((a.real == b.real) && (a.imaginary == b.imaginary));
}

Complex operator*(const Complex a ,const Complex b)
{
	Complex sum ;
	sum.real = ((a.real * b.real) - (a.imaginary * b.imaginary));	
	sum.imaginary = ((a.imaginary * b.real) + (a.real * b.imaginary));
	return sum;
}

int main() {
	const Complex i(0, 1);
	Complex a(5,3);
	Complex b;
	cin >> b;

	cout << a << ", " << " and " << b << endl;
	cout << "* opeator --" << a*b << endl;
	cout << "- opeator --" << a-b << endl;
	cout << "+ opeator --" << a+b << endl;
}
