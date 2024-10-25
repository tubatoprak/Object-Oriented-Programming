#include <iostream>
#include <string>
#include <cstdlib>
#include "demon.h"
#include "creature.h" //for inheritance
using namespace std;

Demon::Demon() //constructor
{
	Creature();
}
Demon::Demon(int newStrength, int newHitpoints) //constructor with parameters
{
	Creature(newStrength, newHitpoints); 
}

int Demon::getDamage()  //to output and calculate damage
{
	int damage; 
	damage = Creature::getDamage();  // inheritance - calls function in creature class
	
	cout << " attacks for " <<damage << " points!" << endl;
	
	if ((rand() % 100) < 5) //5% chance for demon attack
	{
		damage = damage + 50;

		cout << "Demon attacks  50 + "  << endl;
		cout << "Total attacks for " << damage << " points!" << endl;
	}
	return damage;
}