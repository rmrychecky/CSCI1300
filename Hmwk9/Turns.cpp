#include <iostream>
#include <iomanip>
#include <string>
#include <iostream>
#include <cmath>
#include <fstream>
#include <time.h>
#include "Turns.h"
#include "Milestones.h"
#include "Animals.h"
#include "Store.h"
using namespace std;

int randomNumbers1(int min, int max){
    // rand() % (max-min+1) + min
    return (rand() % (max-min+1)) + min;
}

Turns :: Turns() //User constructor
{
   currentDay = 28; //ORIGINAL DAY
   currentMonth = 03; //ORIGINAL MONTH (AKA DEFAULT)
}

void Turns :: setStatusUpdate(int milesTraveled, int miley, int totalFood, int totalBullets, int money)
{
   // Milestones turn;
   // turn.setmilestoneDistance(milestoneDistance);
   // Store mark;
   cout << "Current date: " << CURRENTYEAR << '-' << currentMonth << '-' << currentDay << endl; //print out each of these values at the beginning of each turn
   cout << "Miles travelled: " << milesTraveled << endl;
   cout << "Next landmark: " << miley << endl;
   cout << "Current food: " << totalFood << endl;
   cout << "Current number of bullets: " << totalBullets << endl;
   cout << "Current money: " << money << endl;   
   //at the beginning of every turn run a status update to update all the information inputs
   //these values are updated in the previous turn so they are accurate when called
}

int Turns :: rest(int players, int input1)
{
   cout << "You have chosen to rest. Food will be consumed accordingly and your health will improve as well." << endl;

   Store member1;
   int numberDays = randomNumbers1(1, 3); //number days is randomly chosen and is between 1 and 3
   int food = players*3*numberDays;
   bool check = true;
   int foodResult;
   
   setcurrentDay(numberDays); //update the current days and month based on numberDays
   //cout << getcurrentDay() << endl;
   setcurrentMonth(currentDay);
   //cout << getcurrentMonth() << endl;
   
   
   if (food >= input1)
   {
      foodResult = -1; //you run out of food
   }
   else if (food < input1)
   {
     foodResult = input1 - food; //food can be updated
   } 
   
   return foodResult;
   //this function will update the date and food values after a rest turn
   //if player chooses rest from the menu then call this function
}

int Turns :: continueTrail(int input1)
{
   cout << "You have chosen to continue on the trail for the next 2 weeks. Food will be consumed accordingly and your total miles will be updated." << endl;
   
   Store member1;
   Milestones member2;
   //int numberDays = 14;
   //int food = -5*3*14;
   int check1;

   int miles = randomNumbers1(70, 140); //generate a random milage value 
   
   setcurrentDay(14);
   setcurrentMonth(currentDay);
   // member1.settotalFood(food);
   // member2.setmilesTraveled(miles);
   if (input1 <= 0)
   {
      check1 = -1; //if you run out of food 
   }
   else 
   {
       check1 = miles; //if you still have food update the miles
   }
   
   return check1;
   //*****also update the milestone distances 
   //this function will increment the date by 2 weeks, milesTraveled by (70-140) and food values after a continue turn
   //if player chooses continue from the menu then call this function
}

