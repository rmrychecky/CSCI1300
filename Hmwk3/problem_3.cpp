// CS1300 Fall 2018
// Author: Raegan Rychecky 
// Recitation: 104 (8am) – Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/rmrychecky/csci1300
// Homework 3 - Problem 3

#include <iostream>
using namespace std;

/**
 * Algorithm: Takes an integer value that represents month and prints out the number of days in the month.
 * 1. Use a switch with the int month
 * 2. Create conditions for each individual month coupled with c out statements.
 * 3. Create a default case where the month is invalid if none of the cases are met.
 * Input parameters:an integer number which represents the month.
 * Output: prints out the number of days in the month as "Month" <month> "has x (or y) days" or "Invalid month number"
 * Returns: none
 **/
 
 void daysOfMonth(int month) //This function will cout a statement after calculating days in the month using a switch so it is of return type void.
 {
       switch(month) //This switch will cout a statement after calculating days in the month.
       {
           case 1:
                cout << "Month " << month << " has 31 days" << endl; //Each number represents a month
                break;
           case 2:
                cout << "Month " << month << " has 28 or 29 days" << endl; //Every month will be printed out with the number of days it has.
                break;
           case 3:
                cout << "Month " << month << " has 31 days" << endl;
                break;
           case 4:
                cout << "Month " << month << " has 30 days" << endl;
                break;
           case 5:
                cout << "Month " << month << " has 31 days" << endl;
                break;
           case 6:
                cout << "Month " << month << " has 30 days" << endl;
                break;
           case 7:
                cout << "Month " << month << " has 31 days" << endl;
                break;
           case 8:
                cout << "Month " << month << " has 31 days" << endl;
                break;
           case 9:
                cout << "Month " << month << " has 30 days" << endl;
                break;
           case 10:
                cout << "Month " << month << " has 31 days" << endl;
                break;
           case 11:
                cout << "Month " << month << " has 30 days" << endl;
                break;
           case 12:
                cout << "Month " << month << " has 31 days" << endl;
                break;
           default:
                cout << "Invalid month number" << endl; //If a month entered does not fit one of the 12 cases then it will print out month is invalid.
            
       }
    
 }

int main() //Test cases for the function daysOfMonth
{
    daysOfMonth(5); //Month 5 has 31 days
    daysOfMonth(4); //Month 4 has 30 days
    daysOfMonth(1); //Month 1 has 31 days
    daysOfMonth(13); //Invalid month number
    
}
