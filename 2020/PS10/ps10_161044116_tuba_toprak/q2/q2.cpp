#include <iostream>
#include <string>
using namespace std;
//I learned from internet
class Payment
{
	private:
		float amountOfPayment;

	public:
		Payment();
		Payment(float amount);
		float getAmountOfPayment();
		void setAmountOfPayment(float pAmountOfPayment);
		void paymentDetails();
};
Payment::Payment()
{
	amountOfPayment = 0;
}

Payment::Payment(float pAmountOfPayment)
{
	amountOfPayment = pAmountOfPayment;

}

float Payment::getAmountOfPayment()
{
	return amountOfPayment;
}

void Payment::setAmountOfPayment(float pAmountOfPayment)
{
	amountOfPayment = pAmountOfPayment;
}

void Payment::paymentDetails()
{
	cout << "Amount of payment: $" << amountOfPayment << endl;
}

class CreditCardPayment : public Payment
{
	private:
		string nameCard;
		string expirationDate;
		string numberOfCard;

	public:
		CreditCardPayment();
		CreditCardPayment(float ccpAmountOfPayment, string ccpNameOnCard, 
			string ccpExpirationDate, string ccpCardNumber);
		void paymentDetails();
};
CreditCardPayment::CreditCardPayment() 
{
	Payment();
	nameCard = "";
	expirationDate ="";
	numberOfCard= "";
}

CreditCardPayment::CreditCardPayment(float ccpAmountOfPayment,string ccpNameOnCard, string ccpExpirationDate, 
	string ccpCardNumber):Payment(ccpAmountOfPayment)
{
	expirationDate = ccpExpirationDate;
	nameCard = ccpNameOnCard;
	numberOfCard = ccpCardNumber;
}

void CreditCardPayment::paymentDetails()
{
	cout<<"Amount of credit card payment: $"<<getAmountOfPayment()<<endl;
	cout<<"Name on the credit card: "<<nameCard<<endl;
	cout<<"Expiration date: "<<expirationDate<<endl;
	cout<<"Credit card number: "<<numberOfCard<<endl;	
}
class CashPayment:public Payment
{
	public:
		CashPayment();
		CashPayment(float cpAmountOfPayment);
		void paymentDetails();
};
CashPayment::CashPayment()
{
	Payment();
}

CashPayment::CashPayment(float cpAmountOfPayment):Payment(cpAmountOfPayment)
{
}

void CashPayment::paymentDetails()
{
	cout << "Amount of cash payment: $" << getAmountOfPayment() << endl;
}

int main()
{
	CashPayment cash1(15.65);
	cout <<endl<<"-----cashPayment1(15.65)------"<<endl;
	cash1.paymentDetails();

	CashPayment cash2(48.25);
	cout <<endl<<"-----cashPayment2(48.25)------"<<endl;
	cash2.paymentDetails();
	
	
	CreditCardPayment credicart1(15.65, "Tuba", "11/11/2020", "123456789");
	cout <<endl<<"-----CreditCardPayment1(15.65)-----"<<endl;
	credicart1.paymentDetails();

	CreditCardPayment credicart2(48.25, "Merve", "18/12/2021", "987654321");
	cout <<endl<<"-----CreditCardPayment2(48.25)-----"<<endl;
	credicart2.paymentDetails();
		
	return 0;
}