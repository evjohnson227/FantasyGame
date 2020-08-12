/***********
**
**	Name:		Eric Johnson
**	Date:		5/9/19
**	Description:	Game class implementation file - consists of two characters representing players in the game; constructor that takes
**			two parameters and uses them to initialize data members; method to create objects based on user's choic; method to
**			simulate character battle
**
*********/

#include "Game.hpp"

// Constructor that takes to parameters and uses them to initialize data members
Game::Game(Character *player1In, Character *player2In)
{
	player1 = player1In;
	player2 = player2In;
}

// Method that creates Character objects based on user choice
void Game::setPlayerCharacters()
{
	int player1Choice;
	int player2Choice;

	player1Choice = characterSelectMenu();
	player2Choice = characterSelectMenu();

	switch (player1Choice)
	{
		case 1: player1 = new Vampire;
			player1->setData();
			break;
		case 2: player1 = new Barbarian;
			player1->setData();
			break;
		case 3: player1 = new Blue_Men;
			player1->setData();
			break;
		case 4: player1 = new Medusa;
			player1->setData();
			break;
		case 5: player1 = new Harry_Potter;
			player1->setData();
			break;
	}

	switch (player2Choice)
	{
		case 1: player2 = new Vampire;
			player2->setData();
			break;
		case 2: player2 = new Barbarian;
			player2->setData();
			break;
		case 3: player2 = new Blue_Men;
			player2->setData();
			break;
		case 4: player2 = new Medusa;
			player2->setData();
			break;
		case 5: player2 = new Harry_Potter;
			player2->setData();
			break;
	}
}

// Method to simulate character battle
void Game::playGame()
{
	int damage;
	int choice;

	std::cout << "Player 1: " << player1->getType() << std::endl;
	std::cout << "Armor: " << player1->getArmor() << std::endl;
	std::cout << "Strength Points: " << player1->getStrengthPoints() << std::endl;

	std::cout << "Player 2: " << player2->getType() << std::endl;
	std::cout << "Armor: " << player2->getArmor() << std::endl;
	std::cout << "Strength Points: " << player2->getStrengthPoints() << std::endl;

	do
	{
		// Player 1's attack
		std::cout << "Begin turn: " << std::endl;
		std::cout << "Player 1's attack: " << std::endl;
		damage = player1->attack();

		std::cout << "Player 2's defense: " << std::endl;
		player2->defense(damage);

		// Player 2's attack
		if (player2->getIsDead() == false)
		{
			std::cout << "Player 2's attack: " << std::endl;
			damage = player2->attack();

			std::cout << "Player 1's defense: " << std::endl;
			player1->defense(damage);
		}

		// Display results	
		std::cout << "End turn: " << std::endl;
		std::cout << "Player 1: " << std::endl;
		std::cout << "Armor: " << player1->getArmor() << std::endl;
		std::cout << "Strength Points: " << std::endl;
	
		std::cout << "Player 2: " << std::endl;
		std::cout << "Armor: " << player2->getArmor() << std::endl;;
		std::cout << "Strength Points: " << player2->getStrengthPoints() << std::endl;

		if (player1->getIsDead() == true)
		{
			std::cout << "Player 2 wins!" << std::endl;
		}

		else if (player2->getIsDead() == true)
		{
			std::cout << "Player 1 wins!" << std::endl;
		}

		if (player1->getIsDead() == false && player2->getIsDead() == false)
		{
			choice = continuePlaying();
		}

		else if (player1->getIsDead() == true || player2->getIsDead() == true)
		{
			return;
		}

	} while (choice != 2);

	// Free allocated memory
	delete player1;
	delete player2;
}

		

				










