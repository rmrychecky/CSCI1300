#include <iostream>
#include <string>
#include <cmath>
using namespace std;


void dotsAndDashes(int n)
{
  if (n == 1)
  {
      cout << ".";
  }
  else 
  {
  for (int i =1; i <=n; i++)
  {
    for(int j=0; j<i; j++)
    {
      if (i % 2 == 0)
      {
        cout<<"-";
      }
      else
      {
        cout<<".";
      }
    }
    cout << endl;
  }
  }
}

int main()
{
//dotsAndDashes(6);
//dotsAndDashes(1);
dotsAndDashes(12);
}