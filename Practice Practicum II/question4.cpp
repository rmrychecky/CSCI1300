#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool IsPrime(int x)
{
    bool frog = 1;
    if (x < 0)
    {
        x = x * -1;
    }
    if (x == 1)
    {
        frog = 0;
    }
    
    for(int i = x - 1; i > 1; i--)
    {
        if(x % i==0)
        {
            frog = 0;
        }
    }
    return frog;
}


int main()
{
cout << IsPrime(3) << endl;
cout << IsPrime(4) << endl;
cout << IsPrime(2) << endl;
cout << IsPrime(0) << endl;
cout << IsPrime(9) << endl;

}