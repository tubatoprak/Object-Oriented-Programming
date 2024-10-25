#ifndef BALROG_H
#define BALROG_H
#include <iostream>
#include <string>
#include "demon.h"  
using namespace std;
 
class Balrog:public Demon  // inheritance
{
	public:       
		Balrog();       //CONSTRUCTOR
		Balrog(int newStrength, int newHitpoints);  //constructor with parameters
		int getDamage();   // to output and calculate damage
	private:  
		string getSpecies();  //return type
};
#endif