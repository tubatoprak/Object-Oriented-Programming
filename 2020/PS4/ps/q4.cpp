#include <iostream> 
using namespace std; 

const int SMALL = 1; 
const int MEDIUM = 2; 
const int LARGE = 3; 

const int DEEPDISH = 1; 
const int HANDTOSSED = 2; 
const int PAN = 3; 


 
class Pizza 
{ 
private: 
	int type; 
	int size; 
	int topping;
	 
public: 
	Pizza();
	void setType(int choice); 
	void setSize(int choice);
	void setTopping(int toppingg); 
	
	int getType(); 
	int getSize();  

	void outputDescription(); 
	double computePrice(); 
}; 
 
Pizza::Pizza() 
{ 
	type = PAN; 
	size = SMALL; 
	topping = 0;
} 
 
int Pizza::getType() 
{ 
	return type; 
} 
 
int Pizza::getSize() 
{ 
	return size; 
} 
 
void Pizza::setType(int choice) 
{ 
	type = choice; 
} 
 
void Pizza::setSize(int choice) 
{ 
	size = choice; 
} 
void Pizza::setTopping(int toppingg)
{
	topping = toppingg;
}
void Pizza::outputDescription() 
{ 
	cout<< "Your pizza: ";
	switch (size) 
	{ 
		case SMALL: 
			cout << "Small ";
		break;
		case MEDIUM: 
			cout << "Medium ";
		break;
		case LARGE: 
			cout << "Large ";
		break;
		default:
			cout << "Unknown sized ";
	} 
	 
	switch (type) 
	{ 
		case DEEPDISH: 
			cout << "deepdish ";
		break; 
		case HANDTOSSED: 
			cout << "hand tossed "; 
		break; 
		case PAN: 
			cout << "pan "; 
		break; 
		default: 
			cout << "wrong choice.. "; 
	} 
	 
	cout << "pizza"; 
} 
 
double Pizza::computePrice() 
{ 
	double cost = 0.0;

	switch (size) 
	{ 
		case SMALL: 
			cost += 10;
		break; 
		case MEDIUM: 
			cost += 14;
		break; 
		case LARGE: 
			cost += 17;
		break; 
	} 
	cost += topping * 2.0;
	return cost; 
} 
 
int main() 
{ 
 
	Pizza customer;
	char choice_type,choice_size;
	int topping; 
	int type = 0;
	int size = 0; 
	 
	cout << "What size pizza would you like (S/M/L): "; 
	cin >>choice_size; 
	 
	switch (choice_size) 
	{ 
		case 'S':
			size = SMALL; 
		break; 
		case 'M': 
			size = MEDIUM; 
		break; 
		case 'L':
	 		size = LARGE; 
	 	break; 
	} 
 
	cout <<"What type pizza would you like (D/H/P): "; 
	cin >>choice_type;
	switch (choice_type) 
	{ 
		case 'D':
			type = DEEPDISH; 
		break; 
		case 'H': 
			type = HANDTOSSED; 
		break; 
		case 'P': 
	  		type = PAN; 
	  	break; 
	}
 
	 
	customer.setSize(size); 
	customer.setType(type); 
 
	cout << "how many  would you like pepperoni or cheese toppings  ? "; 
	cin >> topping;
	customer.setTopping(topping); 
	customer.outputDescription(); 
	cout << endl; 
 
	cout << "Price: $" << customer.computePrice() << endl; 
 
 
return 0; 
} 