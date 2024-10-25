#include <iostream>
#include <exception>
#include <string>

#include "gtuiteratorconst.cpp"
#include "gtucontainer.cpp"
#include "gtuiterator.cpp"
#include "gtuvector.cpp"
#include "gtuset.cpp"

#include "gtuiteratorconst.h"
#include "gtucontainer.h"
#include "gtuiterator.h"
#include "gtuvector.h"
#include "gtuset.h"


using namespace std;
using namespace hw6;

template<class T, class S>
S find (S begin, S end, const T& val)
{
  while (begin!= end) 
  {
    if (*begin == val)
    {
    	return begin;
    }
    ++begin;
  }
  return end;
}
bool evennumberfind_function_to_find_if(int i) 
{ 
    return i % 2 == 0; 
} 

template<class T, class S>
T find_if (T begin, T end, S function)
{
  while (begin!=end) 
  {
    if (function(*begin)) 
    	return begin;
    ++begin;
  }
  return end;
}
void print_s(string i)
{
	cout<< i<<" "<<endl;
}
void print(int i)
{
	cout<< i<<" ";
}

template<class T, class S>
S for_each(T first, T last, S fn)
{
  while (first!=last) 
  {
    fn (*first);
    ++first;
  }
  return fn; 
}
int main()
{
	cout <<endl<< "**************For Set (integer)****************"<<endl;
	GTUIterator<int> icount;
	GTUSet<int> Setint;

	cout<<"First size of set is: "<<Setint.size1()<<endl;
	cout<<"Insert(1,3,2,5,4,6,8,7)..."<<endl;
	try{
		Setint.insert(1);
		Setint.insert(3);
		Setint.insert(2);
		Setint.insert(5);
		Setint.insert(4);
		Setint.insert(6);
		Setint.insert(8);
		Setint.insert(7);
	}
	catch(invalid_argument error){
		cout<<"Invalid argument: "<<error.what()<<endl;
		exit(1);
	}
	for_each(Setint.begin(),Setint.end(),print);
	cout<<endl;
	cout<<"Size of  set is "<<Setint.size1()<<endl;
	cout<<"Erase (3,1,2).. ";
	Setint.erase(3);
	Setint.erase(1);
	Setint.erase(2);
	for_each(Setint.begin(),Setint.end(),print);
	cout<<endl;
	cout<<"Size of  set is "<<Setint.size1()<<endl;
	cout<<"Try Find Function (if there is not number in set,return 0) "<<endl;
	cout<<"Find 8 in set :";
	auto a = find(Setint.begin(),Setint.end(),8);
	cout<<*a<<endl;
	cout<<"Find 9 in set :";
	auto b = find(Setint.begin(),Setint.end(),9);
	cout<<*b<<endl;
	cout<<"Try Find_if Function "<<endl;
	cout<<"Find First even number: ";
	 a = find_if(Setint.begin(),Setint.end(),evennumberfind_function_to_find_if);
	cout<<*a<<endl;
	cout<<"Try Find_Each Function with print "<<endl;
	for_each(Setint.begin(),Setint.end(),print);
	cout<<endl<<"Set is cleaning.. "<<endl;
	Setint.clear();
	cout<<endl<<"Set is clean.."<<endl;
	if(Setint.empty())
		cout<<"Set is empty! "<<endl;
	else
		cout<<"Set is not empty!"<<endl;

	cout <<endl<< "**************For Set (String)****************"<<endl;
	
	GTUIterator<string> istring;
	GTUSet<string> setstring;

	cout<<"First size of set is: "<<setstring.size1()<<endl;
	cout<<"Insert..."<<endl;
	try{
		setstring.insert("rock and roll");
		setstring.insert("pop");
		setstring.insert("blues");
		setstring.insert("dance");
		setstring.insert("country");
		setstring.insert("jazz");
		setstring.insert("rhythm and blues");
		setstring.insert("hip-hop");
	}
	catch(invalid_argument error){
		cout<<"Invalid argument: "<<error.what()<<endl;
		exit(1);
	}
	for_each(setstring.begin(),setstring.end(),print_s);
	cout<<endl;
	cout<<"Size of  set is "<<setstring.size1()<<endl;
	cout<<"Erase(rhythm and blues ,country).  "<<endl;
	setstring.erase("rhythm and blues");
	setstring.erase("country");
	for_each(setstring.begin(),setstring.end(),print_s);
	cout<<endl;
	cout<<"Size of  set is "<<setstring.size1()<<endl;
	cout<<"Try find_each Function with print "<<endl;
	for_each(setstring.begin(),setstring.end(),print_s);
	cout<<endl<<"Set is cleaning.. "<<endl;
	setstring.clear();
	cout<<endl<<"Set is clean.."<<endl;
	if(setstring.empty())
		cout<<"Set is empty! "<<endl;
	else
		cout<<"Set is not empty!"<<endl;


cout <<endl<< "**************For Vector (integer)****************"<<endl;

	GTUIterator<int> ivector;
	GTUVector<int> vectorint;

	cout<<"First size of vector is: "<<vectorint.size1()<<endl;
	cout<<"Insert(1,3,2,5,4,6,8,7)..."<<endl;
	vectorint.insert(1);
	vectorint.insert(3);
	vectorint.insert(2);
	vectorint.insert(5);
	vectorint.insert(4);
	vectorint.insert(6);
	vectorint.insert(8);
	vectorint.insert(7);
	for_each(vectorint.begin(),vectorint.end(),print);
	cout<<endl;
	cout<<"Size of  vector is "<<vectorint.size1()<<endl;
	cout<<"Erase (3,1,2).. ";
	vectorint.erase(3);
	vectorint.erase(1);
	vectorint.erase(2);
	for_each(vectorint.begin(),vectorint.end(),print);
	cout<<endl;
	cout<<"Size of  vector is "<<vectorint.size1()<<endl;
	cout<<"Try Find Function (if there is not number in vector,return 0) "<<endl;
	cout<<"Find 5 in vector :";
	a = find(vectorint.begin(),vectorint.end(),5);
	cout<<*a<<endl;
	cout<<"Find 9 in vector :";
	b = find(vectorint.begin(),vectorint.end(),9);
	cout<<*b<<endl;
	cout<<"Try - Operator [] : "<<endl;
	cout<<"vector[3]: "<<vectorint[3]<<" "<<endl;
	cout<<"Try Find_if Function "<<endl;
	cout<<"Find First even number: ";
	 a = find_if(vectorint.begin(),vectorint.end(),evennumberfind_function_to_find_if);
	cout<<*a<<endl;
	cout<<"Try find_each Function with print "<<endl;
	for_each(vectorint.begin(),vectorint.end(),print);
	cout<<endl<<"vector is cleaning.. "<<endl;
	vectorint.clear();
	cout<<endl<<"vector is clean.."<<endl;
	if(vectorint.empty())
		cout<<"vector is empty! "<<endl;
	else
		cout<<"vector is not empty!"<<endl;

		cout <<endl<< "**************For vector (String)****************"<<endl;
	
	GTUIterator<string> vstring;
	GTUVector<string> vectorstring;

	cout<<"First size of vector is: "<<vectorstring.size1()<<endl;
	cout<<"Insert..."<<endl;
	try{
		vectorstring.insert("rock and roll");
		vectorstring.insert("pop");
		vectorstring.insert("blues");
		vectorstring.insert("dance");
		vectorstring.insert("country");
		vectorstring.insert("jazz");
		vectorstring.insert("rhythm and blues");
		vectorstring.insert("hip-hop");
	}
	catch(invalid_argument error){
		cout<<"Invalid argument: "<<error.what()<<endl;
		exit(1);
	}
	for_each(vectorstring.begin(),vectorstring.end(),print_s);
	cout<<endl;
	cout<<"Size of  vector is "<<vectorstring.size1()<<endl;
	cout<<"Erase(rhythm and blues ,country).  "<<endl;
	vectorstring.erase("rhythm and blues");
	vectorstring.erase("country");
	for_each(vectorstring.begin(),vectorstring.end(),print_s);
	cout<<endl;
	cout<<"Size of  vector is "<<vectorstring.size1()<<endl;
	cout<<"Try find_each Function with print "<<endl;
	for_each(vectorstring.begin(),vectorstring.end(),print_s);
	cout<<endl<<"Vector is cleaning.. "<<endl;
	vectorstring.clear();
	cout<<"vector is clean.."<<endl;
	if(vectorstring.empty())
		cout<<"Vector is empty! "<<endl;
	else
		cout<<"Vector is not empty!"<<endl;

	return 0;
}

