#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int fileLoadRead(string filename)
{
    ifstream file; 
    file.open(filename);
    string line = "";
    int l = 0;
    if (file.is_open())
    {
        while (getline(file, line))
        {
            l++;
        }
       return l;
    }
    else
    {
       return -1;
    }
    file.close();

    
}


int main() 
{
    string filename = "myFile.txt";
    cout << fileLoadRead(filename) << endl;
}

