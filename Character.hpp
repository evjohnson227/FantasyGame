/*************
**
**	Name:		Eric Johnson
**	Date:		5/6/19
**	Description:	Character class header file - base class that contains four data members: attack, defense,
**			armor, and strength points; default constructor; constructor that takes four parameters 
**			and uses them to initialize data members; get and set methods for each data member
**
************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

class Character
{
	protected:
		std::string type;
		std::string name;
		int armor;
		int strengthPoints;
		bool isDead;
		
	public:
		virtual void recover() = 0;
		virtual void setData() = 0;
		virtual ~Character() {};
		virtual std::string getType() = 0;
		virtual std::string getName() = 0;
		virtual int getArmor() = 0;
		virtual int getStrengthPoints() = 0;
		virtual bool getIsDead() = 0;
		virtual void setName(std::string nameIn) = 0;
		virtual void setArmor(int armorIn) = 0;
		virtual void setStrengthPoints(int strengthPointsIn) = 0;
		virtual int attack() = 0;
		virtual void defense(int attackDamageIn) = 0;
};

#endif			// CHARACTER_HPP
