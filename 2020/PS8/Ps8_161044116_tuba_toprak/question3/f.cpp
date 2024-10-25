#include <iostream>
#include<cstdlib>
#include <cctype>
#include "f.h"

namespace A
{
	void f()
	{
		int a,b;
		using std::cout;
		using std::cin;
		cout << "enter a number for plus  in f(): ";
		cin >> a;
		
		cout <<"f() of namespace A is called \n";
		
		for (int i = 0; i < a; ++i)
		{
			cout <<"+ ";
		}
		cout<<"\n";
	}
}