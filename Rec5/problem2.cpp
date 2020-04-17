#include <iostream>
#include <string>
using namespace std;

     int getDigitCount(string sentence)
     {
        int d = 0;
        char digit;
        for (int i = 0; i <= sentence.length(); i++)
    	{
    	    
    	    if (sentence[i] == '0' || sentence[i] == '1' || sentence[i] == '2' || sentence[i] == '3' || sentence[i] == '4' || sentence[i] == '5' || sentence[i] == '6' || sentence[i] == '7' || sentence[i] == '8' || sentence[i] == '9') 
    	    {
    	        d++;
    	    }
      
        }
        return d;

     }


int main() 
{
    // test 1
    // expected output
    // 5 
    cout << getDigitCount("12345") << endl;
    // test 2
    // expected output
    // 0 
    cout << getDigitCount("a blue house") << endl;
    // test 3
    // expected output
    // 1 
    cout << getDigitCount("a0aaa") << endl;
    // test 4
    // expected output
    // 4 
    cout << getDigitCount("abre1567") << endl;
     // test 5
    // expected output
    // 4 
    cout << getDigitCount("009cD8") << endl;
     // test 6
    // expected output
    // 1 
    cout << getDigitCount("!%$o9bf&^") << endl;
}

