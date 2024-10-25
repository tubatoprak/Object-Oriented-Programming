#include <iostream>
#include <string>
#include <cstdlib>
#include "creature.h"    

using namespace std;

Creature::Creature( ) //constructor 
{
	strength = 20;   
	hitpoints = 20;
}
Creature::Creature(int newStrength, int newHitpoints) //constructor with parameters
{
	strength = newStrength;  
	hitpoints = newHitpoints;
}
void Creature::setStrength(int newStrength)  //setter strength
{
	strength = newStrength;
}
int Creature::getStrength()  //getter strength
{
	return strength;
}
string Creature::getSpecies()  //getter type
{
	return "Unknown Creature";
}

int Creature::getDamage()  //to output and calculate damage 
{  
	int damage;
	damage = (rand() % strength) + 1;  //random number for damage
	return damage;
	}

void Creature::setHitpoints(int newHitpoints) //setter  hitpoints
{
	hitpoints = newHitpoints;
}
int Creature::getHitpoints()
{
	return hitpoints;
}