#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool checkFile(string filename)
{
    ifstream file; 
    file.open(filename);
    if (file.is_open())
    {
        return true;
        
    }
    else 
    {
        return false;
    }
    file.close();
 
    
}


int main() 
{
    string filename = "myFile.txt";
    cout << checkFile(filename) << endl;
}

