#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;

int fileLoadWrite(string filename)
{
    ofstream file; 
    file.open(filename);
    const int CAPACITY = 10;
    double values[CAPACITY];
    if (file.is_open())
    {
        for (int i = 0; i < CAPACITY; i++)
        {
            values[i] = (i + 1) * (i + 1); //squaring them
            //cout << values[i] << endl;
            file << values[i] << endl;
        }
       return 0;
       
    }
    else
    {
       return -1;
    }
    file.close();

    
}




int main() 
{
    
    
    int x = fileLoadWrite("myFile.txt");
    cout << "Function returned: " << x << "\n";
    //if (x == 0)
    
    //DisplayFile("myFile.txt");
    // string filename = "myFile.txt";
    // cout << fileLoadWrite(filename) << endl;
}

