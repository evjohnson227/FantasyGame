/*******************
**
**	Name:		Eric Johnson
**	Date:		5/9/19
**	Description:	Implementation file for Harry Potter class - derived from Character abstract class - has special ability
**			Hogwarts: when used, instantly revives Harry Potter to 20 strength points
**			
**
*****************/

#include "Harry_Potter.hpp"

// Method that initializes Harry Potter's data members
void Harry_Potter::setData()
{
	type = "Harry Potter";
	name = "Player Harry Potter";
	armor = 0;
	strengthPoints = 10;
	isDead = false;
	hogwarts = 1;
}

void Harry_Potter::recover()
{
        const int MAXSTRENGTHPOINTS = 20;
        int healRoll;
        int recovery;

        // Determine how much to heal character based on five-sided dice roll
        healRoll = std::rand() % 5 + 1;

        // Recover if character is at half or less total strength points
        if (strengthPoints <= MAXSTRENGTHPOINTS / 4 && hogwarts == 1)
        {
                switch (healRoll)
                {
                        // Heal 10% of overall strength points
                        case 1: recovery = (MAXSTRENGTHPOINTS * 10) / 100;
                                std::cout << "Winner Harry Potter has recovered 10 percent of strength points" << std::endl;
                                break;

                        // Heal 20% of overall strength points
                        case 2: recovery = (MAXSTRENGTHPOINTS * 20) / 100;
                                std::cout << "Winner Harry Potter has recovered 20 percent of strength points" << std::endl;
                                break;

                        // Heal 30% of overall strength points
                        case 3: recovery = (MAXSTRENGTHPOINTS * 30) / 100;
                                std::cout << "Winner Harry Potter has recovered 30 percent of strength points" << std::endl;
                                break;

                        // Heal 40% of overall strength points
                        case 4: recovery = (MAXSTRENGTHPOINTS * 40) / 100;
                                std::cout << "Winner Harry Potter has recovered 40 percent of strength points" << std::endl;
                                break;

                        // Heal 50% of overall strength points
                        case 5: recovery = (MAXSTRENGTHPOINTS * 50) / 100;
                                std::cout << "Winner Harry Potter has recovered 50 percent of strength points" << std::endl;
                                break;
                }

                // Recover damage
                strengthPoints += recovery;
        }

	// Heal Harry Potter based on second life overall strength points
	else if (strengthPoints <= MAXSTRENGTHPOINTS / 2 && hogwarts == 0)
	{
		switch (healRoll)
		{
		
			// Heal 10% of overall strength points
			case 1:	recovery = (MAXSTRENGTHPOINTS * 10) / 100;
                                std::cout << "Winner Harry Potter has recovered 10 percent of strength points" << std::endl;
                                break;

                        // Heal 20% of overall strength points
                        case 2: recovery = (MAXSTRENGTHPOINTS * 20) / 100;
                                std::cout << "Winner Harry Potter has recovered 20 percent of strength points" << std::endl;
                                break;

                        // Heal 30% of overall strength points
                        case 3: recovery = (MAXSTRENGTHPOINTS * 30) / 100;
                                std::cout << "Winner Harry Potter has recovered 30 percent of strength points" << std::endl;
                                break;

                        // Heal 40% of overall strength points
                        case 4: recovery = (MAXSTRENGTHPOINTS * 40) / 100;
                                std::cout << "Winner Harry Potter has recovered 40 percent of strength points" << std::endl;
                                break;

                        // Heal 50% of overall strength points
                        case 5: recovery = (MAXSTRENGTHPOINTS * 50) / 100;
                                std::cout << "Winner Harry Potter has recovered 50 percent of strength points" << std::endl;
                                break;
                }

                // Recover damage
                strengthPoints += recovery;
	}
}

// Get methods for each data member
std::string Harry_Potter::getType()
{
	return type;
}

std::string Harry_Potter::getName()
{
	return name;
}

int Harry_Potter::getArmor()
{
	return armor;
}

int Harry_Potter::getStrengthPoints()
{
	return strengthPoints;
}

bool Harry_Potter::getIsDead()
{
	return isDead;
}

