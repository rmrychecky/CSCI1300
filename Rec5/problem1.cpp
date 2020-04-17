#include <iostream>
#include <string>
using namespace std;

     int getWordCount(string sentence)
     {
        int w = 0;
        if (sentence == "")
        {
            return 0;
        }
    	for (int i = 0; i <= sentence.length(); i++)
    	{
    	   
    	    if (sentence[i] == ' ')
    	    {
    	        w++;
    	    }
    	    
    	}
    	return w + 1;

     }


int main() 
{
    // test 1
    // expected output
    // 1 
    cout << getWordCount("Go") << endl;
    // test 2
    // expected output
    // 2 
    cout << getWordCount("I went") << endl;
    // test 3
    // expected output
    // 5 
    cout << getWordCount("Colorless green ideas dream furiously") << endl;
    // test 4
    // expected output
    // 9 
    cout << getWordCount("The rat the cat the dog bit chased escaped") << endl;
}

