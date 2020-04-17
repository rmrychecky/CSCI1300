#include <iostream>
using namespace std;

 double smallestNumber (double a, double b, double c)
 {
  double smallest;
      if (a < 0)
      {
       smallest = a;
      }
      else if (b < 0)
      {
       smallest = b;
      }
      else if (c < 0)
      {
       smallest = c;
      }
      else 
      {
         if (a > b || a == b)
         {
         smallest = b;
         }
         else 
         {
         smallest = a;
         }
         if (b > c || b == c)
         {
         smallest = c;
         }
         else 
         {
         smallest = b;
         }
         if (a > c || a == c)
         {
         smallest = c;
         }
         else
         {
         smallest = a;
         }
      }
     

      
      return smallest;
      
 }
 
 
 
 int main ()
 {
     cout << smallestNumber(4, 9, 2.5) << endl;
     cout << smallestNumber(17.2, 3.2, 26.4) << endl;
     cout << smallestNumber(2.5,10,17)<<endl;
     cout << smallestNumber(1,1,2.5)<<endl;
     cout << smallestNumber(20,-3.3,25)<<endl;

 }