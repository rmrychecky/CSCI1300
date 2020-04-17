// CS1300 Fall 2018
// Author: Raegan Rychecky 
// Recitation: 104 (8am) – Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/rmrychecky/csci1300
// Recitation 3 - Problem 1

#include <iostream>
using namespace std;

/**
 * Algorithm: takes one integer parameter, returns nothing, and prints if the integer is positive, negative, or zero.
 * 1. If the input is < 0 then print out negative.
 * 2. Else if the input = 0 print out zero.
 * 3. Else print out positive.
 * Input parameters:an integer number.
 * Output:"positive", "negative", or "zero"
 * Returns: nothing
 **/
 
 void numberSign(int num) //This function is void because it returns nothing.
 {
        if(num < 0) 
        {
            cout << "negative"; //Execute if condition 1 is TRUE
        }
        else if(num == 0) 
        {
            cout << "zero"; //Execute if condition 1 is FALSE and condition 2 is TRUE
        }
        else
        {
            cout << "positive"; //Execute if FALSE
        }
 
 }

int main() //Test cases for the function numberSign.
{
   numberSign(0); 
   numberSign(6);
   numberSign(-7); 
}
