/*******************
**
**	Name:		Eric Johnson
**	Date:		5/9/19
**	Description:	Header file for Vampire class - derived from Character abstract class; has special ability charm: when used
**			it gives a 50% chance that the opponent will not attack
**			
*****************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Character.hpp"

class Vampire : public Character
{
	private:
		int charm;

	public:
		void setData();
		void recover();
		~Vampire() {};
		std::string getType();
		std::string getName();
		int getArmor();
		int getStrengthPoints();
		bool getIsDead();
		void setName(std::string nameIn);
		void setArmor(int armorIn);
		void setStrengthPoints(int strengthPointsIn);
		int attackRoll();
		int defenseRoll();
		int charmRoll();
		int attack();
		void defense(int attackDamageIn);
};

#endif			// VAMPIRE_HPP
