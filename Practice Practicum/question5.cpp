#include <iostream>
using namespace std;
 
 double TuitionCost (int units, double costperunit)
 {
     double cost;
     if (units < 0 || costperunit < 0)
     {
         return -1;
     }
     if (units > 16)
     {
         cost = 16 * costperunit + ((units - 16) * (.5*costperunit));
     }
     else 
     {
         cost = units * costperunit;
     }
     return cost;
  
 }
 
 int main ()
 {
    cout << TuitionCost(16,200)<<endl;
    cout << TuitionCost(17,300)<<endl;
 }