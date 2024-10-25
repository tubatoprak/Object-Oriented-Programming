#include <iostream>
#include <cstdlib>

using namespace std;

class Rational{
private:
    int num; 
    int denominator;   
    friend ostream& operator <<(ostream& outs, const Rational& ratinl);
    friend istream& operator >>(istream& ins, Rational& ratinl);

public:
    Rational(); 
    Rational (int wholeNumber); 
    Rational (int m, int n); 
    
    int getNum()const{return num;}
    int getDenom()const{return denominator;}
    
    void setNum(const int n)
    {
        num = n;
    }
    void setDenom(const int den)
    {
        denominator = den;
    }
    void check();
    Rational operator+(const Rational& ratinl)const;
    Rational operator-(const Rational& ratinl)const;
    Rational operator*(const Rational& ratinl)const;
    Rational operator/(const Rational& ratinl)const;
    bool operator==(const Rational& ratinl);
    bool operator>=(const Rational& ratinl);
    bool operator<=(const Rational& ratinl);
    bool operator>(const Rational& ratinl);
    bool operator<(const Rational& ratinl);
   
};

Rational::Rational()
{
   num = 0;
   denominator = 1;
}

Rational::Rational (int wholeNumber):denominator(1){
    num = wholeNumber;
}


Rational::Rational (int n, int d)
{
	num = n;
	denominator = d;
}


void Rational::check() 
{
    if (denominator < 0)
    {
		denominator = denominator*(-1);
		num = num*(-1);

    }
    else if (denominator == 0)
    { 
        cout << "Denominator cannot be zero!!" << endl;
        exit(1);
    }
}

ostream& operator <<(ostream& output, const Rational& ratinl) {	

	if (ratinl.denominator < 0)  
		output << (-1)*(ratinl.num) << "/" << (-1)*(ratinl.denominator); 
     
    else
		output << ratinl.num << "/" << ratinl.denominator;

	return output;
}

istream& operator >>(istream& input, Rational& ratinl) {

	char temp; 
	input >> ratinl.num >> temp >> ratinl.denominator;
	ratinl.check();
	return input;

}


bool Rational::operator==(const Rational& ratinl){
    return (num == ratinl.num && denominator == ratinl.denominator);
}

bool Rational::operator>=(const Rational& ratinl){
    return (num*ratinl.denominator >= denominator*ratinl.num);
}


bool Rational::operator<=(const Rational& ratinl){
    return (num*ratinl.denominator <= denominator*ratinl.num);
}

bool Rational::operator>(const Rational& ratinl){
    return (num*ratinl.denominator > denominator*ratinl.num);
}

bool Rational::operator<(const Rational& ratinl){
    return (num*ratinl.denominator < denominator*ratinl.num);
}

Rational Rational::operator*(const Rational& ratinl)const{
    Rational r;
    r.num = num*ratinl.num;
    r.denominator = denominator*ratinl.denominator;
    return r;
}

Rational Rational::operator/(const Rational& ratinl)const{
    Rational r;
    r.num = num*ratinl.denominator;
    r.denominator = denominator*ratinl.num;
    return r;
}

Rational Rational::operator+(const Rational& ratinl)const{
    Rational rat;
    rat.num = num*ratinl.denominator + ratinl.num*denominator;
    rat.denominator = denominator* ratinl.denominator;
    return rat;    
}

Rational Rational::operator-(const Rational& ratinl)const{
    Rational rat;
    rat.num = num*ratinl.denominator - ratinl.num*denominator;
    rat.denominator = denominator* ratinl.denominator;
    return rat;    
}

int main (){
    int n, d;        
    Rational rat1,rat2,rat3,rat4;

        cout << "Enter 4 rational numbers (n/d)): ";
        cin >> rat1 >> rat2 >> rat3 >> rat4;
        cout << endl;
        cout<<endl;
        cout << "OPERATOR OVERLOADING TEST" << endl;
        cout << " " << rat1 << " + " << rat2 << " = " << (rat1 + rat2) << endl;
        cout << " " << rat3 << " - " << rat4 << " = " << (rat3 - rat4) << endl; 
        cout << " " << rat1 << " / " << rat3 << " = " << (rat1 / rat3) << endl;
        cout << " " << rat3 << " * " << rat4 << " = " << (rat3 * rat4) << endl;
        cout << endl;

        cout <<"rational3 > rational4 " << " :" << (rat3 > rat1) << endl;
        cout <<"rational3 >= rational2 " <<" :" << (rat4 >= rat3) << endl;
        cout <<"rational2 == rational4 " <<" :" << (rat2 == rat4) << endl;
        cout <<"rational1 <= rational4 " <<" :" << (rat2 <= rat4) << endl;
        cout <<"rational1 < rational3 " << " :" << (rat1 < rat2) << endl;
        

    return 0; 
}