int Turns :: hunt(int players, int input1, int rabbit, int fox, int deer, int bear, int moose)
{
   Store member1;
   Animals member3;
   int numberDays = 1;
   int food = 0;
   int subtractFood = 0;
   int totalf = 0;
   string answer;
   string answer2;
   int checker;
   bool yes;
   // int rabbit;
   // int fox;
   // int deer;
   // int bear;
   // int moose;
   
   setcurrentDay(numberDays);
   setcurrentMonth(currentDay);
   
   srand(time(0));
   int r = rand()%100; //values between 0 and 99
   
   if (r <= 5)
   {
      cout << "You got lucky! You encountered a rabbit! Do you want to hunt?Y/N" << endl; //prompt if they want to hunt the animal
      getline(cin, answer);
      while (answer != "Y" && answer != "y" && answer != "N" && answer != "n")
      {
         cout << "Invalid input. Please enter Y/N." << endl;
         getline(cin, answer);
      }
      if (answer == "Y")
      {
         //rabbit = member3.getRabbit(2, 2);
         if (rabbit == -1)
         {
            cout << "Your hunt was unsuccessful." << endl; //if the puzzle isn't solved you are unsucessful 
            yes = false;
         }
         else 
         {
            cout << "Your hunt was successful." << endl; //else set the food
            food = rabbit;
            yes = true;
         }
      }
      
      cout << "You got lucky! You encountered a fox! Do you want to hunt?Y/N" << endl;
      getline(cin, answer);
      while (answer != "Y" && answer != "y" && answer != "N" && answer != "n")
      {
         cout << "Invalid input. Please enter Y/N." << endl;
         getline(cin, answer);
      }
      if (answer == "Y")
      {
         //fox = member3.getFox(5, 5);
         if (fox == -1)
         {
            cout << "Your hunt was unsuccessful." << endl; //if the puzzle isn't solved you are unsucessful 
            yes = false;
         }
         else 
         {
            cout << "Your hunt was successful." << endl; //else set the food
            food = food + fox;
            yes = true;
         }
         
      }
      
      cout << "You got lucky! You encountered a deer! Do you want to hunt?Y/N" << endl;
      getline(cin, answer);
      while (answer != "Y" && answer != "y" && answer != "N" && answer != "n")
      {
         cout << "Invalid input. Please enter Y/N." << endl;
         getline(cin, answer);
      }
      if (answer == "Y")
      {
         //deer = member3.getDeer(30, 55);
         if (deer == -1)
         {
            cout << "Your hunt was unsuccessful." << endl; //if the puzzle isn't solved you are unsucessful 
            yes = false;
         }
         else 
         {
            cout << "Your hunt was successful." << endl; //else set the food
            food = food + deer;
            yes = true;
         }
         
      }
    
      cout << "You got lucky! You encountered a bear! Do you want to hunt?Y/N" << endl;
      getline(cin, answer);
      while (answer != "Y" && answer != "y" && answer != "N" && answer != "n")
      {
         cout << "Invalid input. Please enter Y/N." << endl;
         getline(cin, answer);
      }
      if (answer == "Y")
      {
         //bear = member3.getBear(100, 350);
         if (bear == -1)
         {
            cout << "Your hunt was unsuccessful." << endl; //if the puzzle isn't solved you are unsucessful 
            yes = false;
         }
         else 
         {
            cout << "Your hunt was successful." << endl; //else set the food
            food = food + bear;
            yes = true;
         }
         
      }
      
      cout << "You got lucky! You encountered a moose! Do you want to hunt?Y/N" << endl;
      getline(cin, answer);
      while (answer != "Y" && answer != "y" && answer != "N" && answer != "n")
      {
         cout << "Invalid input. Please enter Y/N." << endl;
         getline(cin, answer);
      }
      if (answer == "Y")
      {
         //moose = member3.getMoose(300, 600);
         if (moose == -1)
         {
            cout << "Your hunt was unsuccessful." << endl; //if the puzzle isn't solved you are unsucessful 
            yes = false;
         }
         else 
         {
            cout << "Your hunt was successful." << endl; //else set the food
            food = food + moose;
            yes = true;
         }
         
      }
      
      //if (answer == "Y" )
      //{
         cout << "How well do you want to eat? Poorly/Moderately/Well" << endl;
         getline(cin, answer2);
         while (answer2 != "Poorly" && answer2 != "Moderately" && answer2 != "Well")
         {
            cout << "Invalid answer, please enter how well you would like to eat. Poorly/Moderately/Well" << endl;
            getline(cin, answer2);
         }
         
         if (answer2 == "Poorly")
         {
            subtractFood = -players*2;
         }
         else if (answer2 == "Moderately")
         {
            subtractFood = -players*3;
         }
         else if (answer2 == "Well")
         {
            subtractFood = -players*5;
         }
         
         //fix food value 
         food = food + subtractFood; //set the overal food from the hunt
         //member1.settotalFood(food);
         totalf = input1 - food; //subtract how much you have from what you result with from the hunt
         if (totalf <= 0) //if you dont have enough
         {
            checker = 0;
            return checker;
         }
         else if (totalf > 1000)
         {
            food = -(totalf - 1000);
            checker = food;
            //member1.settotalFood(food);
            //totalf = member1.gettotalFood();
            cout << "Your total food exceeded 1000 lbs of food, so you had to leave behind any your extra food. You currently have 1000 lbs of food." << endl; 
         }
         else 
         {
            checker = food;
            cout << "You have " << totalf << " lbs of food after your hunt." << endl;
         }
      //}

   }
   
   else if (r <= 7)
   {
      cout << "You got lucky! You encountered a rabbit! Do you want to hunt?Y/N" << endl;
      getline(cin, answer);
      while (answer != "Y" && answer != "y" && answer != "N" && answer != "n")
      {
         cout << "Invalid input. Please enter Y/N." << endl;
         getline(cin, answer);
      }
      if (answer == "Y")
      {
         //rabbit = member3.getRabbit(2, 2);
         if (rabbit == -1)
         {
            cout << "Your hunt was unsuccessful." << endl; //if the puzzle isn't solved you are unsucessful 
            yes = false;
         }
         else 
         {
            cout << "Your hunt was successful." << endl; //else set the food
            food = rabbit;
            yes = true;
         }
      }
      
      cout << "You got lucky! You encountered a fox! Do you want to hunt?Y/N" << endl;
      getline(cin, answer);
      while (answer != "Y" && answer != "y" && answer != "N" && answer != "n")
      {
         cout << "Invalid input. Please enter Y/N." << endl;
         getline(cin, answer);
      }
      if (answer == "Y")
      {
         //fox = member3.getFox(5, 5);
         if (fox == -1)
         {
            cout << "Your hunt was unsuccessful." << endl; //if the puzzle isn't solved you are unsucessful 
            yes = false;
         }
         else 
         {
            cout << "Your hunt was successful." << endl; //else set the food
            food = food + fox;
            yes = true;
         }
         
      }
      
      cout << "You got lucky! You encountered a deer! Do you want to hunt?Y/N" << endl;
      getline(cin, answer);
      while (answer != "Y" && answer != "y" && answer != "N" && answer != "n")
      {
         cout << "Invalid input. Please enter Y/N." << endl;
         getline(cin, answer);
      }
      if (answer == "Y")
      {
         //deer = member3.getDeer(30, 55);
         if (deer == -1)
         {
            cout << "Your hunt was unsuccessful." << endl; //if the puzzle isn't solved you are unsucessful 
            yes = false;
         }
         else 
         {
            cout << "Your hunt was successful." << endl; //else set the food
            food = food + deer;
            yes = true;
         }
         
      }
    
      cout << "You got lucky! You encountered a bear! Do you want to hunt?Y/N" << endl;
      getline(cin, answer);
      while (answer != "Y" && answer != "y" && answer != "N" && answer != "n")
      {
         cout << "Invalid input. Please enter Y/N." << endl;
         getline(cin, answer);
      }
      if (answer == "Y")
      {
         //bear = member3.getBear(100, 350);
         if (bear == -1)
         {
            cout << "Your hunt was unsuccessful." << endl; //if the puzzle isn't solved you are unsucessful 
            yes = false;
         }
         else 
         {
            cout << "Your hunt was successful." << endl; //else set the food
            food = food + bear;
            yes = true;
         }
         
      }
      
      // if (answer == "Y")
      // {
         cout << "How well do you want to eat? Poorly/Moderately/Well" << endl;
         getline(cin, answer2);
         while (answer2 != "Poorly" && answer2 != "Moderately" && answer2 != "Well")
         {
            cout << "Invalid answer, please enter how well you would like to eat. Poorly/Moderately/Well" << endl;
            getline(cin, answer2);
         }

         if (answer2 == "Poorly")
         {
            subtractFood = -players*2;
         }
         else if (answer2 == "Moderately")
         {
            subtractFood = -players*3;
         }
         else if (answer2 == "Well")
         {
            subtractFood = -players*5;
         }
         
         food = food + subtractFood; //set the overal food from the hunt
         //member1.settotalFood(food);
         totalf = input1 - food; //subtract how much you have from what you result with from the hunt
         if (totalf <= 0)
         {
            checker = 0;
            return checker;
         }
         else if (totalf > 1000)
         {
            food = -(totalf - 1000);
            checker = food;
            //member1.settotalFood(food);
            //totalf = member1.gettotalFood();
            cout << "Your total food exceeded 1000 lbs of food, so you had to leave behind any your extra food. You currently have 1000 lbs of food." << endl; 
         }
         else 
         {
            checker = food;
            cout << "You have " << totalf << " lbs of food after your hunt." << endl;
         }
         
      
      // }
      
     
   }
   
   else if (r <= 15)
   {
      
      cout << "You got lucky! You encountered a rabbit! Do you want to hunt?Y/N" << endl;
      getline(cin, answer);
      while (answer != "Y" && answer != "y" && answer != "N" && answer != "n")
      {
         cout << "Invalid input. Please enter Y/N." << endl;
         getline(cin, answer);
      }
      if (answer == "Y")
      {
         //rabbit = member3.getRabbit(2, 2);
         if (rabbit == -1)
         {
            cout << "Your hunt was unsuccessful." << endl; //if the puzzle isn't solved you are unsucessful 
            yes = false;
         }
         else 
         {
            cout << "Your hunt was successful." << endl; //else set the food
            food = rabbit;
            yes = true;
         }
      }
      
      cout << "You got lucky! You encountered a fox! Do you want to hunt?Y/N" << endl;
      getline(cin, answer);
      while (answer != "Y" && answer != "y" && answer != "N" && answer != "n")
      {
         cout << "Invalid input. Please enter Y/N." << endl;
         getline(cin, answer);
      }
      if (answer == "Y")
      {
         //fox = member3.getFox(5, 5);
         if (fox == -1)
         {
            cout << "Your hunt was unsuccessful." << endl; //if the puzzle isn't solved you are unsucessful 
            yes = false;
         }
         else 
         {
            cout << "Your hunt was successful." << endl; //else set the food
            food = food + fox;
            yes = true;
         }
         
      }
      
      cout << "You got lucky! You encountered a deer! Do you want to hunt?Y/N" << endl;
      getline(cin, answer);
      while (answer != "Y" && answer != "y" && answer != "N" && answer != "n")
      {
         cout << "Invalid input. Please enter Y/N." << endl;
         getline(cin, answer);
      }
      if (answer == "Y")
      {
         //deer = member3.getDeer(30, 55);
         if (deer == -1)
         {
            cout << "Your hunt was unsuccessful." << endl; //if the puzzle isn't solved you are unsucessful 
            yes = false;
         }
         else 
         {
            cout << "Your hunt was successful." << endl; //else set the food
            food = food + deer;
            yes = true;
         }
         
      }
      
      // if (answer == "Y")
      // {
         cout << "How well do you want to eat? Poorly/Moderately/Well" << endl;
         getline(cin, answer2);
         while (answer2 != "Poorly" && answer2 != "Moderately" && answer2 != "Well")
         {
            cout << "Invalid answer, please enter how well you would like to eat. Poorly/Moderately/Well" << endl;
            getline(cin, answer2);
         }
         
         if (answer2 == "Poorly")
         {
            subtractFood = -players*2;
         }
         else if (answer2 == "Moderately")
         {
            subtractFood = -players*3;
         }
         else if (answer2 == "Well")
         {
            subtractFood = -players*5;
         }
         
         food = food + subtractFood; //set the overal food from the hunt
         //member1.settotalFood(food);
         totalf = input1 - food; //subtract how much you have from what you result with from the hunt
         if (totalf <= 0) //if you dont have enough
         {
            checker = 0;
            return checker;
         }
         else if (totalf > 1000) //if you have over 1000
         {
            food = -(totalf - 1000);
            checker = food;
            //member1.settotalFood(food);
            //totalf = member1.gettotalFood();
            cout << "Your total food exceeded 1000 lbs of food, so you had to leave behind any your extra food. You currently have 1000 lbs of food." << endl; 
         }
         else //normal
         {
            checker = food;
            cout << "You have " << totalf << " lbs of food after your hunt." << endl;
         }
      // }
   
   }
   
   else if (r <= 25)
   {
      cout << "You got lucky! You encountered a rabbit! Do you want to hunt?Y/N" << endl;
      getline(cin, answer);
      while (answer != "Y" && answer != "y" && answer != "N" && answer != "n")
      {
         cout << "Invalid input. Please enter Y/N." << endl;
         getline(cin, answer);
      }
      if (answer == "Y")
      {
         //rabbit = member3.getRabbit(2, 2);
         if (rabbit == -1)
         {
            cout << "Your hunt was unsuccessful." << endl; //if the puzzle isn't solved you are unsucessful 
            yes = false;
         }
         else 
         {
            cout << "Your hunt was successful." << endl; //else set the food
            food = rabbit;
            yes = true;
         }
      }
      
      cout << "You got lucky! You encountered a fox! Do you want to hunt?Y/N" << endl;
      getline(cin, answer);
      while (answer != "Y" && answer != "y" && answer != "N" && answer != "n")
      {
         cout << "Invalid input. Please enter Y/N." << endl;
         getline(cin, answer);
      }
      if (answer == "Y")
      {
         //fox = member3.getFox(5, 5);
         if (fox == -1)
         {
            cout << "Your hunt was unsuccessful." << endl; //if the puzzle isn't solved you are unsucessful 
            yes = false;
         }
         else 
         {
            cout << "Your hunt was successful." << endl; //else set the food
            food = food + fox;
            yes = true;
         }
         
      }
      
      // if (answer == "Y")
      // {
         cout << "How well do you want to eat? Poorly/Moderately/Well" << endl;
         getline(cin, answer2);
         while (answer2 != "Poorly" && answer2 != "Moderately" && answer2 != "Well")
         {
            cout << "Invalid answer, please enter how well you would like to eat. Poorly/Moderately/Well" << endl;
            getline(cin, answer2);
         }
         
         if (answer2 == "Poorly")
         {
            subtractFood = -players*2;
         }
         else if (answer2 == "Moderately")
         {
            subtractFood = -players*3;
         }
         else if (answer2 == "Well")
         {
            subtractFood = -players*5;
         }
         
         food = food + subtractFood; //set the overal food from the hunt
         //member1.settotalFood(food);
         totalf = input1 - food; //subtract how much you have from what you result with from the hunt
         if (totalf <= 0) //if you dont have enough
         {
            checker = 0;
            return checker;
         }
         else if (totalf > 1000)
         {
            food = -(totalf - 1000);
            checker = food;
            //member1.settotalFood(food);
            //totalf = member1.gettotalFood();
            cout << "Your total food exceeded 1000 lbs of food, so you had to leave behind any your extra food. You currently have 1000 lbs of food." << endl; 
         }
         else 
         {
            checker = food;
            cout << "You have " << totalf << " lbs of food after your hunt." << endl;
         }
      // }
         
   }
   
   else if (r <= 50)
   {
      
      cout << "You got lucky! You encountered a rabbit! Do you want to hunt?Y/N" << endl;
      getline(cin, answer);
      while (answer != "Y" && answer != "y" && answer != "N" && answer != "n")
      {
         cout << "Invalid input. Please enter Y/N." << endl;
         getline(cin, answer);
      }
      if (answer == "Y")
      {
         //rabbit = member3.getRabbit(2, 2);
         if (rabbit == -1)
         {
            cout << "Your hunt was unsuccessful." << endl; //if the puzzle isn't solved you are unsucessful 
            yes = false;
         }
         else 
         {
            cout << "Your hunt was successful." << endl; //else set the food
            food = rabbit;
            yes = true;
         }
      }
      
            //    if (answer == "Y")
      // {
         cout << "How well do you want to eat? Poorly/Moderately/Well" << endl;
         getline(cin, answer2);
         
         while (answer2 != "Poorly" && answer2 != "Moderately" && answer2 != "Well")
         {
            cout << "Invalid answer, please enter how well you would like to eat. Poorly/Moderately/Well" << endl;
            getline(cin, answer2);
         }
         
         if (answer2 == "Poorly")
         {
            subtractFood = -players*2;
         }
         else if (answer2 == "Moderately")
         {
            subtractFood = -players*3;
         }
         else if (answer2 == "Well")
         {
            subtractFood = -players*5;
         }
         
         food = food + subtractFood; //set the overal food from the hunt
         //member1.settotalFood(food);
         totalf = input1 - food; //subtract how much you have from what you result with from the hunt
         if (totalf <= 0) //if you dont have enough
         {
            checker = 0;
            return checker;
         }
         else if (totalf > 1000)
         {
            food = -(totalf - 1000);
            checker = food;
            //member1.settotalFood(food);
            //totalf = member1.gettotalFood();
            cout << "Your total food exceeded 1000 lbs of food, so you had to leave behind any your extra food. You currently have 1000 lbs of food." << endl; 
         }
         else 
         {
            checker = food;
            cout << "You have " << totalf << " lbs of food after your hunt." << endl;
         }
      // }

   }
   else 
   {
      checker = -1;
      cout << "You did not encounter any animals, bummer." << endl;
      //    if (answer == "Y")
      // {
         cout << "How well do you want to eat? Poorly/Moderately/Well" << endl;
         getline(cin, answer2);
         
         while (answer2 != "Poorly" && answer2 != "Moderately" && answer2 != "Well")
         {
            cout << "Invalid answer, please enter how well you would like to eat. Poorly/Moderately/Well" << endl;
            getline(cin, answer2);
         }
         
         if (answer2 == "Poorly")
         {
            subtractFood = -players*2;
         }
         else if (answer2 == "Moderately")
         {
            subtractFood = -players*3;
         }
         else if (answer2 == "Well")
         {
            subtractFood = -players*5;
         }
         
         food = food + subtractFood; //set the overal food from the hunt
         //member1.settotalFood(food);
         totalf = input1 - food; //subtract how much you have from what you result with from the hunt
         if (totalf <= 0) //if you dont have enough
         {
            checker = 0;
            return checker;
         }
         else if (totalf > 1000)
         {
            food = -(totalf - 1000);
            checker = food;
            //member1.settotalFood(food);
            //totalf = member1.gettotalFood();
            cout << "Your total food exceeded 1000 lbs of food, so you had to leave behind any your extra food. You currently have 1000 lbs of food." << endl; 
         }
         else 
         {
            checker = food;
            cout << "You have " << totalf << " lbs of food after your hunt." << endl;
         }
      // }
      
   }
   
   return checker;   
   
   //add 1 to current day 
   //use proablility function to decide which animal is encountered 
   //they could encounter more than 1 animal on the trip or none...
   // srand(time(0));
   //int r = rand()%100; //values between 0 and 99
   //cout what animal they encountered and ask them if they want to hunt it
   //call animal class!
}

