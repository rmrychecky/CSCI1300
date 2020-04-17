#include <iostream>
using namespace std;

class Stats  
{
private:

  string data[50];
  int dataSize;

public: //set each function with their perspective input types

  Stats();
  
  void ReadFile(string filename);
  
  float getAvgStringLength();
  
  string getLongestString();
  
};

Stats::Stats()
{
    dataSize = 50;
}

void Stats::ReadFile(string filename)
{
    ifstream myFile;
    myFile.open(filename);
    
    if(myFile.is_open())
    {
        string line;
        dataSize=0;
        while(getline(myFile, line))
        {
            data[dataSize] = line;
            dataSize++;
        }
    }
    else
    {
        cout << "File failed to open" << endl;
    }
}

float Stats::getAvgStringLength()
{
    float sum = 0, avg = 0;
    
    for(int i=0; i<=dataSize; i++)
    {
        sum += data[i].length();
    }
    
    avg = sum/dataSize;
    return avg;
}

string Stats::getLongestString()
{
    int index = 0;
    for(int i=0; i<dataSize; i++)
    {
        if(data[i].length()>=data[index].length())
        {
            index = i;
        }
    }
    return data[index];
}