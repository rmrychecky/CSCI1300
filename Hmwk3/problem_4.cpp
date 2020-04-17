// CS1300 Fall 2018
// Author: Raegan Rychecky 
// Recitation: 104 (8am) – Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/rmrychecky/csci1300
// Homework 3 - Problem 4 (EXTRA CREDIT)

#include <iostream>
using namespace std;

/**
 * Algorithm: Use the 9 inputs to decide which doors are opened on the minivan. The function returns nothing.
 * 1. If the gear is P
 *  2. If the master lock is off
 *    3. If the child lock is off
 *      4. If the left dash, inside left latch, or outside left latch is 1 and the right dash, inside right latch, or outside right latch is 1 the doors stay open.
 *      5. If the right dash, right inside latch, or right outside latch is 1 and the left dash, left inside latch, and the left outside latch is 0, then the right door opens.
 *      6. If the right dash, right inside latch, and right outside latch is 0 and the left dash, left inside latch, and left outside latch is 1, the left door opens.
 *      7. If the right dash, right inside latch, and right outside latch is 0 and the left dash, left inside latch, and left outside latch is 0, both doors stays closed.
 *      8. Else (when the child lock is on)
 *      9. If the left dash or left outside latch is 1 and the right dash or right outside latch is 1, both doors are open.
 *      10. If the right dash and right outside latch is 1 and the left dash and left outside latch is 0, the right door opens.
 *      11. If the left dash or left outside latch is 1 and the right dash and right outside latch is 0, the left door opens.
 *      12. If the left outside latch and left dash is 0 and the right outside latch and right dash is 0, both doors stay closed.
 *  13. Else print out both doors stay closed.
 * Input parameters: 8 bool variables and 1 char variables.
 * Output: print out a statement that says "Left door opens", "Right door opens", "Both doors open", or "Both doors stay closed".
 * Returns: nothing
 **/
 
void vehicle(bool dash_left, bool dash_right, bool child_lock, bool master_lock, bool inside_latchL, bool outside_latchL, bool inside_latchR, bool outside_latchR, char gearshift) 
{
      if(gearshift == 'P') //Gearshift is park
      {
        if(master_lock == 0) //Master lock is 0
        {
          if(child_lock == 0) //Child lock is 0
          {
            if((dash_left == 1 || inside_latchL == 1 || outside_latchL == 1) && (dash_right == 1 || inside_latchR == 1 || outside_latchR == 1))
            {
              cout << "Both doors open" << endl; //If the left dash, inside left latch, or outside left latch is 1 and the right dash, inside right latch, or outside right latch is 1 the doors stay open. 
            }
            if((dash_right == 1 || inside_latchR == 1 || outside_latchR == 1) && (dash_left == 0 && inside_latchL == 0 && outside_latchL == 0))
            {
              cout << "Right door opens" << endl; //If the right dash, right inside latch, or right outside latch is 1 and the left dash, left inside latch, and the left outside latch is 0, then the right door opens.
            }
            if((dash_right == 0 && inside_latchR == 0 && outside_latchR == 0) && (dash_left == 1 || inside_latchL == 1 || outside_latchL == 1))
            {
              cout << "Left door opens" << endl; //If the right dash, right inside latch, and right outside latch is 0 and the left dash, left inside latch, and left outside latch is 1, the left door opens.
            }
            if((dash_right == 0 && inside_latchR == 0 && outside_latchR == 0) && (dash_left == 0 && inside_latchL == 0 && outside_latchL == 0))
            {
              cout << "Both doors stay closed" << endl; //If the right dash, right inside latch, and right outside latch is 0 and the left dash, left inside latch, and left outside latch is 0, both doors stays closed.
            }
          }
          else //child lock is on
          {
            if((dash_left == 1 || outside_latchL == 1) && (dash_right == 1 || outside_latchR == 1))
            {
              cout << "Both doors open" << endl; //If the left dash or left outside latch is 1 and the right dash or right outside latch is 1, both doors are open.
            }
            if((dash_right == 1 && outside_latchR == 1) && (dash_left == 0 && outside_latchL == 0))
            {
              cout << "Right door opens" << endl; //If the right dash and right outside latch is 1 and the left dash and left outside latch is 0, the right door opens.
            }
            if((dash_left == 1 || outside_latchL == 1) && (dash_right == 0 && outside_latchR == 0))
            {
              cout << "Left door opens" << endl; //If the left dash or left outside latch is 1 and the right dash and right outside latch is 0, the left door opens.
            }
            if((outside_latchL == 0 && dash_left == 0) && (outside_latchR == 0 && dash_right == 0))
            {
              cout << "Both doors stay closed" << endl; //If the left outside latch and left dash is 0 and the right outside latch and right dash is 0, both doors stay closed.
            }
          }
        }
      } 
      else
      {
        cout << "Both doors stay closed" << endl; //Else print out both doors stay closed.
      }
        
}
 

int main() //Test cases for the function vehicle
{
    vehicle(0, 0, 1, 0, 0, 1, 1, 0, 'P'); //left door opens
    vehicle(0, 0, 1, 0, 0, 1, 1, 0, 'N'); //both closed
    vehicle(1, 0, 1, 0, 1, 1, 0, 1, 'P'); //both open
    vehicle(0, 0, 1, 0, 1, 1, 0, 0, 'R'); //both closed
    vehicle(0, 0, 0, 0, 0, 0, 1, 0, 'P'); //both open
}
