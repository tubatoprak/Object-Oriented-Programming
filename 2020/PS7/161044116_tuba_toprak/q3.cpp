#include <iostream>
using namespace std;

class Polynomial {
public:
	Polynomial();
	Polynomial(const Polynomial& rhs);
	Polynomial(double coefficient[], int newsize);
	~Polynomial();
	double& operator[] (int degree);
	const double& operator[](int degree)const;
	const Polynomial& operator=(const Polynomial & rhs);
	int mySize();
	friend double evaluate(const Polynomial& poly, double arg);
	friend Polynomial operator+ (const Polynomial& lhs, const Polynomial& rhs);
	friend Polynomial operator- (const Polynomial& lhs, const Polynomial& rhs);
	friend Polynomial operator* (const Polynomial& lhs, const Polynomial& rhs);
private:
	int size;
	double *coefficients;
};

int main() {
	Polynomial empty;
	double one[] = {1};
	Polynomial One(one,1);
	double quad[] = {3, 2, 1};
	double cubic[] = {1, 2, 0, 3};
	Polynomial q(quad,3);
	Polynomial c(cubic,4);
	Polynomial p = q;
	Polynomial r;
	r = q;
	r = c;

	cout << "Polynomial q" << endl;
	for(int i = 0; i < 3; i++) 
		cout << "term with degree " << i << " has coefficients " << q[i] << endl;
	cout << "Polynomial c" << endl;
	for(int i = 0; i < 4; i++) 
		cout << "term with degree " << i << " has coefficients " << c[i] << endl;
	cout << "value of q(2) is " << evaluate(q,2) << endl;
	cout << "value of p(2) is " << evaluate(p,2) << endl;
	cout << "value of r(2) is " << evaluate(r,2) << endl;
	cout << "value of c(2) is " << evaluate(c,2) << endl;

	r = q + c;
	cout << "value of (q + c)(2) is " << evaluate(r,2) << endl;
	r = q - c;
	cout << "value of (q - c)(2) is " << evaluate(r,2) << endl;
	r = q * c;
	cout << "size of (q * c) is " << r.mySize() << endl;
	cout << "Polynomial r = (q * c) " << endl;

	for (int i = 0; i < r.mySize(); i++)
		cout << "term with degree " << i << " has coefficient " << r[i] << endl;
	cout << "value of (q * c)(2) is " << evaluate(r,2) << endl;
	return 0;
}

int Polynomial::mySize()
{
	return size;
}

Polynomial::Polynomial() : coefficients(0), size(0) {

}
const Polynomial& Polynomial::operator=(const Polynomial & rhs)
{
	if(rhs.coefficients == coefficients)
		return rhs;
	else {
		delete [] coefficients;
		coefficients = new double[rhs.size];
		for (int i = 0; i < rhs.size; i++)
		 coefficients[i] = rhs.coefficients[i];
		size = rhs.size;
		return rhs;
	}
}
Polynomial::Polynomial(const Polynomial& rhs) :size(rhs.size)
{
	coefficients = new double[rhs.size];
	for(int i = 0; i < rhs.size; i++)
		coefficients[i] = rhs.coefficients[i];
}
Polynomial::Polynomial(double coefficient[], int newsize) :size(newsize)
{
	coefficients = new double[size];
	for(int i = 0; i < size; i++)
		coefficients[i] = coefficient[i];
}
Polynomial::~Polynomial()
{
	delete[] coefficients;
}
double& Polynomial::operator[] (int degree)
{
	return coefficients[degree];
}
const double& Polynomial::operator[] (int degree)const
{
	return coefficients[degree];
}
Polynomial operator+ (const Polynomial& lhs, const Polynomial& rhs)
{
	int newsize;
	if(lhs.size > rhs.size)
		newsize = lhs.size;
	else
		newsize = rhs.size;
	double *sum = new double[newsize];
	for (int i = 0; i < newsize; i++) 
		sum[i] = lhs.coefficients[i] + rhs.coefficients[i];
	return Polynomial(sum, newsize);
}
Polynomial operator- (const Polynomial& lhs, const Polynomial& rhs)
{
	int newsize;
	if(lhs.size > rhs.size)
		newsize = lhs.size;
	else
		newsize = rhs.size;
	double *sum = new double[newsize];
	for (int i = 0; i < newsize; i++) 
		sum[i] = lhs.coefficients[i] - rhs.coefficients[i];
	return Polynomial(sum, newsize);
}
Polynomial operator* (const Polynomial& lhs, const Polynomial& rhs)
{
	int newsize,k = 0;
	newsize = lhs.size + rhs.size;
	double *sum = new double[newsize];
	for(int i = 0; i < newsize; i++)
		sum[i] = 0;
	for (int i = 0; i < lhs.size; i++) {
		for (int j = 0; j < rhs.size; j++) {
			sum[i+j] += lhs[i] * rhs[j];
		}
	}
	return Polynomial(sum, newsize);
}
double evaluate(const Polynomial& poly, double arg)
{
	double val = 0;
	int i;
	for (i = poly.size - 1; i >= 0; i--)
	{
		val = poly[i] + arg * val;
	}
	return val;
}