


//I got the sources from the videos my teacher uploaded to moodle.


#include <iostream>
using namespace std;

class PrimeNumber
{
private:
	int number;
	bool isPrime(int number);
public:
	PrimeNumber();
	PrimeNumber(int value);
	int get();
	const PrimeNumber operator ++(int);
	const PrimeNumber operator --(int);
};
PrimeNumber::PrimeNumber()
{
	number = 1;
}
PrimeNumber::PrimeNumber(int value) 
{
	number = value;
}
int PrimeNumber::get()
{
	return number;
}
bool PrimeNumber::isPrime(int number)
{
	for (int i = number-1; i > 1; i--)
	{
		if ((number % i) == 0)
			return false;
	}
	return true;
}
const PrimeNumber PrimeNumber::operator ++(int)
{
	int nextprime = number;
	do
	{
		nextprime++;
	}while (!isPrime(nextprime));
	return PrimeNumber(nextprime);
}
const PrimeNumber PrimeNumber::operator --(int)
{
	int previousprime = number;
	do
	{
		previousprime--;
		if (previousprime < 1)
		{
			return PrimeNumber(1);
		}
	}while(!isPrime(previousprime));
	return PrimeNumber(previousprime);
}
int main()
{
	PrimeNumber p1, p2(13);
	cout<<"p1: "<<p1.get()<<endl;
	cout<<"p2: "<<p2.get()<<endl;
	
	PrimeNumber p3 = p1++;
	cout<<"p1++ : "<<p3.get()<<endl;
	
	PrimeNumber p4 = p2++;
	cout<<"p2++: "<<p4.get()<<endl;
	
	PrimeNumber p5 = p2--;
	
	cout<<"p2--: "<<p5.get()<<endl;
	
	return 0;
}