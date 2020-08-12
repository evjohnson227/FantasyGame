/*************
**
**	Name:		Eric Johnson
**	Date:		5/11/19
**	Description:	Input validation function - takes two parameters for minimum and maximum value, validates and returns an integer
**
***********/

#include "inputValidation.hpp"

// Adapted from Group 4's Predator-Prey Game Project
int getInt(int min, int max)
{
	std::string input;
	bool correctInput = false;
	int intValue;

	// Continue asking for input until input is correct
	while (!correctInput)
	{
		bool correctFormat = true;

		std::cout << "Please choose a number between: " << min << " and " << max << std::endl;

		std::getline(std::cin, input);

		// Check that each char is an int
		int inputLen = input.length();
		if (inputLen >= 1)
		{
			for (int i = 0; i < inputLen; i++)
			{
				if (!isdigit(input.at(i)))
				{
					correctFormat = false;
				}

			}

			// Test that entire input is an integer
			if (correctFormat)
			{
				intValue = std::stoi(input);
				if (intValue >= min && intValue <= max)
				{
					correctInput = true;
				}
			}
		}
		std::cout << std::endl;
	}

	return intValue;
}


		


