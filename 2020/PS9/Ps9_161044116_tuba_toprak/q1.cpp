#include <iostream>
#include <cmath>

using namespace std;

int Fibo( int n )
{  
	if (n == 0 || n == 1)   
		return n; 
	return Fibo( n - 1 ) + Fibo( n - 2 );
}
 
int main()
{  
	char ans;  
	int number;  
	cout<<"Enter number for Fibonacci: ";
	cin>>number;
	cout<<Fibo(number);
	cout<<endl;
}