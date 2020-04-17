// CS1300 Fall 2018
// Author: Raegan Rychecky 
// Recitation: 104 (8am) – Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/rmrychecky/csci1300
// Homework 3 - Problem 2

#include <iostream>
using namespace std;

/**
 * Algorithm: Takes an integer as input and returns the number of digits in the range -1000 to 1000
 * 1. If input < 0 first multiply the input by -1 
 * 2. If it is < 10 then return 1
 * 3. If input >= 10 and < 100 the return is 2.
 * 4. If input >= 100 and < 1000 the return is 3.
 * 5. Else return is 4
 * Input parameters:an integer number.
 * Output: an integer
 * Returns: an integer (number of digits)
 **/
 
 int countDigits(int num) //This function has both integer inputs and outputs
 {
    if(num < 0)
    {
        num = -1 * num; //When the number is negitive it first must be multiplied by -1 in order to projress through the function.
    }
    if(num < 10)
    {
        return 1; //If a number is less than 10 it will only have one digit
    }
    if(num >= 10 && num < 100)
    {
        return 2; //If a number is greater than or equal to 10 and if it is less than 100 it will have 2 digits.
    }
    if(num >= 100 && num < 1000)
    {
        return 3; //If a number is greater than or equal to 100 and less than 1000 it iwll have 3 digits.
    }
    else 
    {
        return 4; //Otherwise it will have four digits.
    }
    
 }

int main() //Test cases for the function countDigits
{
   int number = countDigits(-10); //2
   cout << number << endl; 
   
   int number1 = countDigits(0); //1
   cout << number1 << endl; 
   
   int number2 = countDigits(10); //2
   cout << number2 << endl; 
   
   int number3 = countDigits(100); //3
   cout << number3 << endl; 
   
   int number4 = countDigits(1000); //4
   cout << number4 << endl; 
   
   int number5 = countDigits(-1000); //4
   cout << number5 << endl; 
   
   int number6 = countDigits(-143); //3
   cout << number6 << endl;
   
}
