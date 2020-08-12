/*******************
**
**	Name:		Eric Johnson
**	Date:		5/9/19
**	Description:	Header file for Medusa class - derived from Character abstract class - has special abilty glare:
**			when cast, immediately turns opponent to stone
**			
**
*****************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "Character.hpp"

class Medusa : public Character
{
	public:
		void setData();
		void recover();
		~Medusa() {};
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
		int attack();
		void defense(int attackDamageIn);
};
#endif			// MEDUSA_HPP
