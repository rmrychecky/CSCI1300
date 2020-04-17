// CS1300 Fall 2018
// Author: Raegan Rychecky 
// Recitation: 104 (8am) – Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/rmrychecky/csci1300
// Recitation 4 - Problem 4

#include <iostream>
using namespace std;

/**
 * Algorithm: print a diamond with given side length (with respect to screen)
 * 1. initialize length, size, and numstar to 1, and spaces to parameter - 1
 * 2. for the top half of the diamond
 *  3. while the row is <= the parameter
 *   4. while spaces is greater than the value of i you will print out a space, subtract a space and add 1 to i.
 *   5. while column <= numstar print an asterisk and increment the column by 1.
 *   6.reset column to 1 and move to the next row.
 *   7.increment numstar by 2 and size by 1
 * 8.set spaces to 1 and numstar to 2*parameter - 3
 * 9.for the bottom half of the diamond
 *  10. while the row is >= 1
 *   11. while spaces is greater than the value of i you will print out a space, add 1 to spaces and add 1 to i.
 *   12. while the length is <= numstar print an asterisk and increment the length by 1.
 *   13. reset column to 1 and move to the next row.
 *   14. subtract 2 from numstar, and 1 from size.
 * Input parameters: an integer representing side length
 * Output: print diamond with given side length
 * Returns: nothing
 **/
 
 
 void printDiamond(int parameter) //The function is void because it returns nothing and will only cout the diamond
 {
    
         int length = 1; //column
         int size = 1; //row
         int numstar = 1; //number of stars present
         int spaces = parameter - 1; //number of spaces before each asterisk
         
         while (size <= parameter)
         {
              int i = 1;
              while (i <= spaces) //while spaces is greater than the value of i you will print out a space, subtract a space and add 1 to i.
              {
                cout << " ";
                i++;
              }
              spaces--;
              
             while (length <= numstar) //while column <= numstar print an asterisk and increment the column by 1.
             {
                 cout << "*";
                 length++;
             }
            length = 1;    
            cout << endl;
            
           

             numstar++; //add two stars each time
             numstar++;
             size++; //add a row each time
         }
         
         numstar = 2*parameter - 3; //set spaces to 1 and numstar to 2*parameter - 3
         spaces = 1;
         
         while (size >= 1) //while the row is >= 1
         {
             int i = 1;
              while (i <= spaces) //while spaces is greater than the value of i you will print out a space, add 1 to spaces and add 1 to i.
              {
                cout << " ";
                i++;
              }
              spaces++;
              
             while (length <= numstar) //while the length is <= numstar print an asterisk and increment the length by 1.
             {
                 cout << "*";
                 length++;
             }
            length = 1;   //set column to 1 and move to the next row 
            cout << endl;

             numstar--; //subtract two stars each time
             numstar--;
             size--; //counting down rows 
         }
 }

int main() 
{
    // test 1
    // expected output
    // diamond with side length 4 and middle row of 7
    printDiamond(4);
    // test 2
    // expected output
    // nothing
    printDiamond(0);
    // test 3
    // expected output
    // diamond with side length 7 and middle row of 13
    printDiamond(7);
    // test 4
    // expected output
    // nothing
    printDiamond(-5);
}
