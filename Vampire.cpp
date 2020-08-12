/*******************
**
**	Name:		Eric Johnson
**	Date:		5/9/19
**	Description:	Implemenation file for Vampire class - derived from Character abstract class
**			
**
*****************/

#include "Vampire.hpp"

// Method that initializes Vampire's data members
void Vampire::setData()
{
	type = "Vampire";
	name = "Player Vampire";
	armor = 1;
	strengthPoints = 18;
	isDead = false;
	charm = 0;
}

// Method that recovers the Vampire's health; used in tournament class
void Vampire::recover()
{
	const int MAXSTRENGTHPOINTS = 18;
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
				std::cout << "Winner Vampire has recovered 10 percent of strength points" << std::endl;
				break;

			// Heal 20% of overall strength points
			case 2: recovery = (MAXSTRENGTHPOINTS * 20) / 100;
				std::cout << "Winner Vampire has recovered 20 percent of strength points" << std::endl;
				break;

			// Heal 30% of overall strength points
			case 3: recovery = (MAXSTRENGTHPOINTS * 30) / 100;
				std::cout << "Winner Vampire has recovered 30 percent of strength points" << std::endl;
				break;

			// Heal 40% of overall strength points
			case 4: recovery = (MAXSTRENGTHPOINTS * 40) / 100;
				std::cout << "Winner Vampire has recovered 40 percent of strength points" << std::endl;
				break;

			// Heal 50% of overall strength points
			case 5: recovery = (MAXSTRENGTHPOINTS * 50) / 100;
				std::cout << "Winner Vampire has recovered 50 percent of strength points" << std::endl;
				break;
		}

		// Recover damage
		strengthPoints += recovery;
	}
}


// Get methods for each data member
std::string Vampire::getType()
{
	return type;
}

std::string Vampire::getName()
{
	return name;
}

int Vampire::getArmor()
{
	return armor;
}
int Vampire::getStrengthPoints()
{
	return strengthPoints;
}

bool Vampire::getIsDead()
{
	return isDead;
}

// Set methods for each data members
void Vampire::setName(std::string nameIn)
{
	name = nameIn;
}

void Vampire::setArmor(int armorIn)
{
	armor  = armorIn;
}

void Vampire::setStrengthPoints(int strengthPointsIn)
{
	strengthPoints = strengthPointsIn;
}

// Method to return Vampire's attack roll
// Generates a random number representing the roll of a 12-sided die
// Returns total damage inflicted
int Vampire::attackRoll()
{
	int attackRoll;

	attackRoll = std::rand() % 12 + 1;

	return attackRoll;
}

int Vampire::defenseRoll()
{
	int defenseRoll, die1, die2;

	die1 = std::rand() % 6 + 1;

	die2 = std::rand() % 6 + 1;

	defenseRoll = die1 + die2;

	return defenseRoll;
}

// Method to determine if charm special ability is cast - 1 = successful, 2 = not
int Vampire::charmRoll()
{
	int charmRoll = rand() % 2 + 1;

	return charmRoll;
}

// Method to display and return Vampire's attack damaage
int Vampire::attack()
{
	int attackDamage = attackRoll();
	std::cout << "Vampire rolled " << attackDamage << " point(s) of damage." << std::endl;

	return attackDamage;
}

void Vampire::defense(int damageIn)
{
	const int MAX_DAMAGE = 100;
	int defense = defenseRoll();
	charm = charmRoll();
	int damageReceived;
	
	if (charm == 1 && damageIn == MAX_DAMAGE)
	{
		std::cout << "Vampire casts charm. Medusa's glare did no damage." << std::endl;
		std::cout << "Vampire's remaining strength points: " << strengthPoints << std::endl;
	}

	else if (charm == 2 && damageIn == MAX_DAMAGE)
	{
		strengthPoints = 0;
		
		std::cout << "Vampire turned to stone." << std::endl;
		std::cout << "Vampire remaining strength points: " << strengthPoints << std::endl;
		isDead = true;
	}

	if (damageIn < MAX_DAMAGE && damageIn > defense)
	{
		if (charm == 1)
		{
			std::cout << "Vampire casts charm. No damage taken." << std::endl;
		}

		else
		{
			damageReceived = damageIn - defense - armor;
			strengthPoints -= damageReceived;
			std::cout << "Vampire's defense roll: " << defense << std::endl;
			std::cout << "Vampire's armor: " << armor << std::endl;
			std::cout << "Vampire receives " << damageReceived << " points of damage." << std::endl;
			std::cout << "Vampire's remaining strength points: " << strengthPoints << std::endl;
		}
	}

	else if (damageIn < defense)
	{
		std::cout << "Vampire's defense roll: " << defense << std::endl;
		std::cout << "Vampire's armor: " << armor << std::endl;
		std::cout << "Vampire manages to defend against the attack." << std::endl;
		std::cout << "No damage taken." << std::endl;
		std::cout << "Vampire's remaining strength points: " << strengthPoints << std::endl;
	}

	if (strengthPoints > 0)
	{
		std::cout << "Vampire survives this turn." << std::endl;
		std::cout << "Vampire's remaining strength points: " << strengthPoints << std::endl;
	}

	else if (strengthPoints <= 0)
	{
		std::cout << "Vampire has run out of strength points. Vampire dies ." << std::endl;
		std::cout << "Vampire strength points: " << strengthPoints << std::endl;
		isDead = true;
	}
}

