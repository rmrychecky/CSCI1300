#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void modifyVector(vector<int>& v)
{
   int value;
   while (value > 0)   
   {
      cout << "Please enter an integer value: " << endl;
      cin >> value;
      
      if (value <= 0)
      {
            return;
      }
      else if (v.size() == 0)
      {
            v.push_back(value);
      }
      else if (value % 5 == 0)
      {
            v.erase(v.begin());
      }
      else if (value % 3 == 0)
      {
            v.pop_back();
      }
      else 
      {
            v.push_back(value);
      }
      
   }
      
}

int main ()
{
      
}