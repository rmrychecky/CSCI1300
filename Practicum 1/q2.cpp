#include <iostream>
#include <string>
using namespace std;

 string mileage (int flightdistance)
 {
      if (flightdistance >= 0 && flightdistance <= 10000)
      {
       return "Bronze";

      }
      if (flightdistance >= 10001 && flightdistance <= 15000)
      {
       return "Silver";

      }
      if (flightdistance >= 15001 && flightdistance <= 30000)
      {
       return "Gold";

      }
      if (flightdistance > 30000)
      {
       return "Platinum";

      }
      else 
      {
       return "INVALID";
      }

 }
 
 
 
 int main ()
 {
     cout << mileage(0) << endl;
     cout << mileage(500) << endl;
     cout << mileage(15001) << endl;
     cout << mileage(16000) << endl;
     cout << mileage(40000) << endl;
     cout << mileage(-12) << endl;

 }