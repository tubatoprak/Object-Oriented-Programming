#include <iostream>

using namespace std;  

void reverseArray(char array[], int first, int end);


int main()
{ 

	char array[5];
	
	for (int i = 0; i < 5; i++)
	{
		array[i] = 'A' + i;
	}
	
	cout << "Array Contents"<<endl;
	for (int i = 0; i < 5; i++)
	{
		cout << array[i] << " ";
	}
	
	cout << endl;
	reverseArray(array, 1, 4);

	cout << "New Array Contents"<<endl;
	for (int i = 0; i < 5; i++)
	{
		cout << array[i] << " ";
	}
}
void reverseArray(char array[], int first, int end)
{ 
	if (first >= end)
		return;
	if (first + 1 == end)
	{
		char temp;
		temp = array[first];
		array[first] = array[end];
		array[end] = temp;
		return;
	}      
	char temp = array[first];
	array[first] = array[end];
	array[end] = temp;
	reverseArray( array, first + 1, end - 1);
}