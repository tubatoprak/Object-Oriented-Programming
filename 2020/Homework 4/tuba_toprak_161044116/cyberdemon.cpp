#include <iostream>
#include <string>
#include <cstdlib>
#include "cyberdemon.h"
#include "demon.h"          //for inheritance
using namespace std;
Cyberdemon::Cyberdemon( ) //constructor
{
	Demon();
}
Cyberdemon::Cyberdemon(int newStrength, int newHitpoints)  //constructor with parameters
{
	Demon(newStrength, newHitpoints);
}
string Cyberdemon::getSpecies() //getter type
{
	return "Cyberdemon";
}
int Cyberdemon::getDamage()  //to output and calculate damage 
{
	int damage;  
	
	cout << getSpecies();  //to print  type
	
	damage = Demon::getDamage();  // inheritance - calls function in demon class
	
	return damage;
  }
