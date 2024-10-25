#include <iostream> 
#include <cstdlib> 
#include <string> 
using namespace std; 

class Student 
{ 
public: 
	Student();
	~Student();
	void InputData();
	void OutputData();
	void ResetClasses();
	Student& operator =(const Student& object);

private:
	string name;
	int numberOfClasses;
	string *classList;
};

Student::Student()
{
	name = "";
	numberOfClasses = 0;
	classList = NULL;
}
  
Student::~Student()
{
	if (classList != NULL)
	{
		delete [] classList;
	}
}
void Student::ResetClasses()
{
	name = "";
	if (classList != NULL)
	{
		delete[] classList;
		classList = NULL;
		numberOfClasses = 0;
	}
}
  
void Student::InputData()
{ 
	ResetClasses();
	cout << "Enter student name: ";
	getline(cin, name);
	cout << "Enter number of classes: ";
	cin >> numberOfClasses;
	cin.ignore(2, '\n');
	
	if (numberOfClasses > 0)
	{
		classList = new string[numberOfClasses];
		for (int i = 0; i<numberOfClasses; i++)
		{
			cout << "Enter name of class " << (i + 1) << " : ";
			getline(cin, classList[i]);
		}
	}
	cout << endl;
}
void Student::OutputData()
{ 
	int i;
	cout << "Name: " << name << endl;
	cout << "Number of classes: " << numberOfClasses << endl;
	for (i = 0; i < numberOfClasses; i++)
	{
		cout <<"->"<<classList[i]<<endl;
	}
	cout << endl;
}

Student& Student::operator =(const Student& object)
{
	ResetClasses();
	name = object.name;
	numberOfClasses = object.numberOfClasses;
	if (numberOfClasses > 0)
	{
		classList = new string[numberOfClasses];
		for (int i = 0; i < numberOfClasses; i++)
		{
			classList[i] = object.classList[i];
		}
	}
	return *this;
}
int main() 
{ 
  
	Student student1, s2; 
	student1.InputData(); 
	cout<<"---Student 1---"<<endl;
	student1.OutputData(); 
	

	cout<<"Assigment operator (Student 2 = Student 1)"<<endl;
	cout<<"---Student 2---"<<endl;
	s2 = student1;
	s2.OutputData();
	
	cout<<"After reset "<<endl;
	cout<<"---Student 1---"<<endl;	
	student1.ResetClasses();  
	student1.OutputData(); 
	return(0);
}