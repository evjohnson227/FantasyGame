/**********************
**
**	Name:		Eric Johnson
**	Date:		5/9/19
**	Description:	Main function for Fantasy Combat game - seeds random number generator, creates game
**			and players
*********************/

#include "Character.hpp"
#include "CharacterQueue.hpp"
#include "CharacterNode.hpp"
#include "Tournament.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "Blue_Men.hpp"
#include "Medusa.hpp"
#include "Harry_Potter.hpp"
#include "inputValidation.hpp"
#include "menu.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(time(NULL));

	int choice;
	Tournament t;

	do
	{
		t.playTournament();
	
		choice = continuePlaying();
	} while (choice != 2);

	return 0;
}
	
