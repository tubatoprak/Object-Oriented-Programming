#include <iostream>
#include <cstring>

void reverseArray(char array[],int first,int end);

void iterativeArray(int length,char array[])
{
	reverseArray(array,0,length-1);
}

int main()
{
	using namespace std;  
	char array[5];
	int length = strlen(array)-1;
	
	for (int i = 0; i < length; i++)
	{
		array[i] = 'A' + i;
		if(i == length-1)
			array[i]='\0';
	}


	cout << "\nArray Contents------------------New Array Contents"<<endl;
	for (int i = 0; i < 5; i++)
	{
		cout << array[i] << " ";
	}	
	
	iterativeArray(length,array); 
	cout<<"     ------------------";
	for (int i = 0; i < 5; i++)
	{
		cout <<array[i]<< " ";
	}
	cout<<endl;
	return 0;
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