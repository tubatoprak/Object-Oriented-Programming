#include <iostream>
#include <string>
#include <cstdlib>
#include "elf.h"
#include "creature.h" //for inheritance
using namespace std;

Elf::Elf() //constructor  
{
	 Creature();
}

Elf::Elf(int newStrength, int newHitpoints) //constructor with parameters
{
	setStrength(newStrength);
	setHitpoints(newHitpoints);
}

string Elf::getSpecies() //getter type
{
	return "Elf";
}

int Elf::getDamage() //to output and calculate damage
{  
	int damage;
	damage = Creature::getDamage(); // inheritance - calls function in creature class
	cout << getSpecies()<<" attacks for "<< damage<< " points!" <<endl;
	if ((rand() % 100) < 10) // 10% chance for  magical attack
	{
		cout<<"Magical attack  2*"<< damage <<" + "<<endl;
		damage = damage *2;
		cout << "New "<<  getSpecies() << " attacks for " << damage << " points!" << endl;
	}
	return damage;
}
