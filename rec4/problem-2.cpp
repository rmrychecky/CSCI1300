// CS1300 Fall 2018
// Author: Raegan Rychecky 
// Recitation: 104 (8am) – Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/rmrychecky/csci1300
// Recitation 4 - Problem 2

#include <iostream>
using namespace std;

/**
 * Algorithm: find and print all positive multiples of an integer <= max value.
 * 1. if the parameter or max input is 0 or parameter > max print out nothing.
 * 2. if parameter is 1 do the same for the others except max - 1
 * 1. if the maximum is even and greater than 0 while multiple is less than max - 2
 * 2. the multiplier is initialized to 1 and the output multiple is initialized to 0.
 * 3. multiple is parameter times t
 * 4. increment t by 1
 * 5. if the maximum is odd and greater than 0 while multiple is less than max - 2
 * 6. the multiplier is initialized to 1 and the output multiple is initialized to 0.
 * 7. multiple is parameter times t
 * 8. increment t by 1
 * Input parameters: an integer, and an integer representing the max value.
 * Output: print all the positive multiples of the first integer parameter less
 * than or equal to the max value
 * Returns: nothing
 **/
 
 
 void printMultiples(int parameter, int max) //The function is void because it returns nothing and will only cout integers.
 {
        if(parameter > max || parameter <= 0 || max <= 0) //This if statement encompasses situations when the parameter or max are <= 0
        {
          cout << "" << endl;
        }
        else if (parameter == 1)
        {
            int multiple1 = parameter; //initialize the output multiple to 0
            int i = 1; //the multiplier is initialed to 1
            while (multiple1 <= max ) //while loop occurs when multiple < the max value - 1
            {
                cout << multiple1 << endl; //print out the resulting values
                i++; //multiplier must be incremented by 1
                multiple1 = parameter * i; //the output multiple is computed as parameter*t
            }
            
        }
        else if (max % 2 == 0 && parameter > 0) //This if statement encompasses numbers that are even and parameters greater than 0
        {
            int multiple = parameter; //initialize the output multiple to 0
            int t = 1; //the multiplier is initialed to 1
            while (multiple <= max) //while loop occurs when multiple < the max value - 2
            {
               
                cout << multiple << endl; //print out the resulting values
                t++; //multiplier must be incremented by 1
                multiple = parameter * t; //the output multiple is computed as parameter*t
            }
            
       }
       else if (max % 2 != 0 && parameter > 0) //This if statement encompasses numbers that are odd and parameters greater than 0
       {
            int multiple1 = parameter; //initialize the output multiple to 0
            int i = 1; //the multiplier is initialed to 1
            while (multiple1 <= max - 1) //while loop occurs when multiple < the max value - 2
            {
                cout << multiple1 << endl; //print out the resulting values
                i++; //multiplier must be incremented by 1
                multiple1 = parameter * i; //the output multiple is computed as parameter*t
            }
       }
      
      
      
 }

int main() 
{
    // test 1
    // expected output
    // 3, 6, 9 (printed below each other)
    //printMultiples(3, 10);
    // test 2
    // expected output
    // 4, 8 (printed below each other)
    //printMultiples(4, 10);
    // test 3
    // expected output
    // 12, 24, 36 (printed below each other)
    //printMultiples(12, 36);
    // test 4
    // expected output
    // 0 
    //printMultiples(0, 10);
    // test 5
    // expected output
    // 0 
    //printMultiples(-5, -10);
    // test 6
    // expected output
    // 0
    //printMultiples(10, 0);
printMultiples(2, 10);
printMultiples(4, 17); 
printMultiples(15, 10); 
printMultiples(1, 7);
printMultiples(3, -10);
printMultiples(8, 12);

}

