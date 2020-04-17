// CS1300 Fall 2018
// Author: Raegan Rychecky 
// Recitation: 104 (8am) – Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/rmrychecky/csci1300
// Recitation 4 - Problem 1

#include <iostream>
using namespace std;

/**
 * Algorithm: find and print all positive even integers <= max value.
 * 1. (for even max) original output is initialized to 0
 * 2. while (output < max) you add two to the output (to get even numbers), and print it out
 * 3. (for odd max) original output is initialized to 0
 * 4. while (output1 < max - 1) you add two to the output, and print it out
 *  a.MAX - 1 is important or else you will print out the next even integer after the max value!!
 * Input parameters: an integer representing the max value.
 * Output: print the positive even integers <= max value
 * Returns: nothing
 **/
 
 
 void printEvenNums(int max) //The function is void because it returns nothing and will only cout integers.
 {
    
       if (max % 2 == 0) //This if statement encompasses numbers that are even
       {
            int output = 0; //initial output is 0
            while (output < max)
            {
                output = output + 2; //output will be updated each time the while loop is executed (2 will be added)
                cout << output << endl; //print out the resulting values
            }
       }
       if (max % 2 != 0) //This if statement encompasses numbers that are odd (not divisible by 2)
       {
            int output1 = 0; //initial output is 0
            while (output1 < max - 1) //Here you must say max - 1 or else the even integer value following the max will also print!
            {
                output1 = output1 + 2; //output1 will be updated each time the while loop is executed (2 will be added)
                cout << output1 << endl; //print out the resulting values
            }
       }
     
 
 }

int main() 
{
    // test 1
    // expected output
    // nothing should print
    printEvenNums(0);
    // test 2
    // expected output
    // 2, 4, 6, 8, 10 (printed below each other)
    printEvenNums(10);
    // test 3
    // expected output
    // 2, 4, 6, 8, 10 (printed below each other)
    printEvenNums(11);
    // test 4
    // expected output
    // 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 (printed below each other)
    printEvenNums(20);
    // test 5
    // expected output
    // 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 (printed below each other)
    printEvenNums(21);
    // test 6
    // expected output
    // nothing should print
    printEvenNums(-10);
 
}

