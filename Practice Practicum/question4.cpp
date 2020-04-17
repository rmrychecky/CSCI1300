#include <iostream>
using namespace std;

/**
 * Algorithm: cost to paint a house
 * if any input < 0 return -1
 * 1. costwd = numberwd * 6.75
 * 2. perimeter = 2 * (width + depth)
 * 3. if perimeter <= 100 costwalls = 8 * perimeter
 * 4. if perimeter <= 200 
 *  a. new perimeter = perimeter - 100
 *  b. costwalls = 800 + (10 * new perimeter)
 * 5. if perimeter > 200 costwalls = perimeter * 15
 * 6. double totalcost = costwalls + costwd
 * 7. return totalcost;
 * Input parameters:takes an integer for width, depth, and number of windows/doors
 * Output: N/A
 * Returns: double for total cost of work
 **/
 
 double PaintHouse (int width, int depth, int numberwd)
 {
    if (width < 0 || depth < 0 || numberwd < 0)
    {
       return -1;
    }
  double costwd = numberwd * 6.75;
  double costwalls;
  int newperimeter;
  int perimeter = 2 * (width + depth);
  
    if (perimeter <= 100)
    {
       costwalls = 8 * perimeter;
    }
    if (perimeter > 100 && perimeter <= 200)
    {
       newperimeter = perimeter - 100;
       costwalls = 800 + (10 * newperimeter);
    }
    if (perimeter > 200)
    {
       newperimeter = perimeter - 200;
       costwalls = 1800 + (15 * newperimeter);
    }
  double totalcost = costwalls + costwd;
  return totalcost;
 }
 
 int main ()
 {
    cout << PaintHouse(15,25,8)<<endl;
 }