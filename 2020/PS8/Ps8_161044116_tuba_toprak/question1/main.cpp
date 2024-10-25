#include <iostream>
#include <string>
#include "user.h"
#include "administrator.h"
using namespace std;

int main()
{

	User user1("abbott","monday");
	User user2("tuba","123");
	User user3("costello","tuesday");
	
	Administrator admin1("abbott","monday");
	Administrator admin2("tuba","123");
	Administrator admin3("costello","tuesday");

	cout<<"*User Login*"<<endl;
	cout << "tuba: " << user2.Login() << endl;
	cout << "abbott: " << user1.Login() << endl;
	cout << "costello: " << user3.Login() << endl<<endl;
	
	cout<<"*Administrator login*"<<endl;
	cout << "tuba: " << admin2.Login() << endl;
	cout << "abbott: " << admin1.Login() << endl;
	cout << "costello: " << admin3.Login() << endl;
	return 0;
}