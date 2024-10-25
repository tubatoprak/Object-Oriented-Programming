#ifndef HUMAN_H
#define HUMAN_H
#include <iostream>
#include <string>
#include "creature.h"
using namespace std;

class Human : public Creature  // inheritance
{
	public:    
		Human();   //constructor
		Human(int newStrength, int newHitpoints);     
		int getDamage(); //to output and calculate damage
	private:
		string getSpecies();   //to return type 
};
#endif