/*******************
**
**	Name:		Eric Johnson
**	Date:		5/9/19
**	Description:	Implementation file for Medusa class - derived from Character abstract class - has special ability glare:
**			when cast, immediately turns opponent to stone
**			
**
*****************/

#include "Medusa.hpp"

// Method that initializes Medusa's data members
void Medusa::setData()
{
	type = "Medusa";
	name = "Player Medusa";
	armor = 3;
	strengthPoints = 8;
	isDead = false;
}

// Method that recovers character if they incurred damage from battle
void Medusa::recover()
{
        const int MAXSTRENGTHPOINTS = 8;
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
                                std::cout << "Winner Medusa has recovered 10 percent of strength points" << std::endl;
                                break;

                        // Heal 20% of overall strength points
                        case 2: recovery = (MAXSTRENGTHPOINTS * 20) / 100;
                                std::cout << "Winner Medusa has recovered 20 percent of strength points" << std::endl;
                                break;

                        // Heal 30% of overall strength points
                        case 3: recovery = (MAXSTRENGTHPOINTS * 30) / 100;
                                std::cout << "Winner Medusa has recovered 30 percent of strength points" << std::endl;
                                break;

                        // Heal 40% of overall strength points
                        case 4: recovery = (MAXSTRENGTHPOINTS * 40) / 100;
                                std::cout << "Winner Medusa has recovered 40 percent of strength points" << std::endl;
                                break;

                        // Heal 50% of overall strength points
                        case 5: recovery = (MAXSTRENGTHPOINTS * 50) / 100;
                                std::cout << "Winner Medusa has recovered 50 percent of strength points" << std::endl;
                                break;
                }

                // Recover damage
                strengthPoints += recovery;
        }
}


// Get methods for each data member
std::string Medusa::getType()
{
	return type;
}

std::string Medusa::getName()
{
	return name;
}

int Medusa::getArmor()
{
	return armor;
}

int Medusa::getStrengthPoints()
{
	return strengthPoints;
}

bool Medusa::getIsDead()
{
	return isDead;
}

// Set methods for each data member
void Medusa::setName(std::string nameIn)
{
	name = nameIn;
}

void Medusa::setArmor(int armorIn)
{
	armor = armorIn;
}

void Medusa::setStrengthPoints(int strengthPointsIn)
{
	strengthPoints = strengthPointsIn;
}

// Method to return Medusa's attack roll
// Generates a random number representing 2 six-sided die
// Returns total damage inflicted
int Medusa::attackRoll()
{
	int attackRoll, die1, die2;
	
	die1 = std::rand() % 6 + 1;

	die2 = std::rand() % 6 + 1;

	attackRoll = die1 + die2;

	return attackRoll;
}

// Method to return Medusa's defense roll
// Generates a random number representing the roll of a six-sided die
// Returns total damage inflicted
int Medusa::defenseRoll()
{
	int defenseRoll;
	
	defenseRoll = std::rand() % 6 + 1;

	return defenseRoll;
}

// Method to display and return Medusa's attack damage
int Medusa::attack()
{
	int attackDamage = attackRoll();

	// Glare special abilty, when a 12 is rolled, deals max damage
	if (attackDamage == 12)
	{
		attackDamage = 100;

		std::cout << "Medusa casts glare." << std::endl;
	}

	else
	{
		std::cout << "Medusa rolled " << attackDamage << " points of damage." << std::endl;
	}
	return attackDamage;
}

void Medusa::defense(int damageIn)
{
	const int MAX_DAMAGE = 100;
	int defense = defenseRoll();
	int damageReceived;

	if (damageIn < MAX_DAMAGE && damageIn > defense)
	{
		damageReceived = damageIn - defense - armor;
		strengthPoints -= damageReceived;
		std::cout << "Medusa's defense roll: " << defense << std::endl;
		std::cout << "Medusa's armor: " << armor << std::endl;
		std::cout << "Medusa receives " << damageReceived << " points of damage." << std::endl;
		std::cout << "Medusa's remaining strength points: " << strengthPoints << std::endl;
	}

	else if (damageIn < MAX_DAMAGE && damageIn < defense)
	{
		std::cout << "Medusa's defense roll: " << defense << std::endl;
		std::cout << "Medusa's armor: " << armor << std::endl;
		std::cout << "Medusa manages to defend against the attack." << std::endl;
		std::cout << "No damage taken" << std::endl;
		std::cout << "Medusa's remaining strength points: " << strengthPoints << std::endl;
	}

	else if (damageIn == MAX_DAMAGE)
	{
		strengthPoints = 0;
		std::cout << "Medusa turns to stone." << std::endl;
		std::cout << "Medusa remaining strength points: " << strengthPoints << std::endl;
		isDead = true;
	}

	if (strengthPoints > 0)
	{
		std::cout << "Medusa survives this turn." << std::endl;
		std::cout << "Medusa remaining strength points: " << strengthPoints << std::endl;
	}

	else if (strengthPoints <= 0)
	{
		std::cout << "Medusa has run out of strength points." << std::endl;
		std::cout << "Medusa strength points: " << strengthPoints << std::endl;
		isDead = true;
	}
}

