#ifndef CREATURE_H  
#define CREATURE_H
#include <iostream>
#include <string>

using namespace std;
class Creature      // inheritance
{
	public:
		Creature( );                             //CONSTRUCTOR
		Creature(int newStrength, int newHitpoints);
		void setStrength(int newStrength);     //SETTER FUNCTIONS
		void setHitpoints(int newHitpoints);
		int getStrength();                    //GETTER FUNCTIONS
		int getHitpoints();
		int getDamage();          // to output and calculate damage
		private:
		int strength;       	  //to determine the interval for the random number
		int hitpoints;
		string getSpecies(); 	//return type (cyberdemon,elf,human,balrog) 
};
#endif