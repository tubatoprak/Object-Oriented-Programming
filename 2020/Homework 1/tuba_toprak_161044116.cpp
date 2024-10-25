#include <iostream>
#include <string.h>
#include <stdlib.h> 
#include <time.h>
using namespace std;

bool iss_digit(string argv2); ////Checks whether the expression entered is a number

int find_digit_number(int number); //to learn the number of digits of the number entered by the user.

void create_random_number(int digit,int secret_number[10]); //to generate a random number

void divide_user_number(int number,int digit,int user_number[10]);//The number entered by the user is divided into digits and stored in the array.

bool finish_control(int digit,int user_number[10],int secret_number[10]);//checks if the game is over.

void control_game(int digit,int user_number[10],int secret_number[10],int exact_and_misplaced[10]);

bool edit_secret_number_unique(int digit_number,int user_number[10]);//for -u,Checks whether the digits of the number are different.


int main(int argc, char const *argv[])
{
	if(argc == 3) //if the user doesn't enter 3 arguments, the user should get an error (E0)
	{
		string argv2 = argv[2]; //Stores to process with the number in argv [2].
		
		if(argv2[0]=='0') // Checks whether the first digit of the number entered as  argument is 0.
		{
			cout<<"E0"<<endl; 
			return 0;
		}

		if(!iss_digit(argv2)) //Checks whether the expression entered as an argument is a number
		{
			cout<<"E0";
			return 0;
		}
		srand(time(0));
		int entered = stoi(argv2);//Stores to process with the number in argv [2].
		int digit = 0; // for digit number
		int number = 0; //the number entered by the user.
		int secret_number[10]; //given or random secret number.
		int user_number[10]; //it stores the number entered by the user. there is a digit number in each cell.
		int exact_and_misplaced[2]={0,0}; //It stores the correct digit number in cell number zero and It stores the misplaced digit number in cell number one.
		int count = 0;//turn  number
		
		if(strcmp(argv[1], "-r") == 0) //for the first of two options so for -r
		{
			digit = entered;
			if(digit < 1 || digit > 9 ) /*checks if the number is in range. if the number 
											is not in range it will get an error*/
			{
				cout <<"E0"<<endl;
				return 0;
			}
			else
			{
				create_random_number(digit,secret_number); //Firstly ,The random number is determined 
				do{
				string str; //to users number 
				cin>>str;
				if(!iss_digit(str)) //Checks whether the expression entered is a number
				{
					cout<<"E2";
					return 0;
				}
				if(str[0]=='0') //checks whether the entered expression starts at 0
				{
					cout<<"E1";
					return 0;
				}
				
				number = stoi(str);//So far, if the expression is true, it makes the expression integer.
				if(digit != find_digit_number(number)) //the numbers entered by the user are checked.
				{
					cout<<"E1";
					return 0;
				}
				divide_user_number(number,digit,user_number);//stores the entered number in the array.
				count++;
				control_game(digit,user_number,secret_number,exact_and_misplaced);//Controls the game. Fills the exact_and_misplaced[].
				if(!finish_control(digit,user_number,secret_number)) /*if the game is over, 
																		to avoid showing the results table*/
				{
					for (int i = 0; i < 2; ++i)  // to see exact number and misplaced number
					{
						cout<<exact_and_misplaced[i]<<" ";
					}
					cout<<endl;
				}
				}while(!finish_control(digit,user_number,secret_number));
				if(count == 100)
					cout<<"FAILED. ";
				else
					cout<<"FOUND "<<count<<endl;;
			}
		}
		else if (strcmp(argv[1], "-u") == 0)  //for the second of two options so for -u
		{
			digit = find_digit_number(entered);/*finds the number of digits of the entered 
																number and stores it in the digit*/
			divide_user_number(entered,digit,secret_number); //divides and stores the secret number
			if(!edit_secret_number_unique(digit,secret_number))//checks whether the secret number is unique.
			{
				cout<<"E0"<<endl;
				return 0;
			}
			do{    //and the game cycle begins. The game continues until you find the correct number.
				string str; //to users number 
				cin>>str;
				if(!iss_digit(str)) //Checks whether the expression entered is a number
				{
					cout<<"E2";
					return 0;
				}
				if(str[0]=='0') //checks whether the entered expression starts at 0
				{
					cout<<"E1";
					return 0;
				}
				number = stoi(str); //So far, if the expression is true, it makes the expression integer.
				if(digit != find_digit_number(number))//checks the number of digits of the entered number.
				{
					cout<<"E1";
					return 0;
				}
				divide_user_number(number,digit,user_number);//divides and stores the secret number
				count++;
				control_game(digit,user_number,secret_number,exact_and_misplaced);//Controls the game. Fills the exact_and_misplaced[].
				if(!finish_control(digit,user_number,secret_number))/*if the game is over, 
																		to avoid showing the results table*/
				{
					for (int i = 0; i < 2; ++i) // to see exactnumber and misplaced
					{
						cout<<exact_and_misplaced[i]<<" ";
					}
					cout<<endl;
				}
			}while(!finish_control(digit,user_number,secret_number));//check the game over.
			if(count == 100) // 100 kere denenmişse hata alır.
				cout<<"FAILED. ";
			else
				cout<<"FOUND "<<count<<endl;
		}
		else	//
		{
			cout<<"E0"<<endl; // if users not entered -r or -u,the user should get an error (E0)
		}
	}
	else		
	{
		cout<<"E0"<<endl; //if the user doesn't enter 3 arguments, the user should get an error (E0)
	}
	return 0;
}
int find_digit_number(int number)//find digit number and return digit number.
{
	int digit = 0;
	while(number > 0)
	{
		digit++;
		number/=10;
	}
	return digit;
}
void create_random_number(int digit,int secret_number[10]) 
										//for create secret number.and store in  secret_number array.
{
	for (int i = 0; i < digit; ++i) 	
	{
		if(i == 0) 
		{
			secret_number[i] =  rand() % 9 + 1; //so that the first number is not zero
		}
		else
		{	
			int temp = rand() % 9;	
			for(int j = 0; j < i ;j++)  /*checks the same numbers in the array. 
											if it is the same, changes the number.*/
			{
				while(temp == secret_number[j])
				{
					temp = rand() % 9;
					j = 0;
				}
				
			}
			secret_number[i] = temp;
		}
	}
}
void divide_user_number(int number,int digit,int user_number[10])
{					      //It divides the integer number entered by the user and stores it in the array.		
	int temp_secret_number[10];
	int i = 0, j = 0;
	while(number > 0) //to separate numbers
	{
		temp_secret_number[i] =number %10;
		i++;
		number =number/10;
	}
	for (i = digit-1 ; i >= 0; --i) // to store
	{
		user_number[j] = temp_secret_number[i];
		j++;
	}
}
bool finish_control(int digit,int user_number[10],int secret_number[10])
{			                          //Returns true if secret number and user number are the same
	for (int i = 0; i < digit; ++i)
	{
		if(user_number[i] != secret_number[i])
			return false;
	}
	return true;
}
void control_game(int digit,int user_number[10],int secret_number[10],int exact_and_misplaced[10])
{
 	int temp;
	exact_and_misplaced[0]= 0; //to reset the array in each turn
	exact_and_misplaced[1]= 0;
	
	for (int i = 0; i < digit; ++i)
	{
		if(user_number[i] == secret_number[i])
			exact_and_misplaced[0] += 1;
		else 
		{
			temp = user_number[i];
			for (int i = 0; i < digit; ++i)
			{
				if(temp == secret_number[i])
					exact_and_misplaced[1] +=1;				
			}	
		}
	}
} 
bool edit_secret_number_unique(int digit_number,int secret_number[10])
														//checks whether the secret number is unique.
{
	for (int i = 0; i < digit_number; ++i)
	{
		for (int j = i+1 ;j < digit_number; ++j)
		{
			if(secret_number[i] == secret_number[j])
				return false;
		}
	}
	return true;
}
bool iss_digit(string argv2) //Checks whether the expression entered is a number
{
	for (int i=0; i<argv2.length(); i++)
    {
        if (!isdigit(argv2[i]))
            	return false;
    }
    return true;
}