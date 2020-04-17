#include <iostream>
using namespace std;

/**
 * Algorithm: calculate the cost of students coffee consumption. 
 * 1. if numberofcups >= 12
 *  a. int reward number = number of cups / 12 
 *  b. number of cups = number of cups - reward number
 * 2. double total cost = number of cups * cost per cup
 * 3. return total cost;
 * Input parameters:takes an integer number of cups and double for cost per cup
 * Output: N/A
 * Returns: double for cost of coffee
 **/
 
 double CoffeeCost (int numberofcups, double costpercup)
 {
     if (numberofcups > 12)
     {
         int rewardnumber = numberofcups / 12;
         numberofcups =  numberofcups - rewardnumber;
     }
     double totalcost = numberofcups * costpercup;
     return totalcost;
 }
 
 
 
 int main ()
 {
     cout << CoffeeCost(12,3) << endl;
     cout << CoffeeCost(14,3) << endl;
     
     int a = 5;
     int b = 2;
     float c = a/b;
     cout << c << endl;
     
 }