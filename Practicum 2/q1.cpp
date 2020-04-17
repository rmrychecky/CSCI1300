#include <iostream>
#include <string>
using namespace std;

int CountAtoJ(string a)
{
    int k = 0;
    if (a == "")
    {
      k = -1;
    }
    else 
    {
       for (int i = 0; i <= a.length(); i++)
       {
          if(a[i] == 'A' || a[i] == 'B' || a[i] == 'C' || a[i] == 'D' || a[i] == 'E'|| a[i] == 'F'|| a[i] == 'G' || a[i] == 'H'|| a[i] == 'I'|| a[i] == 'J')
          {
             k++;
          }
       }
       if (k == 0)
       {
       k = -2;
       }
    }
    return k;

}

int main()
{
cout << CountAtoJ("ALL THE BEST") << endl; 
cout << CountAtoJ("") << endl; 
cout << CountAtoJ("all the best") << endl; 
}