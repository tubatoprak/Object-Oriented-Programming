#include <iostream>
#include <cstdlib>    //for time
#include <ctime>      //for time  
#include "human.h"
#include "elf.h"
#include "balrog.h"
#include "cyberdemon.h"

using namespace std;

int main()
{
	srand(time(NULL));   //to get different numbers each time
	
	cout<<endl<<"---------------HUMAN-------------"<<endl;
	Human humanone(40,40);   
	humanone.getDamage(); 
	cout<<endl<<endl<<"----------------ELF--------------"<<endl;	
	Elf elfone(40,40);
	elfone.getDamage();
	cout<<endl<<endl<<"---------------BALROG------------"<<endl;
	Balrog balrogone(40,40);
	balrogone.getDamage();
	cout<<endl<<endl<<"-----------CYBERDEMON------------"<<endl;
	Cyberdemon cyberdemon1 ;
	cyberdemon1.getDamage();
	cout << endl;
}