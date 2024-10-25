#include <iostream>

using namespace std;

template <typename T>

T absCalculate(T number1,T number2 )
{
	if (number1 > number2)
	{
		return (number1 - number2);
	}
	else
	{
		return (number2 - number1);
	}
}
int main(int argc, char const *argv[])
{
	int i1 = 5;
	int i2 = 10;
	double d1 = 3.2;
	double d2 = 7.5;

	cout<<"welcome absolute value calculator "<<endl;
	cout<<"for integer number1 = 5 and number2 = 10 ";
	cout<<"----->Result: "<<absCalculate(5,10)<<endl;
	cout<<"for double number1 = 3.2 and number2 = 7.5 ";
	cout<<"----->Result: "<<absCalculate(3.2,7.5)<<endl;
	return 0;
}
