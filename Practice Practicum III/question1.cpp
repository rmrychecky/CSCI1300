#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

 int Split (string str, char c, string array[], int size) //given split function
 {
    if (str.length() == 0) {
         return 0;
     }
    string word = "";
    int count = 0;
    str = str + c;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == c)
        {
            if (word.length() == 0)
                continue;
            array[count++] = word;
            word = "";
        } else {
            word = word + str[i];
        }
    }
    return count ;
 }
 
float averageTemp(string filename)
{
    ifstream file; 
    file.open(filename);
    string line = ""; 
    string array[2];
    float number = 0;
    float average = 0;
    
    if (file.is_open()) //if the file opens
    {
        int i = 0;
        while (getline(file, line)) //store each author in first array and each title in second array
        { 
            Split(line, ',', array, 2);
            if (line != "")
            {
                number = number + stoi(array[1]);
                i++;
            }
        }
        if (i == 0 || number == 0)
        {
            average = -0.00;
        }
        else 
        {
            average = number / i;
        }
        return average; 
    }
    else
    {
        return -1;
    }
    file.close();

}

int main()
{
string filename = "text.txt";
cout << averageTemp(filename) << endl; //expected return: 8
 
}