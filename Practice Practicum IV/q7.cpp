#include <iostream>
using namespace std;

class MovieReview 
{
private:

  string name;
  string genre;
  int rating;

public: //set each function with their perspective input types

  MovieReview();
  
  MovieReview(string n, string g, int r);
  
  void setName(string n);

  string getName();
  
  void setGenre(string g);
  
  string getGenre();
  
  void setRating(int r);
  
  int getRating();
  
  string howYouReallyFeel();
  
};

MovieReview :: MovieReview()
{
  name = "Goofy Movie 2: The Extremely Goofy Movie";
  genre = "Thriller";
  rating = 10;
}

MovieReview :: MovieReview(string n, string g, int r)
{
  name = n;
  genre = g;
  rating = r;
}

void MovieReview :: setName(string n)
{
  name = n;
}

string MovieReview :: getName()
{
  return name;
}

void MovieReview :: setGenre(string g)
{
  genre = g;
}

string MovieReview :: getGenre()
{
  return genre;
}

void MovieReview :: setRating(int r)
{
  rating = r;
}

int MovieReview :: getRating()
{
  return rating;
}

string MovieReview :: howYouReallyFeel()
{
  string statement;
  if (rating < 0)
  {
    statement = "Garbage";
  }
  else if (rating > 0 && rating <= 5)
  {
    statement = "Boo";
  }
  else if (rating > 5 && rating <= 7)
  {
    statement = "Meh";
  }
  else if (rating > 7 && rating <= 9)
  {
    statement = "Good";
  }
  else //if (rating > 10)
  {
    statement = "Must be THE Goofy Movie 2";
  }
  return statement;
}