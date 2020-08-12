/**********
**
**	Name:		Eric Johnson
**	Date:		5/22/19
**	Description:	Tournament class header file - contains four data members - 2 queues to hold the lineups
**			of characters for each team, 2 queues to hold the losers of each team - methods to 
**			initiate the tournament and show the results of the tournament 
**
*********/

#ifndef TOURNAMENT_HPP
#define TOURNAMENT_HPP

#include "Character.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "Blue_Men.hpp"
#include "Medusa.hpp"
#include "Harry_Potter.hpp"
#include "CharacterNode.hpp"
#include "CharacterQueue.hpp"
#include "menu.hpp"
#include "inputValidation.hpp"
#include <iostream>
#include <string>
#include <limits>


class Tournament
{
	private:
		CharacterQueue* team1;
		CharacterQueue* team1Losers;
		CharacterQueue* team2;
		CharacterQueue* team2Losers;

	public:
		Tournament();
		~Tournament();
		Tournament(CharacterQueue* team1In, CharacterQueue* team2In);
		void playTournament();
};

#endif					// TOURNAMENT_HPP
