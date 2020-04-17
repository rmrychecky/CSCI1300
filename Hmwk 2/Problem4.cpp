// Author: Raegan Rychecky CS1300 Fall 2018
// Recitation: 104 (8am) – Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/rmrychecky/csci1300
// Homework 2 - Problem 4

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

/**
 * Algorithm: Calculates luminosity with two inputs, brightness and distance.
 * 1. luminosity = 4*brightness*π*distance^2 
 *      a.π=3.14159
 * Input parameters:Brightness and distance as doubles.
 * Output:Value of luminosity as an integer.
 * Returns: nothing
 **/
  
 
 int luminosity(double b, double d) //This function outputs the integer value of luminosity using the double values of brightness and distance.
 {
    const double PI = 3.14159; //Pi is set to be a constant as specified in the instructions. It's value holds at 3.14159.
    int luminosity1 = 4 * b * PI * pow(d, 2); //Solves for luminosity.
    return luminosity1;

 }

int main() //Two test cases for the luminosity function.
{
    
    int lum1 = luminosity(1.5, 17.8);
    cout << lum1 << endl; //Outputs luminosity.
    
    int lum2 = luminosity(2.0, 20.9);
    cout << lum2 << endl;
    
}
