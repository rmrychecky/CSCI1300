// Author: Raegan Rychecky CS1300 Fall 2018
// Recitation: 104 (8am) – Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/rmrychecky/csci1300
// Homework 2 - Problem 1

#include <iostream>
using namespace std;

/**
 * Algorithm: takes seconds (call seconds time) as input and converts it to hours, minutes, and seconds.
 * 1. Take the value of seconds passed to the function
 * 2. Calculate hours as input/3600.
 * 3. Caclulate minutes as remaining input/60.
 * 4. Caclulate seconds as remaining input from calculation 2.
 * Input parameters:seconds as an integer.
 * Output:a string that gives: xhour(s) yminute(s) zsecond(s).
 * Returns: nothing
 **/
 
 void convertSeconds(int time) //This function does not have a return so it's output is type void. It also only accepts 1 input, time as an integer.
 {
     int hours = time / 3600; //This solves for time in hours from the seconds input as an integer.
     int time1 = time % 3600; //This gives the remaining input in seconds left after finding hours.
     int minutes = time1 / 60; //Caclulates time in minutes from the remaining seconds.
     int time2 = time1 % 60; //Gives the remaining input in seconds after finding hours and minutes.
     int seconds = time2; //Time in seconds is the remainder after all other operations are preformed.
     
     cout << hours << " hour(s) " << minutes << " minute(s) " << seconds << " second(s)" << endl;
 }

int main() //Two test cases for the function convertSeconds.
{
    convertSeconds(3671);
    convertSeconds(5280);
    return 0;
    
}
