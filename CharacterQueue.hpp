/****************
**
**	Name:		Eric Johnson
**	Date:		5/21/19
**	Description:	Header file for Character Queue class which is a circular linked list - contains a data member	**			for the head of the queue of Character objects
**
***************/

#ifndef CHARACTERQUEUE_HPP
#define CHARACTERQUEUE_HPP

#include "CharacterNode.hpp"
#include "Character.hpp"
#include <iostream>
#include <string>

class CharacterQueue
{
	private:
		 CharacterNode* head;

	public:
		CharacterQueue();
		CharacterQueue(CharacterNode* headIn);
		~CharacterQueue();
		bool isEmpty();
		void addBack(Character* characterIn);
		void moveHead();
		Character* getFront();
		void removeFront();
		void printCharacterQueue();
};

#endif 					// CHARACTERQUEUE_HPP
