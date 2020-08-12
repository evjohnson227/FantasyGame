/*******************
**
**	Name:		Eric Johnson
**	Date:		5/9/19
**	Description:	Header file for Blue Men class - derived from Character abstract class - has special ability mob:
**			for every four points of damage, Blue Men lose one defense die
**			
**
*****************/

#ifndef BLUE_MEN_HPP
#define BLUE_MEN_HPP

#include "Character.hpp"

class Blue_Men : public Character
{
	private:
		int mob;

	public:
		void setData(); 
		void recover();
		~Blue_Men() {};
		std::string getType();
		std::string getName();
		int getArmor();
		int getStrengthPoints();
		bool getIsDead();
		void setName(std::string nameIn);
		void setArmor(int armorIn);
		void setStrengthPoints(int strengthPointsIn);
		int loseDie();
		int attackRoll();
		int defenseRoll();
		int attack();
		void defense(int damageIn);
};

#endif			// BLUE_MEN_HPP
