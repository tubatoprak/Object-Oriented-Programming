#ifndef CYBERDEMON_H
#define CYBERDEMON_H
#include <iostream>
#include <string>
#include "demon.h"
using namespace std;
class Cyberdemon : public Demon   // inheritance 
{
	public:
		Cyberdemon( ); //CONSTRUCTOR
		Cyberdemon(int newStrength, int newHitpoints);  //constructor with parameters
		int getDamage();    // to output and calculate damage
	private:
		string getSpecies();   //return type 
};
#endif