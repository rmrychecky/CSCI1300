// CS1300 Fall 2018
// Author: Raegan Rychecky 
// Recitation: 104 (8am) – Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/rmrychecky/csci1300
// Recitation 3 - Problem 3

#include <iostream>
using namespace std;

/**
 * Algorithm: takes a single integer input and returns 1 if it is a leap year and 0 if it isn't.
 * 1. If input <= 1582 and input % 4 is 0 then it is a leap year (return true).
 * 2. Else if input > 1582 and input % 400 is 0 or input % 4 is 0 and the input % 100 is not 0 it is a leap year.
 * 3. Else if input > 1582 and input % 100 is 0 or input % 4 is 0 not a leap year.
 * 4. Else it is not a leap year. 
 * Input parameters: integear representing a year.
 * Output: 0 or 1 (type bool)
 * Returns: 1 if it is a leap year or 0 if it isn't
 **/
 
 bool checkLeapYear(int year) //Function to test leap years with one input (int)
 {
      if(year <= 1582 && (year % 4) == 0)
      {
          bool checkLeapYear = true; //Returns true if conditions are met
          return true;
      }
      else if(year > 1582 && ((year % 400) == 0 || (year % 4) == 0 && (year % 100) != 0)) //Must make sure conditions are mutually exclusive
      {
          bool checkLeapYear = true; //Returns true if conditions are met
          return true;
      }
      else if(year > 1582 && (year % 100) == 0 || (year % 4) == 0)
      {
          bool checkLeapYear = false; //Returns false if conditions are met 
          return false;
      }
      else
      {
          bool checkLeapYear = false; //Returns false after checking other statements
          return false;
      }
       
 }
 
int main() //Test cases for the function checkLeapYear.
{
   bool test1 = checkLeapYear(1616);
   cout << test1 << endl;
   
   bool test2 = checkLeapYear(1981);
   cout << test2 << endl;
   
   bool test3 = checkLeapYear(1500);
   cout << test3 << endl;
   
   bool test4 = checkLeapYear(1700);
   cout << test4 << endl;
   
   bool test5 = checkLeapYear(2000);
   cout << test5 << endl;
   
   bool test6 = checkLeapYear(1501);
   cout << test6 << endl;
   
   bool test7 = checkLeapYear(1600);
   cout << test7 << endl;
   
   
}
