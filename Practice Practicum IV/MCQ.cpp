#include <iostream>
using namespace std;


// A programmer working on an airline ticketing application realizes that she needs to create many Flight objects in this application. What does she need to do in order to define a Flight class?
// d. Write a Flight class that defines the data members and functions that Flight objects will have.


class AeroPlane
{
public:
  void set_new_height(double new_height);
  void view() const;
  void view_new_height() const;
 
  AeroPlane();
  AeroPlane(double new_height);
  AeroPlane(double new_height, double new_speed);
  AeroPlane(int new_height, int new_speed);
 
private:
  double height;
  double speed;
};
//Which of the following constructors is called for the object declaration AeroPlane c1(10, 100)?
//b. AeroPlane(int new_height, int new_speed)


#ifndef ANIMAL_H
#define ANIMAL_H
 
class Animal
{
public:
  Animal();
  Animal(double new_area_hunt);
 
private:
  double area_hunt;
};
#endif
// The above file is saved as "Animal.h". The following is the source file.
#include "Animal.h"
 
Animal::Animal()
{
   area_hunt = 0;
}
int main()
{
   Animal cheetah1(250.00);
   return 0;
}
// a. The definition of the Animal class is incomplete because the constructor Animal::Animal(double new_area_hunt) has not been implemented in the source file.

// What is the output of the following code snippet?
class Building
{
public:
   Building();
   void set_height(double count);
   void get_data() const;
 
private:
   double height;
};
Building::Building() 
{
   cout << "Constructor" << endl;
}
void Building::get_data() const
{
   cout << height << endl;
}
void Building::set_height(double count)
{
   height = count;
}
int main()
{
   Building blg1;
   Building blg2;
   blg1.set_height(10);
   blg2.set_height(50);
   blg1.get_data();
   blg2.get_data();
   return 0;
}
// a. Constructor
// Constructor
// 10
// 50

// What is the output of the following code snippet?
class CashRegister
{
public:
   void set_item_count(int count);
 
private:
   int item_count;
};
void CashRegister::set_item_count(int count)
{
   item_count = count;
}
int main()
{
   CashRegister reg1;
   reg1.set_item_count(15);
   cout << "Item count: " << reg1.item_count;
   return 0;
}
// c. The code snippet does not compile. (no item_count function)

// What is the output of the following program?
#include <iostream>
using namespace std;
class Car
{
public:
   double get_speed() const;
 
   Car();
   Car(double dspeed);
 
private:
   double speed;
};
Car::Car()
{
   speed = 0;
}
Car::Car(double dspeed)
{
   speed = dspeed;
}
double Car::get_speed() const
{
   return speed;
}
int main()
{
   Car c1;
   Car c2(5);
   double sum_speed = 0;
   sum_speed = c1.get_speed() + c2.get_speed();
   cout << sum_speed << endl;
   return 0;
}
// a. 5

// Which of the following is a benefit of encapsulation?
// c. It guarantees that an object cannot be accidentally put into an inconsistent state.

//Which of the functions in the Item class cannot be mutators?
class Item
{
public:
   Item();
   Item(double price);
   Item(string d_description);
 
   void set_price(double price);
   void set_description(string d_description);
   string get_description() const;
   void display_item() const;
 
private:
   string description;
   double item_price;
};
// c. get_description and display_item
// control changes to a variable. They are also widely known as SETTER methods.

// Which option best describes this class definition?
class Car
{
   void start();
   double speed;
   double get_speed() const;
};
//  It is useless because all its members are private.
// DEFAULT TO PRIVATE

// Which option best describes the main() program, assuming the class member functions are implemented correctly, but not shown below?
class Month
{
public:
   int get_Month_num() const;
   string get_Month() const;
   Month(int);
private:
   int mon;
};
void main()
{
  Month m(3);
  cout << get_Month() << “ is #“ << get_Month_num() << endl;
  m.Month(4);
  cout << get_Month() << “ is #“ << get_Month_num() << endl;
}
//  It has a syntax error.





// private members of a class are accessible only from within other members of the same class (or from their "friends").
// protected members are accessible from other members of the same class (or from their "friends"), but also from members of their derived classes.
// Finally, public members are accessible from anywhere where the object is visible.

//DATA MEMBERS MUST BE PRIVATE == FALSE
//MEMBER FUNCTIONS MUST BE PUBLIC == TRUE
//DEFAULT CONSTUCTOR NEEDS 0 ARGUMENTS == TRUE 