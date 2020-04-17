#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void PrintNonLetters(string u)
{
    string temp = "";
    
    for(int s = 0; s < u.length(); s++)
    {
        if(u[s] != 'a' && u[s] != 'b' && u[s] != 'c' && u[s] != 'd' && u[s] != 'e' && u[s] != 'f' && u[s] != 'g' && u[s] != 'h' && u[s] != 'i' && u[s] != 'j' && u[s] != 'k' && u[s] != 'l' && u[s] != 'm' && u[s] != 'n' && u[s] != 'o' && u[s] != 'p' && u[s] != 'q' && u[s] != 'r' && u[s] != 's' && u[s] != 't' && u[s] != 'u' && u[s] != 'v' && u[s] != 'w' && u[s] != 'x' && u[s] != 'y' && u[s] != 'z' && u[s] != 'A' && u[s] != 'B' && u[s] != 'C' && u[s] != 'D' && u[s] != 'E' && u[s] != 'F' && u[s] != 'G' && u[s] != 'H' && u[s] != 'I' && u[s] != 'J' && u[s] != 'K' && u[s] != 'L' && u[s] != 'M' && u[s] != 'N' && u[s] != 'O' && u[s] != 'P' && u[s] != 'Q' && u[s] != 'R' && u[s] != 'S' && u[s] != 'T' && u[s] != 'U' && u[s] != 'V' && u[s] != 'W' && u[s] != 'X' && u[s] != 'Y' && u[s] != 'Z')
        {
            temp += u[s]; 
        }
    }
    if(u == "")
    {
        temp = "NULL";
    }
    if(temp == "")
    {
        temp = "-2";
    }
    cout << temp << endl;

}
   

int main()
{
PrintNonLetters("one1, two2");
PrintNonLetters("Test3: 2 String.");
}