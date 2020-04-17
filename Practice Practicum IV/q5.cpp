#include <iostream>
using namespace std;

class DogProfile 
{
private:

  string name;
  string temperament;
  float bitingProbability;

public: //set each function with their perspective input types

  DogProfile();
  
  DogProfile(string n, string t, float b);
  
  void setName(string n);
  
  string getName();
  
  void setTemperament(string t);
  
  string getTemperament();
  
  void setBitingProbability(float b);
  
  float getBitingProbability();
  
  string goodBoy();
  
};

DogProfile :: DogProfile()
{
  name = "Fido";
  temperament = "always wags tail";
  bitingProbability = -100.0;
}

DogProfile :: DogProfile(string n, string t, float b)
{
  name = n;
  temperament = t;
  bitingProbability = b;
}

void DogProfile :: setName(string n)
{
  name = n;
}

string DogProfile :: getName()
{
  return name;
}

void DogProfile :: setTemperament(string t)
{
  temperament = t;
}

string DogProfile :: getTemperament()
{
  return temperament;
}

void DogProfile :: setBitingProbability(float b)
{
  bitingProbability = b;
}

float DogProfile :: getBitingProbability()
{
  return bitingProbability;
}

string DogProfile :: goodBoy()
{
  string statement;
  if (bitingProbability <= 1000.0)
  {
    statement = "Good Boy";
  }
  else if (bitingProbability > 1000.0)
  {
    statement = "Bad Boy";
  }
  return statement;
}