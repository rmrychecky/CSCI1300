#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int getLinesFromFile(string filename, int array[], int length)
{
    ifstream file;
    file.open(filename);
    int j = -1;
    
     if (file.fail())
     {
          return -1;
     }
     else
     {
        while (j < length && file)
        {
            j++;
            string line = "";
            file >> line;
            
            if (line != "")
            {
                    
            array[j] = stoi(line);
                
            }
 
        }
     }
      
     
     
    return j;

}


int main() 
{
     int numArray[4];
     int x = getLinesFromFile("testFile.txt", numArray, 4);
     cout << "Function returned: " << x << "\n";
     for(int i = 0; i < 4; i++)
     {
        cout << numArray[i] << "\n";
     }
}

