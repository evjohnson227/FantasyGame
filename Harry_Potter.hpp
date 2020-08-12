/*******************
**
**	Name:		Eric Johnson
**	Date:		5/9/19
**	Description:	Header file for Harry Potter class - derived from Character abstract class - has special ability Hogwarts:
**			when used, instantly revives Harry Potter to strength points
**			
**
*****************/

#ifndef HARRY_POTTER_HPP
#define HARRY_POTTER_HPP

#include "Character.hpp"

class Harry_Potter : public Character
{
	private:
		int hogwarts;

	public:
		void setData();
		void recover();
		~Harry_Potter() {};
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

#endif			// HARRY_POTTER_HPP
