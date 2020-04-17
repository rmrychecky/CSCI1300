#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string RemoveHashTag(string a)
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
cout << RemoveHashTag("#SKO #Buffs") << endl;
	
cout << RemoveHashTag("#Monday #Motivation") << endl;
cout << RemoveHashTag("") << endl;
}
