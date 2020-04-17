#include <iostream>
#include <string>
using namespace std;

string removeStars(string a)
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
        if (a[i] != '*')
        {
            temp += a[i];
        }

    }
    return temp;
    }

}
   

int main()
{
// cout << removeStars("HelloWorld***") << endl;
// cout << removeStars("H*e*l*l*oWorld") << endl;

// string str = "C++Program";
// cout << str.substr(1, 2);

// string name = "Eiffel";
// string attraction = "Tower";
// string destination = name + " " + attraction;
// cout << destination.length();

// string stripes = "=====";
// int i = 4;
// while (i > 0)
// {
//     cout << stripes.substr(0, 5-i) << "|" ;
//     i--;
// }

for (int i = -5; i <= 5; i = i + 2)
{
    cout << "Hi" << endl;
}

}