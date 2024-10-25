#ifndef ELF_H
#define ELF_H
#include <iostream>
#include <string>
#include "creature.h"

using namespace std;

class Elf : public Creature  // inheritance
{
	public:
		Elf(); //constructor
		Elf(int newStrength, int newHitpoints);
		int getDamage(); //to output and calculate damage
	private:
		string getSpecies();	//to return type

};
#endif