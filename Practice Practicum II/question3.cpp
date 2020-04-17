#include <iostream>
#include <string>
using namespace std;

bool IsAllLower(string u)
{
    for(int s = 0; s<u.length(); s++)
    {
        if(u[s] != 'a' && u[s] != 'b' && u[s] != 'c' && u[s] != 'd' && u[s] != 'e' && u[s] != 'f' && u[s] != 'g' && u[s] != 'h' && u[s] != 'i' && u[s] != 'j' && u[s] != 'k' && u[s] != 'l' && u[s] != 'm' && u[s] != 'n' && u[s] != 'o' && u[s] != 'p' && u[s] != 'q' && u[s] != 'r' && u[s] != 's' && u[s] != 't' && u[s] != 'u' && u[s] != 'v' && u[s] != 'w' && u[s] != 'x' && u[s] != 'y' && u[s] != 'z' && u[s])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
cout << IsAllLower("OneTwo") << endl;
cout << IsAllLower("onetwo") << endl;

 
}