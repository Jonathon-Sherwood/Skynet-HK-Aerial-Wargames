/*
	Jonathon Sherwood
	10/2/2020
	Skynet HK-Ariel: Wargames: Grid-Based Targetting System for Loop practice with multiple players
*/

#include <iostream> //Used to display messages to the console
#include <cstdlib> //Used to generate random numbers
#include <stdlib.h> //Allows for changing the seed of the randomiser
#include <time.h> //Allows access to the computer's time for the seed

using std::cout; //Global declaration to shorten the cout command namespace throughout the code
using std::cin; //Global declaration to shorten the cout command namespace throughout the code
using std::endl; //Global declaration to shorten the endl command namespace throughout the code

int main() //Starting function containig our code found in every C++ file 
{
	srand(time(NULL)); //Uses computer time for random seed

	int randomEnemy = rand() % 64 + 1; //Designates a random enemy location

	int humanGuess; //Holds the value of the user's guess
	int humanPing = 1; //Holds the amount of attempts per loop

	int searchGridHighNumber = 64; //Sets the highest parameter for searching
	int searchGridLowNumber = 1; //Sets the lowest parameter for searching
	int binaryGuess = rand() % 64 + 1; //Starts Skynet with random search within parameters
	int binaryPing = 1; //Holds the amount of attempts per loop

	int linearGuess = 1; //Starts the linear guess at the lowest number
	int linearPing = 1; //Holds the amount of attempts per loop

	int randomGuess = rand() % 64 + 1; //Starts Skynet with random search within parameters;
	int randomPing = 1; //Holds the amount of attempts per loop

	char playerResponse; //Checks for player input to play again

	bool testBegin = false; //Allows for test reset

	do //Entire test loop contained
	{
		testBegin = false; //Stops the overall do-while loop from looping till the end

		//HUMAN GUESSES
		do 
		{
			cout << "WHAT IS YOUR FEEBLE HUMAN GUESS." << endl;
			cin >> humanGuess;

			if (humanGuess < randomEnemy) //Warns the player they guessed too low
			{
				cout << "INCORRECT HUMAN. " << humanGuess << " IS TOO LOW.\n" << endl;
			}
			else if (humanGuess > randomEnemy) //Warns the player they gussed too high
			{
				cout << "INCORRECT HUMAN. " << humanGuess << " IS TOO HIGH.\n" << endl;
			} 
			else //Cancels entire loop if HUMAN guessed on first ping
			{
				break;
			}

			humanPing++; //Adds up attempts per loop

		} while (humanGuess != randomEnemy); //Ends loop on successful guess

		//BINARY DRONE
		do //Tests for higher/lower numbers each check using Binary Search
		{
			if (binaryGuess < randomEnemy) //Adjusts lower parameter on low binaryGuess
			{
				searchGridLowNumber = binaryGuess + 1;
			}
			else if (binaryGuess > randomEnemy) //Adjusts higher parameter on high binaryGuess
			{
				searchGridHighNumber = binaryGuess;
			}
			else //Cancels entire loop if binaryGuessed on first attempt
			{
				break;
			}

			//Starts loop over with new binaryGuess based on changes
			binaryGuess = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;

			++binaryPing; //Adds up attempts per loop

		} while ((binaryGuess != randomEnemy)); //Ends loop on successful guess

		//LINEAR DRONE
		do //Counts up one guess at a time
		{
			linearGuess++;
			linearPing++; //Adds up attempts per loop
		} while (linearGuess != randomEnemy); //Ends loop on successful guess

		//RANDOM DRONE
		do //Randomizes guess each loop
		{
			randomGuess = rand() % 64 + 1;
			randomPing++;//Adds up attempts per loop
		} while (randomGuess != randomEnemy); //Ends loop on successful guess

		if (humanGuess == randomEnemy) //Resets game on input after correct binaryGuess
		{
			cin.ignore(); //Allows for new user input

			cout << "\nALL DRONES HAVE DISCOVERED THE ENEMY HIDING AT " << randomEnemy << ".\n" << endl;
			cout << "IT APPEARS IT TOOK THE FEEBLE HUMAN " << humanPing << " ATTEMPTS TO FIND THE ENEMY." << endl;
			cout << "IT TOOK THE BINARY DRONE " << binaryPing << " ATTEMPTS TO FIND THE ENEMY." << endl;
			cout << "IT TOOK THE PATHETIC LINEAR DRONE " << linearPing << " ATTEMPTS TO FIND THE ENEMY." << endl;
			cout << "IT TOOK THE MALFUNCTIONING RANDOM DRONE " << randomPing << " ATTEMPTS TO FIND THE ENEMY." << endl;
			cout << "\nDO YOU WISH TO TEST AGAIN. Y/N ";

			do //Repeats the question until a valid input
			{
				cin >> playerResponse;
				if (playerResponse == 'y')  //Resets all variables for next test
				{
					system("CLS"); //Clears screen
					testBegin = true;
					searchGridHighNumber = 64;
					searchGridLowNumber = 1;
					randomEnemy = rand() % 64 + 1;
					binaryGuess = rand() % 64 + 1;
					linearGuess = 1;
					randomGuess = rand() % 64 + 1;
					binaryPing = 1;
					humanPing = 1;
					randomPing = 1;
					linearPing = 1;
				}
				else if(playerResponse == 'n') //Exits program on user input
				{
					exit(0);
				}
				else 
				{
					cout << "THAT IS NOT A VALID INPUT. Y/N ";
				}
			} while (playerResponse != 'n' && playerResponse != 'y'); //Exits the loop on a valid input
		}
	} while (testBegin); //Returns loop to the beginning of the entire test procedure

	return 0;
}