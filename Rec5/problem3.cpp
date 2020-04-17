#include <iostream>
#include <string>
using namespace std;

     int getMatchCount(string substring, string sentence)
     {
        int match = 0;
        if (substring == "" || sentence == "")
        {
            return -1;
        }
        if (substring.length() > sentence.length())
        {
            return -2;
        }
        for (int i = 0; i < sentence.length(); i++)
    	{
    	    
    	    if (sentence.substr(i, substring.length()) == substring) 
    	    {
    	       match++;
    	    }
    	   
        }
        return match;
     }


int main() 
{
    // test 1
    // expected output
    // 2
    cout << getMatchCount("si", "mississippi") << endl;
    // test 2
    // expected output
    // 1
    cout << getMatchCount("ipp", "mississippi") << endl;
    cout << getMatchCount("cat", "at") << endl;

}



//str.substr(int start, int length)
//int isdigit (int c) //returns 1 if true and 0 if false