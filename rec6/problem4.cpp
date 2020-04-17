#include <iostream>
#include <string>
using namespace std;

int split(string ssplit, char delimiter, string words[], int maximum)
{
    string string1;
    int j = 0;
    int h = 0;
    
    int k = 0;
    for (int i = 0; i < ssplit.length(); i++) //spaces at the beginning 
    {
        if (ssplit[i] == delimiter)
        {
            k++;
        }
        else
        {
            break;
        }
    }
    ssplit = ssplit.substr(k, ssplit.length() - k);

    k = 0;
    for (int i = ssplit.length() - 1; i >= 0; i--) //spaces at the end
    {
         if (ssplit[i] == delimiter)
         {
            k++;
         }
         else
         {
             break;
         }
        
     }
    ssplit = ssplit.substr(0, ssplit.length() - k);
    
    ssplit = ssplit + delimiter;
    for (int i = 0; i < ssplit.length(); i++)
    {
	    if (ssplit[i] == delimiter)
		{
			string1 = ssplit.substr(h, i - h);
		    h = i + 1;
			//cout << string1 << endl;
            if (string1 != "")
            {
                words[j] = string1;
                j++;
            }
		}
	}
	if (maximum < j + 1)
	{
	    return -1;
	}
    else
    {
        return j;
    }

}

int getScores(string scores, int array[], int maximum)
{
    string array1[maximum];
    int result = split(scores, ' ', array1, maximum);
    for (int i = 0; i < result; i++)
    {
        int number = stoi(array1[i]);
        array[i] = number;
    } 
    return result; 
}


int main() 
{
    int nums[6];
    for (int i = 0; i < 6; i++)
    {
        cout << nums[i] << endl;
    }
    cout << getScores("15 2007 5", nums, 6) << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << nums[i] << endl;
    }

}



//str.substr(int start, int length)
//int isdigit (int c) //returns 1 if true and 0 if false