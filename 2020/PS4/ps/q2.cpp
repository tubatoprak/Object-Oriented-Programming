#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
int main()
{

	int i; 
	int flag;
	int number;
	cout << "Enter the number of suitors: ";
	cin >> number;
	vector<int> suitors(number);
	
	for (int i=0; i<number; i++)
	{
		suitors[i] = i+1;
	}
	if (number <=0)
	{
		cout << "The princess stayed at home.." << endl;
	}
	else if (number == 1)
	{
		cout << "To win the princess : "<<suitors[0] << endl;;
	}
	else
	{
		flag = 0; 
		while (suitors.size() > 1)
		{
			for (i=0; i<2; i++)
			{
				flag++;
				if (flag == suitors.size())
				{
					flag=0;
				}
			}
			suitors.erase(suitors.begin() + flag);
			
			if (flag == suitors.size())
			{
				flag=0;
			}
		}
		cout << "To win the princess : "<<suitors[0] << endl;;
	}
	return 0;
}