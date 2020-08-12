/****************
**
**	Name:		Eric Johnson
**	Date:		5/21/19
**	Description:	Header file for Character node struct - this node holds a pointer to a Character
**			and a pointer to the next Character, and a pointer to the previous Character
**			in a linked list
**
***************/

#ifndef CHARACTERNODE_HPP
#define CHARACTERNODE_HPP

#include "Character.hpp"

struct CharacterNode
{
	CharacterNode* next;
	CharacterNode* prev;
	Character* characterPtr;
};

#endif 			// CHARACTERNODE_HPP