// Set methods for each data member
void Harry_Potter::setName(std::string nameIn)
{
	name = nameIn;
}

void Harry_Potter::setArmor(int armorIn)
{
	armor = armorIn;
}

void Harry_Potter::setStrengthPoints(int strengthPointsIn)
{
	strengthPoints = strengthPointsIn;
}

// Method to return Harry_Potter's attack roll
// Generates two random numbers representing the roll of two dice
// Returns the total damage inflicted
int Harry_Potter::attackRoll()
{
	int attackRoll, die1, die2;

	die1 = std::rand() % 6 + 1;

	die2 = std::rand() % 6 + 1;

	attackRoll = die1 + die2;

	return attackRoll;
}

// Method to return Harry_Potter's defense roll
// Generates two random numbers representing the roll of two dice
int Harry_Potter::defenseRoll()
{
	int defenseRoll, die1, die2;
	
	die1 = std::rand() % 6 + 1;

	die2 = std::rand() % 6 + 1;

	defenseRoll = die1 + die2;

	return defenseRoll;
}

// Method to display and return Harry_Potter's attack damage
int Harry_Potter::attack()
{
	int attackDamage = attackRoll();
	std::cout << "Harry Potter rolled " << attackDamage << " points of damage." << std::endl;

	return attackDamage;
}

// Method that takes in 
void Harry_Potter::defense(int damageIn)
{
	const int MAX_DAMAGE = 100;
	int defense = defenseRoll();
	int damageReceived;

	if (damageIn < MAX_DAMAGE && damageIn > defense)
	{
		damageReceived = damageIn - defense - armor;
		strengthPoints -= damageReceived;
		std::cout << "Harry Potter's defense roll: " << defense << std::endl;
		std::cout << "Harry Potter's armor: " << armor << std::endl;
		std::cout << "Harry Potter receives " << damageReceived << " points of damage." << std::endl;
		std::cout << "Harry Potter's remaining strength points: " << strengthPoints << std::endl;
	}

	else if (damageIn < MAX_DAMAGE && damageIn < defense)
	{
		std::cout << "Harry Potter's defense roll: " << defense << std::endl;
		std::cout << "Harry Potter's armor: " << armor << std::endl;
		std::cout << "Harry Potter manages to defend against the attack." << std::endl;
		std::cout << "No damage taken." << std::endl;
		std::cout << "Harry Potter's remaining strength points: " << strengthPoints << std::endl;
	}

	else if (damageIn == MAX_DAMAGE && hogwarts == 1)
	{
		hogwarts--;
		strengthPoints = 20;
		
		std::cout << "Harry Potter turns to stone." << std::endl;
		std::cout << "Harry Potter uses special ability: Hogwarts." << std::endl;
		std::cout << "Harry Potter recovers to 20 strength points." << std::endl;
		std::cout << "Harry Potter's remaining strength points: 20." << std::endl;
	}

	else if (damageIn == MAX_DAMAGE && hogwarts == 0)
	{
		strengthPoints = 0;
		std::cout << "Harry Potter turns to stone. " << std::endl;
		std::cout << "Harry Potter remaining strength points: " << strengthPoints << std::endl;
		isDead = true;
	}

	if (strengthPoints > 0)
	{
		std::cout << "Harry Potter survives this turn." << std::endl;
		std::cout << "Harry Potter's remaining strength points: " << strengthPoints << std::endl;
	}

	else if (strengthPoints <= 0 && hogwarts == 1) 
	{
		hogwarts--;
		strengthPoints = 20;

		std::cout << "Harry Potter dies." << std::endl;
		std::cout << "Harry Potter uses special ability: Hogwarts." << std::endl;
		std::cout << "Harry Potter recovers to 20 strength points." << std::endl;
		std::cout << "Harry Potter's remaining strength points: 20." << std::endl;
	}

	else if (strengthPoints <= 0 && hogwarts == 0)
	{
		std::cout << "Harry Potter has run out of strength points." << std::endl;
		std::cout << "Harry Potter strength points: " << strengthPoints << std::endl;
		isDead = true;
	}
}
