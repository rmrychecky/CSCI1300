// Author: Raegan Rychecky CS1300 Fall 2018
// Recitation: 104 (8am) – Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/rmrychecky/csci1300
// Homework 2 - Problem 3

#include <iostream>
#include <iomanip>
using namespace std;

/**
 * Algorithm: calculate U.S. population in 1 year (365 days) using the input of initial population and given rates of change.
 * 1. Find how many seconds there are in one year.  
 * 2. Divide 1 year in seconds by 8 and add the resulting value to population.
 * 3. Divide 1 year in seconds by 12 and subtract the resulting value from population.
 * 4. Divide 1 year in seconds by 27 and add the resulting value to population.
 * Input parameters:The initial population as an integer.
 * Output:An integer that gives the value of population after 1 year.
 * Returns: nothing
 **/
 
 int population(int initialpopulation) //This function returns and has input values that are integers, and solves for the final population using given birth, death, and immigration rates.
 {
    int year = 31536000; //This is 1 year displayed in seconds.
    int rate1 = year / 8.0; //Gives the resulting value of the birth rate that should be added to population.
    int rate2 = year / 12.0; //Gives the resulting value of the death rate that should be subtracted from population.
    int rate3 = year / 27.0; //Gives the resulting value of the immigration rate that should be added to population.

    int population1 = initialpopulation + rate1; 
    int population2 = population1 - rate2; 
    int population3 = population2 + rate3; //Final population with rates acknowledged.
    return population3;
    
 }

int main() //Two test cases for the function.
{
    int pop = population(1000000);
    cout << pop << endl;
    
    int pop1 = population(2000000);
    cout << pop1 << endl;
    
}
