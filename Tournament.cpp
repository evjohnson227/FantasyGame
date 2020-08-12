/**********
**
**	Name:		Eric Johnson
**	Date:		5/21/19
**	Description:	Tournament class implementation file - contains four data members - 2 queues tol hold the lineups
**			of characters for eac team, 2 queues to hold the losers of each team - methods to initiate the tournament
**			and shows the results of the tournament
**
**********/

#include "Tournament.hpp"

// Default constructor that sets each data member to null
Tournament::Tournament()
{
	team1 = NULL;
	team1Losers = NULL;
	team2 = NULL;
	team2Losers = NULL;
}

void Tournament::playTournament()
{
	int numFighters;
	std::string fighterName;
	int team1Choice;
	int team2Choice;
	Character *team1AddVampire, *team1AddBarbarian, *team1AddBlueMen, *team1AddMedusa, *team1AddHarryPotter;
	Character *team2AddVampire, *team2AddBarbarian, *team2AddBlueMen, *team2AddMedusa, *team2AddHarryPotter;

	int damage;
	int counter = 0;
	int team1Score = 0;
	int team2Score = 0;

	this->team1 = new CharacterQueue;
	this->team1Losers = new CharacterQueue;
	this->team2 = new CharacterQueue;
	this->team2Losers = new CharacterQueue;

	// Prompts user to enter the number of fighters for both teams
	std::cout << "Please enter the number fighters: " << std::endl;

	// Validate input for number of fighters
	// Max number of fighters arbitrarily set
	numFighters = getInt(1, 1000);

	// Loop to choose character types and names for Team 1
	do
	{
		// Prompt user to choose a character type
		team1Choice = characterSelectMenu();

		// Create character object based on user input and add it to Team 1 queue
		switch (team1Choice)
		{
			case 1: team1AddVampire = new Vampire;
				team1AddVampire->setData();
				std::cout << "Please enter a name for Team 1 fighter: " << counter + 1 << std::endl;
				getline(std::cin, fighterName);
				team1AddVampire->setName(fighterName);
				this->team1->addBack(team1AddVampire);
				break;

			case 2: team1AddBarbarian = new Barbarian;
				team1AddBarbarian->setData();
				std::cout << "Please enter a name for Team 1 fighter: " << counter + 1 << std::endl;
				getline(std::cin, fighterName);
				team1AddBarbarian->setName(fighterName);
				this->team1->addBack(team1AddBarbarian);
				break;
			
			case 3: team1AddBlueMen = new Blue_Men;
				team1AddBlueMen->setData();
				std::cout << "Please enter a name for Team 1 fighter: " << counter + 1 << std::endl;
				getline(std::cin, fighterName);
				team1AddBlueMen->setName(fighterName);
				this->team1->addBack(team1AddBlueMen);
				break;
	
			case 4: team1AddMedusa = new Medusa;
				team1AddMedusa->setData();
				std::cout << "Please enter a name for Team 1 fighter: " << counter + 1 << std::endl;
				getline(std::cin, fighterName);
				team1AddMedusa->setName(fighterName);
				this->team1->addBack(team1AddMedusa);
				break;

			case 5: team1AddHarryPotter = new Harry_Potter;
				team1AddHarryPotter->setData();
				std::cout << "Please enter a name for Team 1 fighter: " << counter + 1<< std::endl;
				getline(std::cin, fighterName);
				team1AddHarryPotter->setName(fighterName);
				this->team1->addBack(team1AddHarryPotter);
				break;
		}

		counter++;

	} while (counter < numFighters);

	// Reset counter for team 2
	counter = 0;

	// Loop to choose character types and names for Team 2
	do
	{
		// Prompt user to choose a character type
		team2Choice = characterSelectMenu();

		// Create character object based on user input and add it to Team 2 queue
		switch (team2Choice)
		{
			case 1: team2AddVampire = new Vampire;
                                team2AddVampire->setData();
                                std::cout << "Please enter a name for Team 2 fighter: " << counter + 1 << std::endl;
                                getline(std::cin, fighterName);
                                team2AddVampire->setName(fighterName);
                                this->team2->addBack(team2AddVampire);
				break;

                        case 2: team2AddBarbarian = new Barbarian;
                                team2AddBarbarian->setData();
                                std::cout << "Please enter a name for Team 2 fighter: " << counter + 1 << std::endl;
                                getline(std::cin, fighterName);
                                team2AddBarbarian->setName(fighterName);
                                this->team2->addBack(team2AddBarbarian);
				break;

                        case 3: team2AddBlueMen = new Blue_Men;
                                team2AddBlueMen->setData();
                                std::cout << "Please enter a name for Team 2 fighter: " << counter + 1 << std::endl;
                                getline(std::cin, fighterName);
                                team2AddBlueMen->setName(fighterName);
                                this->team2->addBack(team2AddBlueMen);
				break;

                        case 4: team2AddMedusa = new Medusa;
                                team2AddMedusa->setData();
                                std::cout << "Please enter a name for Team 2 fighter: " << counter + 1 << std::endl;
                                getline(std::cin, fighterName);
                                team2AddMedusa->setName(fighterName);
                                this->team2->addBack(team2AddMedusa);
				break;

                        case 5: team2AddHarryPotter = new Harry_Potter;
                                team2AddHarryPotter->setData();
                                std::cout << "Please enter a name for Team 2 fighter: " << counter + 1 << std::endl;
                                getline(std::cin, fighterName);
                                team2AddHarryPotter->setName(fighterName);
                                this->team2->addBack(team2AddHarryPotter);
				break;
                }

		counter ++;

	} while (counter < numFighters);

	// Loop to battle the head's of each queue
	while (!team1->isEmpty() && !team2->isEmpty())
	{
		Character* team1Fighter = team1->getFront();
		Character* team2Fighter = team2->getFront();

		std::cout << "Team 1 Fighter: " << team1Fighter->getType() << std::endl;
		std::cout << "Name: " << team1Fighter->getName() << std::endl;
		std::cout << "Armor: " << team1Fighter->getArmor() << std::endl;
		std::cout << "Strength Points: " << team1Fighter->getStrengthPoints() << std::endl;
		std::cout << std::endl;

		std::cout << "Team 2 Fighter: " << team2Fighter->getType() << std::endl;
		std::cout << "Name: " << team2Fighter->getName() << std::endl;
		std::cout << "Armor: " << team2Fighter->getArmor() << std::endl;
		std::cout << "Strength Points: " << team2Fighter->getStrengthPoints() << std::endl;
		std::cout << std::endl;

		// Team 1's attack
		std::cout << "Begin turn: " << std::endl;
		std::cout << "Team 1 fighter attacks!" << std::endl;
		damage = team1Fighter->attack();

		// Team 2's defense
		std::cout << "Team 2 fighter defends!" << std::endl;
		team2Fighter->defense(damage);

		// Team 2's attack
		if (team2Fighter->getIsDead() == false)
		{	
			std::cout << "Player 2 attacks!" << std::endl;
			damage = team2Fighter->attack();

			// Team 1's defense
			std::cout << "Team 1 defends: " << std::endl;
			team1Fighter->defense(damage);
		}

		// Display results of the round
		std::cout << "End of turn" << std::endl;
		std::cout << std::endl;
		std::cout << "Results... " << std::endl;
		std::cout << std::endl;

		std::cout << "Team 1 Fighter: " << std::endl;
		std::cout << "Type: " << team1Fighter->getType() << std::endl;
		std::cout << "Name: " << team1Fighter->getName() << std::endl;
		std::cout << "Armor: " << team1Fighter->getArmor() << std::endl;
		std::cout << "Strength Points: " << team1Fighter->getStrengthPoints() << std::endl;
		std::cout << std::endl;

		std::cout << "Team 2 Fighter: " << std::endl;
		std::cout << "Type: " << team2Fighter->getType() << std::endl;
		std::cout << "Name: " << team2Fighter->getName() << std::endl;
		std::cout << "Armor: " << team2Fighter->getArmor() << std::endl;
		std::cout << "Strength Points: " << team2Fighter->getStrengthPoints() << std::endl;
		std::cout << std::endl;

		// Team 2 wins the round
		if (team1Fighter->getIsDead() == true)
		{
			std::cout << "Team 2 wins this round!" << std::endl;
			// Recover winning fighter
			team2Fighter->recover();
			// Add team 1's fighter to the loser queue
			team1Losers->addBack(team1Fighter);
			// Remove team 1 fighter from the team lineup
			team1->removeFront();
			// Move to next character in team 2 queue
			team2->moveHead();
			// Increase winning team's score 
			team2Score++;
		}

		// Team 1 wins the round
		else if (team2Fighter->getIsDead() == true)
		{
			std::cout << "Team 1 wins this round!" << std::endl;
			// Recover winning fighter
			team1Fighter->recover();
			// Add team 2's fighter to the loser queue
			team2Losers->addBack(team2Fighter);
			// Remove team 2's fighter from the team lineup
			team2->removeFront();
			// Move to next character in team 1 queue
			team1->moveHead();
			// Increase winning team's score
			team1Score++;
		}
	}

	// Notify user if team 1 has won
	if (team1Score > team2Score)
	{
		std::cout << "Team 1 Score: " << team1Score << std::endl;
		std::cout << "Team 2 Score: " << team2Score << std::endl;
		std::cout << "Team 1 Wins!" << std::endl;
	}

	// Notify user if team 2 has won
	else if (team2Score > team1Score)
	{
		std::cout << "Team 1 Score: " << team1Score << std::endl;
		std::cout << "Team 2 Score: " << team2Score << std::endl;
		std::cout << "Team 2 Wins!" << std::endl;
	}

	else
	{
		std::cout << "Game tied" << std::endl;
	}

	// Ask user to display loser pile
	std::cout << "Display loser piles?" << std::endl;
	std::cout << "1) Yes" << std::endl;
	std::cout << "2) No" << std::endl;

	int userChoice = getInt(1, 2);

	if (userChoice == 1)
	{
		std::cout << "Team 1 Losers: " << std::endl;
		team1Losers->printCharacterQueue();
		std::cout << "Team 2 Losers: " << std::endl;
		team2Losers->printCharacterQueue();
	}

	else
	{
		return;
	}
}

// Destructor
Tournament::~Tournament()
{
	delete team1;
	delete team2;
	delete team1Losers;
	delete team2Losers;
}
