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

1. Turn total is initialized to 0. Game total human and computer is initialized to 0.  Player is initialized to 1. declare dice roll and answer.
2. Create function playerTotal 
    1. Check for player 1 if game_totalhuman = turn_total + game_totalhuman
    2. Return game_totalhuman
    3. Check for player 2 if game_totalcomputer = turn_total + game_totalcomputer
    4. Return game_totalcomputer
3. Create function turnTotal 
    1. If the dice roll is 1 or 6 then the turn total is 0
    2. If the dice roll is 3 then the turn total is 15
    3. If the dice roll is a 2, 4, or 5 then the turn_total = turn_total + dice roll 
    4. Return the resulting turn_total
4. Create function afterTurnHuman
    1. If the game total of the human is >= 100 then print out the congratulation statement for the human
5. Create function afterTurnComputer
    1. If the game total of the computer is >= 100 then print out the congratulation statement for the computer
6. Void game function
    1. Printout welcome statement and say it is now the human’s turn
    2. Player is initialized to 1
    3. While the game total of the computer and human is < 100 
        1. Turn total is 0
        2. Ask if they want to roll a dice
        3. Cin the answer
        4. If the player is the human
            1. While the answer is yes
                1. Roll the dice
                2. If the dice roll is a 1, 6, or 3
                    1. cout you rolled a 
                    2. Cout turn total
                    3. Cout human/computer game total
                    4. If the game total for the human is >= 100 then break
                    5. Else print out it is the computers turn
                3. If the dice roll is 2, 4, or 5
                    1. Cout you rolled a
                    2. Cout turn total
                    3. Ask if they want to roll again
                    4. Cin the answer
            2. While the answer is no
                1. If the answer is no/player is 1
                    1. Cout human/computer game totals
                    2. Cout its the computer’s turn
                    3. Set player to 2
        5. If player is the computer
            1. Turn total is initialized to 0
                1. While the turn total is less than 10
                    1. Roll the dice
                    2. If dice roll is 1, 6, 3
                        1. Cout computer rolled a
                        2. Cout turn total
                        3. Cout computer/human total game scores
                        4. If the computer total is >= 100 then break
                        5. Else out it is the human’s turn
                    3. If the dice roll is 2, 4, or 5
                        1. Cout dice roll/turn total
                2. If the game total for either computer or human is >= 100
                3. Else if the turn_total is >= 10 and the player is the computer
                    1. Cout game total computer
                    2. Check after turn computer
                    3. If it is >=100 break
                    4. Else out human game total/it is now the humans turn
    4. After turn computer check

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
 		turn_total = 0;

 	}
 	if (diceroll == 3) //how do you end turn
 	{
 		turn_total = 15;

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

	player = 1; //player is initalized to human
	
	while (game_totalcomputer < 100 && game_totalhuman < 100) //while the game totals are less than 100
	{
		turn_total = 0;
		//char answer;
		cout << "Do you want to roll a dice (Y/N)?:" << endl; //first ask if they want to roll dice
		cin >> answer;
		if (player == 1); //if the player is the human
		{
			turn_total = 0; //initalize turn total to 0
		
			while ((answer == 'Y' && player == 1) || (answer == 'y' && player == 1)) //while the answer is yes and the player is the human
			{
			
				diceroll = rollDice(); //roll the dice
				
				if (diceroll == 1 || diceroll == 6 || diceroll == 3) // if the dice roll is a 1, 3, or 6
				{
					cout << "You rolled a " << diceroll << endl;
					turnTotal(diceroll); //call turn total funciton and input dice roll
					cout << "Your turn total is " << turn_total << endl;
					game_totalhuman = playerTotal(turn_total);
					cout << "computer: " << game_totalcomputer << endl;
					cout << "human: " << game_totalhuman << endl << endl;
					afterTurnHuman(game_totalhuman); //call the after turn human function and input the game total for the human
					if(game_totalhuman >= 100){ //if the game total is >= 100 complete this if statement
						break;
					}
					else {cout << "It is now computer's turn" << endl << endl;} //if not pass turn to computer
					player = 2;
				}
				
				if (diceroll == 2 || diceroll == 4 || diceroll == 5) //if the dice roll is a 2, 4, or 5
				{
					cout << "You rolled a " << diceroll << endl;
					turnTotal(diceroll); //call turn total funciton and input dice roll
					cout << "Your turn total is " << turn_total << endl;
					cout << "Do you want to roll again (Y/N)?:" << endl; //ask the user if they want to roll again
					cin >> answer;
				}

				
			
			}
			while ((answer == 'N' && player == 1) || (answer == 'n' && player == 1)) //while the answer is no stay in this loop
			{
				if ((answer == 'N' && player == 1) || (answer == 'n' && player == 1)); //if it is no
				{
					game_totalhuman = playerTotal(turn_total); //update the game total for the human
					cout << "computer: " << game_totalcomputer << endl; //print out both game totals
					cout << "human: " << game_totalhuman << endl << endl;
					cout << "It is now computer's turn" << endl << endl; //pass the turn to the computer
					player = 2;
				}
			}
			
		}
		
		if (player == 2) //if the player is the computer
		{
			turn_total = 0; //initialize the turn total to 0
			while (turn_total < 10 && player == 2) //while the turn total is less than 10 and the player is the computer stay in this loop
			{
				diceroll = rollDice(); //roll the dice
					
				if (diceroll == 1 || diceroll == 6 || diceroll == 3) //if the roll is a 1, 6, or 3
				{
					cout << "Computer rolled a " << diceroll << endl; 
					turnTotal(diceroll); //execute function for turn total based on dice roll
					cout << "Computer turn total is " << turn_total << endl; //print the turn total
					game_totalcomputer = playerTotal(turn_total); //update the game total for the computer
					cout << "computer: " << game_totalcomputer << endl;
					cout << "human: " << game_totalhuman << endl << endl;
					if(game_totalcomputer >= 100){ //if the game total for the computer exceeds 100 then break
						break;
					}
					else{
					cout << "It is now human's turn" << endl << endl; //else pass turn to the human
					player = 1;
					}
				}
			
				if (diceroll == 2 || diceroll == 4 || diceroll == 5) //if the dice roll is a 2, 4 or 5
				{
					cout << "Computer rolled a " << diceroll << endl;
					turnTotal(diceroll);
					cout << "Computer turn total is " << turn_total << endl;
				}
					
			}
			
			
			if(game_totalcomputer >= 100 || game_totalhuman >= 100)
			{ //if one of the game totals exceeds 100
				
			}
			else //else if the turn total is >= 10 and the player is the computer
			{
			if (turn_total >= 10 && player == 2)
			{
				player = 2;
				game_totalcomputer = playerTotal(turn_total); //find game total for the computer
				cout << "computer: " << game_totalcomputer << endl;
				afterTurnComputer(game_totalcomputer); //check the after turn computer function
				if(game_totalcomputer >= 100){
					break; //see if game breaks or continues
				}else{
				cout << "human: " << game_totalhuman << endl << endl;							
				cout << "It is now human's turn" << endl << endl; //if the game continues pass turn to human
				player = 1;
				}
			}

			player = 1;
			}
		}
	
	afterTurnComputer(game_totalcomputer); //check after turn for the computer again
			
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
