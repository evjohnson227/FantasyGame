/***********
**
**	Name:		Eric Johnson
**	Date:		5/21/19
**	Description:	Implementation file for Character Queue class - contains one data member for the head of
**			the queue of Character objects
**
***********/

#include "CharacterQueue.hpp"
#include "CharacterNode.hpp"

// Adapted from Lab7 Circular Linked List
// Default constructor that sets the head of the Character queue to null
CharacterQueue::CharacterQueue()
{
	head = NULL;
}

// Constructor that takes an address to a Character Node and uses it to initialize the head of the Character Queue
CharacterQueue::CharacterQueue(CharacterNode* headIn)
{
	head = headIn;
}

// Method that returns true if the Character Queue is empty
bool CharacterQueue::isEmpty()
{
	if (head == NULL)
	{
		return true;
	}

	return false;
}

// Method that takes an address to a Character as a parameter, creates a Character Node with it and appends
// it to the back of the queue
void CharacterQueue::addBack(Character* characterIn)
{
	// If Character queue is empty set the head and queue loop
	if (isEmpty() == true)
	{
		head = new CharacterNode;
		head->characterPtr = characterIn;
		head->next = head;
		head->prev = head;
	}

	// Add new Character node to the queue
	else
	{
		// Initialize new node to be at the end of the queue
		CharacterNode* newCharacterNode = new CharacterNode;
		newCharacterNode->characterPtr = characterIn;
		newCharacterNode->prev = head->prev;
		newCharacterNode->next = head;

		// Set previous back's next pointer to the new Character Node
		head->prev->next = newCharacterNode;
		
		// Set head's previous pointer to the new back
		head->prev = newCharacterNode;
	}
}

// Method that moves the head of the queue to the next node
void CharacterQueue::moveHead()
{
	if (isEmpty() == true)
	{
		std::cout << "Queue is empty." << std::endl;
		return;
	}

	else
	{
		head = head->next;
	}
}

// Method that returns the name of the character in the node at the front of the queue
Character* CharacterQueue::getFront()
{
	// Notify user that Character queue is empty
	if (isEmpty() == true)
	{
		std::cout <<  "Character Queue is empty." << std::endl;
		return NULL;
	}

	return head->characterPtr;
}

// Method that removes the front Character Node of the queue and frees the memory
void CharacterQueue::removeFront()
{
	// Notify user that the queue is empty
	if (isEmpty() == true)
	{
		std::cout << "Character lineup is empty." << std::endl;
	}

	// Delete head if it is the only character node in the queue
	else if (head == head->next)
	{
		delete head;
		head = NULL;
	}

	// Remove first Character node of the queue
	else
	{
		CharacterNode* tempNode = head;
		
		// Set head to the node after the current head
		head = head->next;

		// Set head's previous pointer to old head's previous pointer
		head->prev = tempNode->prev;

		// Set previous back's next pointer to the new head
		head->prev->next = head;

		// Free allocated memory
		delete tempNode;
		
	}
}

// Method that traverses through the queue from the head using next pointers, and prints the character name,
// type, armor, and strength points of each Character Node in the queue
void CharacterQueue::printCharacterQueue()
{
	CharacterNode* traverseNode = head;
	int counter = 1;

	// If list is empty, notify user
	if (isEmpty() == true)
	{
		std::cout << "Queue is empty." << std::endl;
	}

	else
	{
		std::cout << "Your lineup is: " << std::endl;

		// Loop to display Character name and type
		do
		{
			std::cout << "Character " << counter << ": " << std::endl;
			std::cout << "Name: " << traverseNode->characterPtr->getName() << std::endl;
			std::cout << "Type: " << traverseNode->characterPtr->getType() << std::endl;
			std::cout << "Armor: " << traverseNode->characterPtr->getArmor() << std::endl;
			std::cout << "Strength Points: " << traverseNode->characterPtr->getStrengthPoints() << std::endl;
			std::cout << std::endl;
			traverseNode = traverseNode->next;
			counter++;

		} while (traverseNode != head);

		std::cout << std::endl;
	}
}

// Destructor that frees all allocated memory using removeFront() method
// Adapted from Starting Out With C++ Early Objects
CharacterQueue::~CharacterQueue()
{
	while (!isEmpty())
	{
		removeFront();
	}
}

