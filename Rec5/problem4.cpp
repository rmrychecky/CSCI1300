#include <iostream>
#include <string>
using namespace std;


 int getLastIndex(char parameter, string sentence)
     {
        
        int lastindex = 0;
        if (sentence == "")
        {
            return -1;
        }
        for (int i = 0; i < sentence.length(); i++)
    	{
    	    
    	    if (sentence[i] == parameter) 
    	    {
    	       lastindex = i;
    	    }

        }
        if (lastindex == 0 && sentence[0] != parameter)
        {
            lastindex = -2;
        }
        return lastindex;
     }



int main() 
{
  
}



//str.substr(int start, int length)
//int isdigit (int c) //returns 1 if true and 0 if false