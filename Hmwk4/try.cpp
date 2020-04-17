// CSCI1300 Fall 2018
// Author: Raegan Rychecky
// Recitation: <104> – Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/rmrychecky/csci1300
// Project1 

///////////////////////////////////////////////////////////////////////////////////////////////////
// Step1: Steps to solve this problem
// write an algorithm in pseudocode explaining on how you are approaching the problem, step by step 
///////////////////////////////////////////////////////////////////////////////////////////////////

/*

1. initialize player to user outside of the function void game().
void game()
2. if player is user
	a. cout "continue rolling or hold"
		i. if cin = "hold" pass turn to computer
		ii. else
			while continue rolling = true 
			a.rollDice ()
				-if roll is 1 or 6 turn ends and pass turn to computer
				-if roll is 3 turn ends and turnTotal = 15
				-if roll is 2, 4, or 5, add dice to turnTotal
3. if player is computer
	a. rollDice()
    b. roll until turnTotal >= 10
    c. end turn and pass to user
4. when turn ends update player total as turnTotal + playerTotal
5. if playerTotal computer >= 100 cout "Congratulations! computer won this round of jeopardy dice!"
6. if playerTotal human >= 100 cout "Congratulations! human won this round of jeopardy dice!"

*/

///////////////////////////////////////////////////////////////////////////////////////////////////
// Step2: Code it up! 
// After finishing up your pseudocode, translate them into c++ 
// IMPORTANT: rollDice() and main() are already written for you.
// You need to complete game function as well as at least 3 other additional functions
///////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
using namespace std; 

 int turn_total = 0;
 int game_totalhuman = 0;
 int game_totalcomputer = 0;
 int player = 1;
 int diceroll;
 char answer;
 
 
/**
 * rollDice 
 * returns a random integer between 1 and 6, works as rolling a dice.
 * return value, int number (1-6)
 */

int rollDice()
{
	return random() % 6 + 1; 
}

/**
 * playerTotal 
 * turnTotal plus previous playerTotal
 * updates everytime
 * the function returns an integer value
 */

 int playerTotal (int turn_total)
 {
 	if (player == 1)
 	{
 		game_totalhuman = turn_total + game_totalhuman;
 		return game_totalhuman;
 	}
 	if (player == 2)
 	{
 		game_totalcomputer = turn_total + game_totalcomputer;
 		return game_totalcomputer;
 	}
 }
 
 /**
 * turnTotal 
 * added numbers from dice or special exception when 1, 6, or 3.
 * the function returns an integer value 
 */

 int turnTotal (int diceroll)
 {
 	if (diceroll == 1 || diceroll == 6) //how do you end turn
 	{
 		turn_total = turn_total + 0;
		answer = 'n';

 	}
 	if (diceroll == 3) //how do you end turn
 	{
 		turn_total = turn_total + 15;

 	
 	}
 	if (diceroll == 2 || diceroll == 4 || diceroll == 5)
 	{
 		turn_total = turn_total + diceroll;
 	}
 	return turn_total;
 }
 
 /**
 * afterTurn functions for computer and human
 * check if the playerTotal has accumulated to 100 or above
 * the function returns nothing
 */
 
 void afterTurnHuman (int game_totalhuman)
 {
 	if (game_totalhuman >= 100)
 	{
 		cout << "Congratulations! human won this round of jeopardy dice!" << endl;
 	}
 }
 
 void afterTurnComputer (int game_totalcomputer)
 {
 	if (game_totalcomputer >= 100)
 	{
 		cout << "Congratulations! computer won this round of jeopardy dice!" << endl;
 	}
 }
 
/**
 * game 
 * driver function to play the game
 * the function does not return any value
 */

void game()
{
	cout << "Welcome to Jeopardy Dice!" << endl << endl;
	cout << "It is now human's turn" << endl << endl;

	player = 1;
	
	while (player == 1 && game_totalcomputer < 100 && game_totalhuman < 100)
	{
		turn_total = 0;
		//char answer;
		cout << "Do you want to roll a dice (Y/N)?:" << endl;
		cin >> answer;
		if (answer == 'Y' || answer == 'y');
		{
			turn_total = 0;
		
			while (answer == 'Y'|| answer == 'y')
			{
				diceroll = rollDice();
				
				if (diceroll == 1 || diceroll == 6 || diceroll == 3)
				{
					cout << "You rolled a " << diceroll << endl;
					turnTotal(diceroll);
					cout << "Your turn total is " << turn_total << endl;
					game_totalhuman = playerTotal(turn_total);
					cout << "computer: " << game_totalcomputer << endl;
					cout << "human: " << game_totalhuman << endl << endl;
					cout << "It is now computer's turn" << endl << endl;
					player = 2;
				}
				else
				{
					cout << "You rolled a " << diceroll << endl;
					turnTotal(diceroll);
					cout << "Your turn total is " << turn_total << endl;
					cout << "Do you want to roll again (Y/N)?:" << endl;
					cin >> answer;
				}

			}

			if (answer == 'N' || answer == 'n');
			{
				game_totalhuman = playerTotal(turn_total);
				cout << "computer: " << game_totalcomputer << endl;
				cout << "human: " << game_totalhuman << endl << endl;
				cout << "It is now computer's turn" << endl << endl;
				player = 2;
			}
			
		

			while (player == 2 && game_totalcomputer < 100 && game_totalhuman < 100)
			{
				
				turn_total = 0;
				while (turn_total < 10)
				{
					diceroll = rollDice();
					cout << "Computer rolled a " << diceroll << endl;
					turnTotal(diceroll);
					cout << "Computer turn total is " << turn_total << endl;
				}
			
				if (turn_total >= 10)
				{
					player = 2;
					game_totalcomputer = playerTotal(turn_total);
					cout << "computer: " << game_totalcomputer << endl;
					afterTurnComputer(game_totalcomputer);
				}

				player = 1;
				game_totalhuman = playerTotal(0);
				cout << "human: " << game_totalhuman << endl << endl;							
				cout << "It is now human's turn" << endl << endl;
			}
			
			

			afterTurnComputer(game_totalcomputer);
			afterTurnHuman(game_totalhuman);
		}
	
	

	}	
	
	
		
}
	

///////////////////////////////////////////////////////////////////////////////////////////////////
// don't change the main. 
// Once you finished please paste your code above this line 
///////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	// start the game! 
	game();
	return 0;
}