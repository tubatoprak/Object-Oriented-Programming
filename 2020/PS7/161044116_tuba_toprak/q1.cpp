#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;
int main()
{
	char str[100];
	char *head = NULL;
	char *tail = NULL;
	cout<<"Enter your string: ";
	cin.getline(str,100);
	head = str;
	int length = strlen(str);
	tail = &str[length-1];
	char temp;
	while (head < tail)
	{
		temp = *head;
		*head = *tail;
		*tail = temp;
		head++;
		tail--;
	}
	cout<<"New String: "<<str<<endl;
	return 0;
}