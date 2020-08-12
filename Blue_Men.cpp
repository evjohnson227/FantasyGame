/*******************
**
**	Name:		Eric Johnson
**	Date:		5/9/19
**	Description:	Implementation file for Blue Men class - derived from Character abstract class - has special ability mob:
**			for every 4 points of damage, Blue Men lose one defense die
**			
**
*****************/

#include "Blue_Men.hpp"

// Method that initializes Blue Men's data members
void Blue_Men::setData()
{
	type = "Blue Men";
	name = "Player Blue Men";
	armor = 1;
	strengthPoints = 12;
	isDead = false;
	mob = 0;
}

// Method that recovers character
void Blue_Men::recover()
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
                                std::cout << "Winner Blue Men has recovered 10 percent of strength points" << std::endl;
                                break;

                        // Heal 20% of overall strength points
                        case 2: recovery = (MAXSTRENGTHPOINTS * 20) / 100;
                                std::cout << "Winner Blue Men has recovered 20 percent of strength points" << std::endl;
                                break;

                        // Heal 30% of overall strength points
                        case 3: recovery = (MAXSTRENGTHPOINTS * 30) / 100;
                                std::cout << "Winner Blue Men has recovered 30 percent of strength points" << std::endl;
                                break;

                        // Heal 40% of overall strength points
                        case 4: recovery = (MAXSTRENGTHPOINTS * 40) / 100;
                                std::cout << "Winner Blue men has recovered 40 percent of strength points" << std::endl;
                                break;

                        // Heal 50% of overall strength points
                        case 5: recovery = (MAXSTRENGTHPOINTS * 50) / 100;
                                std::cout << "Winner Blue Men has recovered 50 percent of strength points" << std::endl;
                                break;
                }

                // Recover damage
                strengthPoints += recovery;
        }
}

// Get methods for each data member
std::string Blue_Men::getType()
{
	return type;
}

std::string Blue_Men::getName()
{
	return name;
}

int Blue_Men::getArmor()
{
	return armor;
}

int Blue_Men::getStrengthPoints()
{
	return strengthPoints;
}

bool Blue_Men::getIsDead()
{
	return isDead;
}

// Set methods for each data member
void Blue_Men::setName(std::string nameIn)
{
	name = nameIn;
}

void Blue_Men::setArmor(int armorIn)
{
	armor = armorIn;
}

void Blue_Men::setStrengthPoints(int strengthPointsIn)
{
	strengthPoints = strengthPointsIn;
}

// Mob special abiity: lose one die for every 4 points of damage taken
int Blue_Men::loseDie()
{
	if (strengthPoints > 8)
	{
		mob = 0;
	}

	else if (strengthPoints <= 8 && strengthPoints > 4)
	{
		mob = 1;
	}

	else if (strengthPoints > 0 && strengthPoints <= 4)
	{
		mob = 2;
	}
}

int Blue_Men::attackRoll()
{
	int attackRoll, die1, die2;

	die1 = std::rand() % 10 + 1;
	
	die2 = std::rand() % 10 + 1;

	attackRoll = die1 + die2;

	return attackRoll;
}

int Blue_Men::defenseRoll()
{
	int defenseRoll, die1, die2, die3;

	if (mob == 0)
	{
		die1 = std::rand() % 6 + 1;

		die2 = std::rand() % 6 + 1;
	
		die3 = std::rand() % 6 + 1;

		defenseRoll = die1 + die2 + die3;
	}

	else if (mob == 1)
	{
		die1 = std::rand() % 6 + 1;

		die2 = std::rand() % 6 + 1;

		defenseRoll = die1 + die2;
	}

	else if (mob == 2)
	{
		defenseRoll = std::rand() % 6 + 1;
	}

	return defenseRoll;
}

int Blue_Men::attack()
{
	int attackDamage = attackRoll();
	std::cout << "Blue Men rolled " << attackDamage << " points of damage." << std::endl;

	return attackDamage;
}
	
void Blue_Men::defense(int damageIn)
{
	const int MAX_DAMAGE = 100;
	int defense = defenseRoll();
	int damageReceived;

	if (damageIn < MAX_DAMAGE && damageIn > defense)
	{
		damageReceived = damageIn - defense - armor;
		strengthPoints -= damageReceived;
		std::cout << "Blue Men's defense roll: " << defense << std::endl;
		std::cout << "Blue Men's armor: " << armor << std::endl;
		std::cout << "Blue Men receives " << damageReceived << " points of damage." << std::endl;
		std::cout << "Blue Men's remaining strength points: " << strengthPoints << std::endl;
	}

	else if (damageIn < MAX_DAMAGE && damageIn < defense)
	{
		std::cout << "Blue Men's defense roll: " << defense << std::endl;
		std::cout << "Blue Men's armor: " << armor << std::endl;
		std::cout << "Blue Men manage to defend against the attack." << std::endl;
		std::cout << "No damage taken." << std::endl;
		std::cout << "Blue Men's remaining strength points: " << strengthPoints << std::endl;
	}

	else if (damageIn == MAX_DAMAGE)
	{
		strengthPoints = 0;
		std::cout << "Blue Men turn to stone." << std::endl;
		std::cout << "Blue Men remaining strength points: " << strengthPoints << std::endl;
		isDead = true;
	}

	if (strengthPoints > 0)
	{
		std::cout << "Blue Men survive this turn." << std::endl;
		std::cout << "Blue Men remaining strength points: " << strengthPoints << std::endl;
	}

	else if (strengthPoints <= 0)
	{
		std::cout << "Blue Men have run out of strength points." << std::endl;
		std::cout << "Blue Men strength points: " << strengthPoints << std::endl;
		isDead = true;
	}
}

