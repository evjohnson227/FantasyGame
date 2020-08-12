/*********************
**
**	Name:		Eric Johnson
**	Date:		5/11/19
**	Description:	Implementation file for menu functions
**
*********************/

#include "menu.hpp"

int startGameMenu()
{
	int choice;

	do
	{
		std::cout << "Fantasy Combat Game Menu" << std::endl;
		std::cout << "Please choose one of the following options: " << std::endl;
		std::cout << "1) Start game" << std::endl;
		std::cout << "2) Exit" << std::endl;
		std::cout << std::endl;

		choice = getInt(1, 2);

	} while (choice < 1 || choice > 2);

	return choice;
}

int characterSelectMenu()
{
	int choice;
	
	do
	{
		std::cout << "Choose your character type: " << std::endl;
		std::cout << "1) Vampire" << std::endl;
		std::cout << "2) Barbarian" << std::endl;
		std::cout << "3) Blue Men" << std::endl;
		std::cout << "4) Medusa" << std::endl;
		std::cout << "5) Harry Potter" << std::endl;
		std::cout << std::endl;

		choice = getInt(1, 5);
	} while (choice < 1 || choice > 5);

	return choice;
}

int continuePlaying()
{
	int choice;

	do
	{
		std::cout << "Continue Playing?" << std::endl;
		std::cout << "1) Play again" << std::endl;
		std::cout << "2) Exit" << std::endl;
		std::cout << std::endl;

		choice = getInt(1, 2);
	} while (choice < 1 || choice > 2);

	return choice;
}
