#include <iostream>
#include <string>
#include <cstdlib>
#include "human.h"
#include "creature.h" //for inheritance

using namespace std;

Human::Human() //constructor
{
	Creature();
}
Human::Human(int newStrength, int newHitpoints) //constructor with parameters
{
	Creature(newStrength, newHitpoints);  
}
string Human::getSpecies() //getter type
{
	return "Human";
}
int Human::getDamage() //to output and calculate damage
{
	int damage;
	damage = Creature::getDamage(); // inheritance - calls function in creture class
	cout << getSpecies() << " attacks for " << damage << " points!" << endl;
	return damage;
}