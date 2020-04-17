#include <iostream>
using namespace std;


class Quarterback 
{
private:

  int pass_completes;
  int pass_attempts;
  int total_yards;
  int touchdowns;
  int intercepts;
  string name;

public: //set each function with their perspective input types

  Quarterback();
  
  Quarterback(string n, int comp, int att, int yards, int td, int i);
  
  void setName(string new_name);
  
  string getName();
  
  void setComp(int x);
  
  int getComp();
  
  void setAtt(int x);
  
  int getAtt();
  
  void setYards(int x);
  
  int getYards();
  
  void setTD(int x);
  
  int getTD();
  
  void setPick(int x);
  
  int getPick();
  
  void PassCompleted(int x);
  
  void PassAttempted();
  
  void Interception();
  
  Quarterback(string d);
  
  float PasserRating();
  
  void Touchdown(int x);
  
};