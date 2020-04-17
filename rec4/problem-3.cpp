// CS1300 Fall 2018
// Author: Raegan Rychecky 
// Recitation: 104 (8am) – Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/rmrychecky/csci1300
// Recitation 4 - Problem 3

#include <iostream>
using namespace std;

/**
 * Algorithm: print a filled and hollow square of given width side by side to the screen. The two squares are separated by a single space.
 * 1. print the rows first while the value of the row is less than the value of the width
 * 2. while the column number is less than the width print and asterisk and increment the column by 1
 * 3. reset the column after completing one square
 * 4. print a blank column before the second square
 * 5. while the column is less than the value of the width
 * 6. if you are in the first or last row print asterisks
 * 7. if you are in the first or last column print asterisks, and if you are not print blank spaces
 * 8. increment the length by 1
 * 9. move to the next row and reset the column number to 0
 * Input parameters: an integer representing width of 1 square
 * Output: print 2 squares (1 filled, 1 hollowed)
 * Returns: nothing
 **/
 
 
 void printSquares(int width) //The function is void because it returns nothing and will only cout the squares
 {
    
         int length = 0; //column
         int size = 0; //row
         
          while (size < width) //print the rows
          {
              while (length < width) //print across width times
              {
              cout << "*"; //print out an asterisk
              length++; //increment column by 1 each time
              }
              length = 0; //reset column to 0
              
              cout << " "; //after printing out all the columns print a space column
              
              while (length < width) //special cases for the second square fall under this loop
              {
                  if (size == 0 || size == width - 1) //if you are in the first or last row
                  {
                      cout << "*"; //print askerisks
                    
                  }
                  else 
                  {
                      if (length == 0 || length == width - 1) //if you are in the first or last column print askerisks
                      {
                      cout << "*";
                      }
                      else
                      {
                      cout << " ";   //if you are not print blank spaces 
                      }
                  }
                  
                  length++; //increment the length each time
              }
              length = 0; //reset the columns to 0
              
              cout << endl; //move to the next line
              size++; //when moving to the next line you will also want to increment the row by 1
          }
  
 }

int main() 
{
    // test 1
    // expected output
    // 2 five by five squares with the one on the right hollowed out
    printSquares(5);
    // test 2
    // expected output
    // nothing
    printSquares(0);
    // test 3
    // expected output
    // 2 eight by eight squares with one on the right hollowed out
    printSquares(8);
    // test 4
    // expected output
    // nothing
    printSquares(-5);
}