void Turns :: quit()
{
   cout << "Sorry but the party must cut their trip short!" << endl;
}

void Turns :: setcurrentDay(int day) //special case for if user wants to change start day?
{
   currentDay = currentDay + day;
  
}

int Turns :: getcurrentDay()
{
   return currentDay;
}

void Turns :: setcurrentMonthOriginal(int month)
{
   currentMonth = month;
}

int Turns :: getcurrentMonthOriginal()
{
   return currentMonth;
}

void Turns :: setcurrentDayOriginal(int day)
{
   currentDay = day;
}

int Turns :: getcurrentDayOriginal()
{
   return currentDay;
}

void Turns :: setcurrentMonth(int day) //special case for if user wants to change start month?
{
   int leftover = 0;
   if ((currentDay >= 30 && currentMonth == 4) || (currentDay >= 30 && currentMonth == 6) || (currentDay >= 30 && currentMonth == 9) || (currentDay >= 30 && currentMonth == 11)) //30 DAY MONTHS
   {
      leftover = currentDay - 30;
      currentMonth++;
      setcurrentDayOriginal(leftover);
   }
   else if ((currentDay >= 31 && currentMonth == 3) || (currentDay >= 31 && currentMonth == 5) || (currentDay >= 31 && currentMonth == 7) || (currentDay >= 31 && currentMonth == 8) || (currentDay >= 31 && currentMonth == 10)) //31 DAY MONTHS
   {
      leftover = currentDay - 31;
      currentMonth++;
      setcurrentDayOriginal(leftover);
     
   }
  
}

int Turns :: getcurrentMonth()
{
   return currentMonth;
}

int Turns :: getcurrentYear()
{
   return CURRENTYEAR;
}

