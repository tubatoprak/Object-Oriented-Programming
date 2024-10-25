#include <iostream>
#include <string>
#include <cstdlib>
#include "balrog.h"
#include "demon.h" //for inheritance

using namespace std;
Balrog::Balrog()  //constructor
{
	Demon();
}
Balrog::Balrog(int newStrength, int newHitpoints) //constructor with parameters
{
	Demon(newStrength, newHitpoints);
}
string Balrog::getSpecies()   //getter type
{
	return "Balrog";
}
int Balrog::getDamage()  //to output and calculate damage
{
	int damage,damage1;
	cout << getSpecies();  //to print  type
	damage = Demon::getDamage();  // inheritance - calls function in demon class	
	damage1 = (rand() % getStrength()) + 1;    //random speed calculation for balrog
	cout<<  getSpecies() <<" twice attacks  "<<damage1<< " + "<<endl;//print for speed
	damage = damage + damage1;  //calculate new damage
	cout << "New "<<  getSpecies() << " attacks for " << damage << " points!" << endl;  //print for new damage
	return damage;
}