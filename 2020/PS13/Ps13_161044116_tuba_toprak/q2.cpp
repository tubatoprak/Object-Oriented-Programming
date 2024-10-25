#include <iostream>
using namespace std;

class NegativeDeposit{};
class InsufficientFunds{};

class Account
{
	public:
		Account();
		Account(double initialDeposit);
		double getBalance();
		double deposit(double amount)throw (NegativeDeposit);
		double withdraw(double amount) throw (InsufficientFunds);
	private:
 		double balance;
};
 	Account::Account()
 	{
 		balance = 0;
 	}
 	
 	Account::Account(double initialDeposit)
 	{
 		balance = initialDeposit;
 	}
 	
 	double Account::getBalance()
 	{
 		return balance;
 	}
 	

 	double Account::deposit(double amount) throw (NegativeDeposit)
 	{
 	if (amount > 0)
 		balance += amount;
 	else
 		throw NegativeDeposit();
 	return balance;
 	}
 	

 	double Account::withdraw(double amount) throw (InsufficientFunds)
 	{
	if((amount > balance) || (amount < 0))
		throw InsufficientFunds();
	else 
		balance -= amount;
	return balance;
 	}
int main()
{
	Account money1(50);
	cout<<"Balance : 50"<<"$ "<<endl;
	try
	{
		cout << "Depositing 50" <<"$ "<< endl;
		cout << "New balance: " << money1.deposit(50) <<"$ "<< endl;
		cout << "Withdraw 10" << endl;
		cout << "New balance: " << money1.withdraw(10)<<"$ "<< endl;
		cout << "Withdraw 1000" << endl;
		cout << "New balance: " << money1.withdraw(1000) <<"$ "<< endl;
	}
	catch (InsufficientFunds)
	{
		cout << "NOT ENOUGH MONEY!!" << endl;
	}
	catch (NegativeDeposit)
	{
		cout << "THE DEPOSIT SHOULD BE  IN A POSITIVE AMOUNT" <<endl <<endl;
	}
	cout<<"-------------------------------"<<endl;
	Account money2(50);
	cout<<"Balance : 50"<<"$ "<<endl;
	try
	{
		cout << "Depositing 50" <<"$ "<< endl;
		cout << "New balance: " << money2.deposit(50) <<"$ "<< endl;
		cout << "Withdraw 10" << endl;
		cout << "New balance: " << money2.withdraw(10)<<"$ "<< endl;
			cout << "Depositing -1000" <<"$ "<< endl;
		cout << "New balance: " << money2.deposit(-1000) <<"$ "<< endl;
	}
	catch (InsufficientFunds)
	{
		cout << "NOT ENOUGH MONEY!!" << endl;
	}
	catch (NegativeDeposit)
	{
		cout << "THE DEPOSIT SHOULD BE  IN A POSITIVE AMOUNT" << endl;
	}


	return 0;
}