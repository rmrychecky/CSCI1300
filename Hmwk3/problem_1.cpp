// CS1300 Fall 2018
// Author: Raegan Rychecky 
// Recitation: 104 (8am) – Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/rmrychecky/csci1300
// Homework 3 - Problem 1

#include <iostream>
using namespace std;

/**
 * Algorithm: Takes one integer and returns the next integer value in the Collatz sequence.
 * 1. If input < 0 then the function returns 0.
 * 2. Else if input % 2 is 0 then the next value should be solved as n/2.
 * 3. Else the next value should be 3n + 1
 * Input parameters:an integer number.
 * Output: an integer
 * Returns: an integer
 **/
 
 int collatzStep(int num) //This function has both integer inputs and outputs as shown. It will output the next integer value in the Collatz sequence.
 {
     if(num < 0)
     {
         return 0; //When there is a negative number this if statement will return 0.
     }
     else if((num % 2) == 0)
     {
         int nextnum = num / 2; //When a number is divisible by 2 it is even so it will return the input value divided by two.
         return nextnum;
     }
     else
     {
         int nextnum = 3*num + 1; //If it is not even or negative then it is odd, and the return value will be 3num + 1.
         return nextnum;
     }
    
 }

int main() //Test cases for the function collatzStep
{
   int nextnumber = collatzStep(10); //5
   cout << nextnumber << endl; 
   
   int nextnumber1 = collatzStep(7); //22
   cout << nextnumber1 << endl; 
   
   int nextnumber2 = collatzStep(0); //0
   cout << nextnumber2 << endl; 
   
   int nextnumber3 = collatzStep(-5); //0
   cout << nextnumber3 << endl; 
   
}
