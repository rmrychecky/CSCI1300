#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void PrintAsterisks()
{

    int j = 0;

    for (int i = 1; i <= 4; i++)
    {
        cout << "*";
        
        if (i == 4)
        {
            cout << endl;
            for (int i = 1; i <= 4; i++)
            {
                 cout << "*";
                 if (i == 4)
                 {
                     cout << endl;
                     for (int i = 1; i <= 4; i++)
                     {
                         cout << "*";
                         if (i == 4)
                         {
                             break;
                         }

                     }
                     
                 }
                 
            }
        }
    }
}
   
//void PrintAsterisks()
//{
//for(int i = 0; i<3; i++)
//{
//cout << "****" << endl;
//}
//}

int main()
{
PrintAsterisks();
}