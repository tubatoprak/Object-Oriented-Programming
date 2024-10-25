#include <iostream>
#include <string>
 
using namespace std;

class Person
{
public:
	Person();
	Person(string thename);
	Person(const Person& theObject);
	string getName() const;
	Person& operator = (const Person& rtSide);
	friend istream& operator>>(istream& inStream,	Person& personObject);
	friend ostream& operator<<(ostream& outStream,	const Person& personObject);

private:
	string name;
};
Person::Person() 
{
	name = "";
}

Person::Person(string thename)
{
	this->name = thename;
}

Person::Person(const Person& theObject)
{
	name = theObject.name;
}
	
string Person::getName() const
{
	return name;
}

Person& Person::operator = (const Person& rtSide)
{
	this->name = rtSide.name;
	return *this;
}

istream& operator >> (istream& inStream, Person& personObject)
{
	inStream >> personObject.name;
	return inStream;
}

ostream& operator<<(ostream& outStream, const Person& personObject)
{
	outStream << personObject.name;
	return outStream;
}

class Vehicle 
{
public:
	Vehicle();
	Vehicle(const string& newManufacturerName, int newNumberOfCylinders,const Person& newOwner);
 	Vehicle(const Vehicle& otherObject);
	Vehicle& operator=(const Vehicle& otherObject);
	string getManufacturerName();
	int getNumberOfCylinders();
	Person getOwner();
	void setManufacturerName(const string& newManufacturerName);
	void setNumberOfCylinders(int newNumberOfCylinders);
	void setOwner(const Person& newOwner);
	void print();

private:
	string manufacturerName;
	int numberOfCylinders;
	Person owner;
};

Vehicle::Vehicle() 
{
	manufacturerName = "";
	numberOfCylinders = 0;     
    owner = Person();
}

Vehicle::Vehicle(const string& newManufacturerName, int newNumberOfCylinders, const Person& newOwner)
{
	manufacturerName = newManufacturerName;
	numberOfCylinders = newNumberOfCylinders;     
    owner = newOwner;
}

Vehicle::Vehicle(const Vehicle& otherObject)
{
	manufacturerName = otherObject.manufacturerName;
	numberOfCylinders = otherObject.numberOfCylinders;     
    owner = otherObject.owner;
}

string Vehicle::getManufacturerName()
{
	return manufacturerName;
}

int Vehicle::getNumberOfCylinders()
{
	return numberOfCylinders;
}

Person Vehicle::getOwner()
{
	return owner;
}

void Vehicle::setManufacturerName(const string& newManufacturerName)
{
	manufacturerName = newManufacturerName;
}

void Vehicle::setNumberOfCylinders(int newNumberOfCylinders)
{
	numberOfCylinders = newNumberOfCylinders;
}

void Vehicle::setOwner(const Person& newOwner)
{
	owner = newOwner;
}

Vehicle& Vehicle::operator=(const Vehicle& otherObject)
{
	manufacturerName = otherObject.manufacturerName;
	numberOfCylinders = otherObject.numberOfCylinders;
	owner = otherObject.owner;

	return *this;
}

void Vehicle::print()
{
	cout << "Owner: " << owner << endl;
	cout << "Manufacturer's name: " << manufacturerName << endl;
	cout << "Number of cylinders in the engine: " << numberOfCylinders << endl;	
}

class Truck : public Vehicle 
{
public:
	Truck();
	Truck(string newManufacturerName, int newNumberOfCylinders, const Person& newOwner, double newLoadCapacity, int newTowingCapacity);
	Truck(const Truck& otherObject);
	Truck& operator =(const Truck& otherObject);
	
	double getLoadCapacity();
	int getTowingCapacity();
	
	void setLoadCapacity(double newLoadCapacity);
	void setTowingCapacity(int newTowingCapacity);
	
	void print();

private:
	int towingCapacity;
	double loadCapacity;
	
};
Truck::Truck() : Vehicle()
{

}

Truck::Truck(string newManufacturerName, int newNumberOfCylinders, const Person& newOwner, double newLoadCapacity, int newTowingCapacity)
	: Vehicle(newManufacturerName, newNumberOfCylinders, newOwner)
{
	loadCapacity = newLoadCapacity;
	towingCapacity = newTowingCapacity;
}

Truck::Truck(const Truck& otherObject) : Vehicle(otherObject)
{
	loadCapacity = otherObject.loadCapacity;
	towingCapacity = otherObject.towingCapacity;
}

Truck& Truck::operator =(const Truck& otherObject)
{
	Vehicle:: operator =(otherObject);
	
	loadCapacity = otherObject.loadCapacity;
	towingCapacity = otherObject.towingCapacity;

	return *this;
}

double Truck::getLoadCapacity()
{
	return loadCapacity;
}

int Truck::getTowingCapacity()
{
	return towingCapacity;
}

void Truck::setLoadCapacity(double newLoadCapacity)
{
	loadCapacity = newLoadCapacity;
}

void Truck::setTowingCapacity(int newTowingCapacity)
{
	towingCapacity = newTowingCapacity;
}

void Truck::print()
{
	Vehicle::print();
	cout << "Load capacity in tons: " << loadCapacity << endl;
	cout << "Towing capacity in pounds: " << towingCapacity << endl;
}

int main()
{
	cout<<" information of Truck 1 "<<endl;
	Person personone("Brad PITT");
	Truck truckone("TOPRAKLAR OTO", 4, personone, 30, 4000);
	truckone.print();
	
	cout<<endl<<"Truck2(truck 1)"<<endl;
	Truck trucktwo(truckone);
	trucktwo.print();
	
	cout<<endl<<" information of Truck 3 "<<endl;
	Person persontwo("Angelina JOLIE");
	Truck truckthird("TOPRAKLAR OTO", 6, persontwo, 20, 4000);
	truckthird.print();

	
	cout<<endl<<"Truck2 =  Truck3"<<endl;
	trucktwo = truckthird;
	trucktwo.print();


	
	return 0;
}