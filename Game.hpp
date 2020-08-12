/************
**
**	Name:		Eric Johnson
**	Date:		5/9/19
**	Description:	Game class header file - consists of two characters representing players in the game; constructor that takes
**			two parameters and uses them to initialize the data members; method to create objects based on user's character
**			choice; method to simulate character battle
**
**********/

#ifndef GAME_HPP
#define GAME_HPP

#include "Character.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "Blue_Men.hpp"
#include "Medusa.hpp"
#include "Harry_Potter.hpp"
#include "menu.hpp"
#include "inputValidation.hpp"

class Game
{
	private:
		Character *player1;
		Character *player2;

	public:
		Game(Character *player1In, Character *player2In);
		void setPlayerCharacters();
		void playGame();
};

#endif			// GAME_HPP

