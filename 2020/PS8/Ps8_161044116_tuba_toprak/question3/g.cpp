#include <iostream>
#include<cstdlib>
#include <cctype>
#include "g.h"
using std::cout;
using std::cin;

namespace A
{
	void g()
	{
		int a,b;
		cout << "enter a number for star  in g(): ";
		cin >> a;
		cout <<"g() of namespace A is called \n";
		for (int i = 0; i < a; ++i)
		{
			cout <<"* ";
		}
		cout<<"\n";
	}
}