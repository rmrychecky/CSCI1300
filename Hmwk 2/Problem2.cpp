// Author: Raegan Rychecky CS1300 Fall 2018
// Recitation: 104 (8am) – Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/rmrychecky/csci1300
// Homework 2 - Problem 2

#include <iostream>
#include <iomanip> //Must include in order to set precision.
using namespace std;

/**
 * Algorithm: takes temperature value in degrees Celsius as input and converts it to temperature in Fahrenheit.
 * 1. Take the temperature in Celsius passed to the function
 * 2. Calculate degrees Fahrenheit as (9/5) * celsius + 32.
 * Input parameters:temperature in Celsius as an integer.
 * Output:a string that gives: The temperature of (input) in fahrenheit is (degreesF).
 * Returns: nothing
 **/
 
 void celsiusToFahrenheit(int degreesCelsius) //This funciton is void becase it does not return anything. It solves for fahrenheit given degrees Celsius.
 {
    
     double fahrenheit = degreesCelsius*(9.0/5.0) + 32.0; //Operation that solves for fahrenheit as a double value.
     cout << fixed << setprecision(2) << "The temperature of " << degreesCelsius << " in fahrenheit is " << fahrenheit << endl; //This print out statement also sets the decimal precision to two, so the resulting degrees in fahrenheit will be given up to two decimals.
 }

int main() //Two test cases for the function celsiusToFahrenheit.
{
    celsiusToFahrenheit(38);

    celsiusToFahrenheit(45);
    return 0;
    
}
