#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

void saveData(string filename, string array[], int n, int size)
{
    ofstream file; 
    file.open(filename);
    
    if (file.is_open())
    {
        double sum = 0;
        double value = 0;
        double average = 0;
        for (int i = 0; i < size - 1; i++)
        {
            if (!array[i].empty())
            {
                value = stod(array[i]);
                sum = sum + value;
            }
        }
        average = sum / n;
        //cout << average << endl;
        if (array[size - 1] == "")
        {
            
        }
        else if (n == 0)
        {
            file << "Name: " << array[0] << endl;
        }
        else 
        {
            file << "Name: " << array[size - 1] << endl << "Avg: " << average << endl;
        }
    }
    else
    {
       cout << "file open failed" << endl;
    }
    file.close();
}


int main() 
{
    string data[4] = {"2.3", "-1.5", "0.8", "Garth"};
    saveData("my_data.txt", data, 3, 4);
}





