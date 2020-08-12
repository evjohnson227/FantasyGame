/*******************
**
**	Name:		Eric Johnson
**	Date:		5/9/19
**	Description:	Implementation file for Barbarian class - derived from Character abstract class
**			
**
*****************/

#include "Barbarian.hpp"

// Method that initializes Barbarian's data members
void Barbarian::setData()
{
	type = "Barbarian";
	name = "Player Barbarian";
	armor = 0;
	strengthPoints = 12;
	isDead = false;
}

// Method that recovers character if it is at or less than half strength points; to be used in tournament class
void Barbarian::recover()
{

	const int MAXSTRENGTHPOINTS = 12;
	int healRoll;
	int recovery;

	// Determine how much to heal character based on five-sided dice roll
	healRoll = std::rand() % 5 + 1;


	// Recover if character is at half or less total strength points
	if (strengthPoints <= MAXSTRENGTHPOINTS / 2)
	{
		switch (healRoll)
		{
			// Heal 10% of overall strength points
			case 1: recovery = (MAXSTRENGTHPOINTS * 10) / 100;
				std::cout << "Winner Barbarian has recovered 10 percent of strength points" << std::endl;
				break;

			// Heal 20% of overall strength points
			case 2: recovery = (MAXSTRENGTHPOINTS * 20) / 100;
				std::cout << "Winner Barbarian has recovered 20 percent of strength points" << std::endl;
				break;

			// Heal 30% of overall strength points
			case 3: recovery = (MAXSTRENGTHPOINTS * 30) / 100;
				std::cout << "Winner Barbarian has recovered 30 percent of strength points" << std::endl;
				break;

			// Heal 40% of overall strength points
			case 4: recovery = (MAXSTRENGTHPOINTS * 40) / 100;
				std::cout << "Winner Barbarian has recovered 40 percent of strength points" << std::endl;
				break;

			// Heal 50% of overall strength points
			case 5: recovery = (MAXSTRENGTHPOINTS * 50) / 100;
				std::cout << "Winner Barbarian has recovered 50 percent of strength points" << std::endl;
				break;
		}

		// Recover damage
		strengthPoints += recovery;
	}
}

// Get methods for each data member
std::string Barbarian::getType()
{
	return type;
}

std::string Barbarian::getName()
{
	return name;
}

int Barbarian::getArmor()
{
	return armor;
}

int Barbarian::getStrengthPoints()
{
	return strengthPoints;
}

bool Barbarian::getIsDead()
{
	return isDead;
}

// Set methods for each data member
void Barbarian::setName(std::string nameIn)
{
	name = nameIn;
}

void Barbarian::setArmor(int armorIn)
{
	armor = armorIn;
}

void Barbarian::setStrengthPoints(int strengthPointsIn)
{
	strengthPoints = strengthPointsIn;
}

int Barbarian::attackRoll()
{
	int attackRoll, die1, die2;

	die1 = std::rand() % 6 + 1;

	die2 = std::rand() % 6 + 1;

	attackRoll = die1 + die2;

	return attackRoll;
}

int Barbarian::defenseRoll()
{
	int defenseRoll, die1, die2;
	
	die1 = std::rand() % 6 + 1;

	die2 = std::rand() % 6 + 1;

	defenseRoll = die1 + die2;

	return defenseRoll;
}

int Barbarian::attack()
{
	int attackDamage = attackRoll();
	std::cout << "Barbarian rolled " << attackDamage << " points of damage." << std::endl;

	return attackDamage;
}

void Barbarian::defense(int damageIn)
{
	const int MAX_DAMAGE = 100;
	int defense = defenseRoll();
	int damageReceived;

	if (damageIn < MAX_DAMAGE && damageIn > defense)
	{
		damageReceived = damageIn - defense - armor;
		strengthPoints -= damageReceived;
		std::cout << "Barbarian's defense roll: " << defense << std::endl;
		std::cout << "Barbarian's armor: " << armor << std::endl;
		std::cout << "Barbarian receives " << damageReceived << " points of damage." << std::endl;
		std::cout << "Barbarian's remaining strength points: " << strengthPoints << std::endl;
	}

	else if (damageIn < MAX_DAMAGE && damageIn < defense)
	{
		std::cout << "Barbarian's defense roll: " << defense << std::endl;
		std::cout << "Barbarian's armor: " << armor << std::endl;
		std::cout << "Barbarian manages to defend against the attack." << std::endl;
		std::cout << "No damage taken." << std::endl;
		std::cout << "Barbarian's remaining strength points: " << strengthPoints << std::endl;
	}

	else if (damageIn == MAX_DAMAGE)
	{
		strengthPoints = 0;
		std::cout << "Barbarian turns to stone." << std::endl;
		std::cout << "Barbarian remaining strength points: " << strengthPoints << std::endl;
		isDead = true;
	}

	if (strengthPoints > 0)
	{
		std::cout << "Barbarian survives this turn." << std::endl;
		std::cout << "Barbarian remaining strength points: " << strengthPoints << std::endl;
	}

	else if (strengthPoints <= 0)
	{
		std::cout << "Barbarian has run out of strength points." << std::endl;
		std::cout << "Barbarian strength points: " << strengthPoints << std::endl;
		isDead = true;
	}
}
