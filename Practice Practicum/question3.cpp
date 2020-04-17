#include <iostream>
#include <string>
using namespace std;

/**
 * Algorithm: takes int for strokes above/below par and return name of score 
 * 1. if number of strokes = -2 return eagle
 * 2. if number of strokes = -1 return birdie
 * 3. if number of strokes = 0 return par
 * 4. if number of strokes = 1 return bogie
 * 5. if number of strokes = 2 return double bogie
 * 6. if number of strokes = 3 return triple bogie
 * 7. if number of strokes does not equal on of these return no comment
 * Input parameters:takes an integer number for strokes
 * Output: N/A
 * Returns: string for name of score
 **/
 
 string GolfName (int numberofstrokes)
 {
  switch (numberofstrokes) 
       {
           case -2:
                return "EAGLE";
                break;
           case -1:
                return "BIRDIE";
                break;
           case 0:
                return "PAR";
                break;
           case 1:
                return "BOGIE";
                break;
           case 2:
                return "DOUBLE BOGIE";
                break;
           case 3:
                return "TRIPLE BOGIE";
                break;
           default:
                return "NO COMMENT";
       }
     
 }
 
 int main ()
 {
     cout << GolfName(-2) << endl;
     cout << GolfName(2) << endl;
     cout << GolfName(10) << endl;
 }