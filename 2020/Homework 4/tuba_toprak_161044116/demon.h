#ifndef DEMON_H
#define DEMON_H
#include <iostream>
#include <string>
#include "creature.h"

using namespace std;

class Demon : public Creature // inheritance
{
	public:
		Demon( ); //constructor
		Demon(int newStrength, int newHitpoints);
		int getDamage();  //to output and calculate damage
};
#endif