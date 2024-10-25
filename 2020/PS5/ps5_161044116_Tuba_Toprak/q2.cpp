#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;

class MyInteger
{ 
public:	
	MyInteger()
	{
		value = 0;
	} 
	MyInteger(int number)
	{
		value = number;
	} 
	void setInteger(const int val)
	{
		value = val;
	} 
	int getInteger()const
	{
		return value;
	}   
	int operator[](int index);

private:
	int value;
};

int MyInteger::operator[](int index)
{
	int temp;
	if(index < 0)
	{
		cout<<"illegal index value"<<endl;
	}
	else 
	{
		temp = (int )(value/(pow(10,index)));
		if(temp == 0)
		{
			return -1;
		}
		return temp %10;
	}	
}
             
int main()
{
	MyInteger number(123),number2(126778);

	cout << "TEST - 123" << endl;
	cout << "0 --> " << number[0] << endl;
	cout << "1 --> " << number[1] << endl;
	cout << "2 --> " << number[2] << endl;
	cout << "3 --> " << number[3] << endl;
	cout << endl;

	cout << "TEST - 1236778" << endl;
	cout << "0 --> " << number2[0] << endl;
	cout << "1 --> " << number2[1] << endl;
	cout << "2 --> " << number2[2] << endl;
	cout << "3 --> " << number2[3] << endl;
	cout << "4 --> " << number2[4] << endl;
	cout << "5 --> " << number2[5] << endl;
	cout << "6 --> " << number2[6] << endl;
	cout << endl;
	

	return 0;
}