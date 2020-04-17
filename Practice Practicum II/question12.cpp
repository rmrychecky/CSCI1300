#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string ReplaceHashTag(string a)
{
    string temp = "";
    if (a == "")
    {
        temp += "";
    }
    else
    {
    for (int i = 0; i <= a.length() - 1; i++)
    {
        if (a[i] == '#')
        {
            temp += '@';
        }
        if (a[i] != '#')
        {
            temp += a[i];
        }

    }
    return temp;
    }

}
   

int main()
{
cout << ReplaceHashTag("#SKO #Buffs") << endl;

}
