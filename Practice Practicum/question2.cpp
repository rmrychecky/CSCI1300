#include <iostream>
using namespace std;

/**
 * Algorithm: calculate the total cost of gas.
 * 1. if input is <= 0 cout invalid input and return 0
 * 2. if units <= 100 totalcost = 1.23*units
 * 3. if units <= 200 
 *  a. int newunits = units - 100
 *  b int totalcost = 123 + (newunits*1.14)
 * 3. if units > 200
 *  a. newunits = units - 200
 *  b. int totalcost = 237 + (newunits*1.08) 
 * Input parameters:takes an integer for units
 * Output: incorrect input for invalid parameter values
 * Returns: double cost or 0
 **/
 
 double GasBill (int units)
 {
  double totalcost;
  int newunits;
     if (units < 0)
     {
      cout << "Incorrect input" << endl;
      return 0;
     }
     if (units <=100)
     {
      totalcost = units * 1.23;
     }
     if (units > 100 && units <= 200)
     {
      newunits = units - 100;
      totalcost = 123 + (newunits * 1.14);
     }
     if (units > 200)
     {
      newunits = units - 200;
      totalcost = 237 + (newunits * 1.08);
     }
     return totalcost;
 }
 
 int main ()
 {
     cout << GasBill(244) << endl;
     cout << GasBill(82) << endl;
     cout << GasBill(-10) << endl;
     cout << GasBill(0) << endl;
 }