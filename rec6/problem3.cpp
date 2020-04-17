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
		
            if (string1 != "")
            {
                words[j] = string1;
                j++;
                //cout << string1 << endl;
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


int main() 
{
    string words[6];
    // for (int i = 0; i < 6; i ++)
    // {
    //     cout << words[i] << endl;
    // }
    // // cout << split("one small step", ' ', words, 6) << endl; //expected output: 3
    // // cout << split(" one small step  ", ' ', words, 6) << endl; //expected output: 3
    // // cout << split("cow/big pig/fish", '/', words, 6) << endl; //expected output: 3
    // cout << split("cow/big pig//fish", '/', words, 6) << endl; //expected output: 3
    // for (int i = 0; i < 6; i ++)
    // {
    //     cout << words[i] << endl;
    // }
    // cout << split("unintentionally", 'n', words, 6) << endl; //expected output: 5
    // cout << split("one small step", ' ', words, 2) << endl; //expected output: -1
    cout << split("Richard Adams,Watership Down", ',', words, 6) << endl;
    for (int i = 0; i < 6; i ++)
    {
        cout << words[i] << endl;
    }
}



//str.substr(int start, int length)
//int isdigit (int c) //returns 1 if true and 0 if false

//going from int to string
//int i = stoi("123") 
//going from float to string
//float f = stof("3.123412")

//going to a string
//string str = to_string(3.1235);