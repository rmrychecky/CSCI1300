#include <iostream>
using namespace std;

 double calculateCost (double distance, double avgSpeed, double gasPrice)
 {
      int mpg;
      if (avgSpeed > 62)
      {
          mpg = 26;
      }
      else 
      {
          mpg = 30;
      }
      double tripCost = (distance / mpg) * gasPrice;
      return tripCost;

 }
 
 
 
 int main ()
 {
     cout << calculateCost(600, 60, 2.5) << endl;
     cout << calculateCost(520, 65, 2.2) << endl;

 }