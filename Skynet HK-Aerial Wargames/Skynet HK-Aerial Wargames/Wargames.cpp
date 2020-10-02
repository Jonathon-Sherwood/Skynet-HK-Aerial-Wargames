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
using std::endl; //Global declaration to shorten the endl command namespace throughout the code

int main() //Starting function containig our code found in every C++ file 
{
	srand(time(NULL)); //Uses computer time for random seed
	int searchGridHighNumber = 64; //Sets the highest parameter for searching
	int searchGridLowNumber = 1; //Sets the lowest parameter for searching
	int randomEnemy = rand() % 64 + 1; //Designates a random enemy location
	int guess = rand() % 64 + 1; //Starts Skynet with random search within parameters
	int ping = 1; //Holds the amount of attempts per loop
	bool testBegin = false; //Allows for test reset

	cout << "Generate Random enemy location on 8x8 grid...." << endl;
	cout << "The enemy is located at location #" << randomEnemy << " on 8x8 grid with 1-64 sectors." << endl;
	cout << "Skynet HK-Aerial Initializing software....." << endl;
	cout << "====================================================================" << endl;

	do //Entire test loop contained
	{
		do //Tests for higher/lower numbers each check
		{
			testBegin = false; //Disables overall loop until completion

			cout << "Skynet HK-Aerial Radar sending out ping #" << ping << endl;

			if (guess < randomEnemy) //Adjusts lower parameter on low guess
			{
				cout << "The target location prediction of " << guess << " was lower than the actual enemy location of " << randomEnemy << "." << endl;
				searchGridLowNumber = guess + 1;
				cout << "The new searchGridLowNumber = " << searchGridLowNumber << endl;
				cout << "====================================================================" << endl;
			}
			else if (guess > randomEnemy) //Adjusts higher parameter on high guess
			{
				cout << "The target location prediction of " << guess << " was higher than the actual enemy location of " << randomEnemy << "." << endl;
				searchGridHighNumber = guess;
				cout << "The new searchGridHighNumber = " << searchGridHighNumber << endl;
				cout << "====================================================================" << endl;
			}
			else //Cancels entire loop if guessed on first ping
			{
				break;
			}

			//Starts loop over with new guess based on changes
			guess = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;

			++ping; //Increments up the number of guesses

		} while ((guess != randomEnemy)); //Continues loop until correct guess

		if (guess == randomEnemy) //Resets game on input after correct guess
		{
			cout << "Skynet HK-Aerial Radar sending out ping #" << ping << endl;
			cout << "Enemy was hiding at location #" << randomEnemy << endl;
			cout << "Target was found at location #" << guess << endl;
			cout << "Skynet HK-Aerial Software took " << ping << " predictions to find the enemy location on a grid size of 8x8 (64)." << endl;
			cout << "Press any key to continue . . . ";

			std::cin.get(); //Awaits user return
			system("CLS"); //Clears screen

			//Resets all variables for next test
			testBegin = true;
			searchGridHighNumber = 64;
			searchGridLowNumber = 1;
			randomEnemy = rand() % 64 + 1;
			guess = rand() % 64 + 1;
			ping = 1;
		}
	} while (testBegin); //Returns loop to the beginning of the entire test procedure

	return 0;
}