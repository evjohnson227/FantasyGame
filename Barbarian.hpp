/*******************
**
**	Name:		Eric Johnson
**	Date:		5/9/19
**	Description:	Header file for Barbarian class - derived from Character abstract class
**			
**
*****************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Character.hpp"

class Barbarian : public Character
{
	public:
		void setData();
		void recover();
		~Barbarian() {};
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
		void defense(int damageIn);
};

#endif			// BARBARIAN_HPP
