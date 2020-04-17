#include <iostream>
#include <string>
using namespace std;

 int CountVowels(string string1)
{
    int numberofvowels = 0;
    for (int i = 0; i < string1.length(); i++)
    {
        if (string1[i] == 'a' || string1[i] == 'e' || string1[i] == 'i' || string1[i] == 'o' || string1[i] == 'u')
        {
            numberofvowels++;
        }
        if (string1[i] == 'A' || string1[i] == 'E' || string1[i] == 'I' || string1[i] == 'O' || string1[i] == 'U')
        {
            numberofvowels++;
        }
    }
    if (string1 == "")
    {
        return -1;
    }
    return numberofvowels;
}

int main()
{
cout << CountVowels("Asdflklsdajflasdkfjaeiou") << endl; //expected return: 8
 
}