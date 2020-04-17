// CS1300 Fall 2018
// Author: Raegan Rychecky 
// Recitation: 104 (8am) – Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/rmrychecky/csci1300
// Recitation 3 - Problem 2

#include <iostream>
using namespace std;

/**
 * Algorithm: takes two double inputs representing hours worked and hourly pay rate and returns the calculated total pay. Hours worked > 40 are 1.5x pay rate.
 * 1. If hours worked or pay rate < 0 return "Pay rate and hours worked cannot be negative valeus."
 * 2. Else if hours worked or pay rate = 0 return 0.
 * 2. Else if hours worked is <= 40 then calculate total pay as hours * pay rate.
 * 3. Else if hours worked > 40 calculate total pay as (hours - 40)*(1.5pay rate) + (40*pay rate)
 * Input parameters: hours worked and hourly pay rate as type double.
 * Output: Total pay as type double
 * Returns: Total pay as type double
 **/
 
 double calcPay(double hours_worked, double pay_rate) //This function has two double inputs and outputs a double as well.
 {
        if(hours_worked < 0 || pay_rate < 0)
        {
            cout << "Pay rate and hours worked cannot be negative values." << endl; //Cannot have negative hours or payrate. This if statement takes care of these cases.
        }
        else if(hours_worked == 0 || pay_rate == 0)
        {
            return 0; //Return 0 if one of the inputs is 0.
        }
        else if(hours_worked <= 40) 
        {
            double total_pay = hours_worked * pay_rate; //Execute if condition 1 is TRUE
            return total_pay; //Return value back to int main()
        }
        else if(hours_worked > 40)
        {
            double total_pay = (hours_worked - 40)*(1.5 * pay_rate) + (40 * pay_rate); //Execute if condition 1 is FALSE and condition 2 is TRUE
            return total_pay; //Return value back to int main()
        }
       
       
 }

int main() //Test cases for the function calcPay.
{
   double total_pay1 = calcPay(35.0, 5.00); //Create a variable to store each test case in and print out
   cout << "$" << total_pay1 << endl; 
   
   double total_pay2 = calcPay(40.0, 10.00);
   cout << "$" << total_pay2 << endl; 
   
   double total_pay3 = calcPay(41.0, 10.00);
   cout << "$" << total_pay3 << endl; 
   
   double total_pay4 = calcPay(-5.0, 10.00);
  
   double total_pay5 = calcPay(40.0, -10.00);
   
   double total_pay6 = calcPay(0, 10.00);
   cout << "$" << total_pay6 << endl; 
   
   double total_pay7 = calcPay(41.0, 0);
   cout << "$" << total_pay7 << endl; 

}
