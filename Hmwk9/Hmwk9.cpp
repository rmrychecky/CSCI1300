// CSCI1300 Fall 2018
// Author: Raegan Rychecky 
// Recitation: Carter Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/rmrychecky/csci1300
// hmwk9 / Project3

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <time.h>
#include "Animals.h" //include the User, Book, and Library h files
#include "Milestones.h"
#include "Store.h"
#include "Turns.h"
using namespace std; 

int randomNumbers3(int min, int max){
    // rand() % (max-min+1) + min
    return (rand() % (max-min+1)) + min;
}


bool is_number(const string& s){
   for(int i = 0; i < s.length(); i++)//for each char in string,
      if(! (s[i] >= '0' && s[i] <= '9' || s[i] == ' ') ) return false;
      //if s[i] is between '0' and '9' of if it's a whitespace (there may be some before and after
      // the number) it's ok. otherwise it isn't a number.

   return true;
}

int raiderAttack(int input1, int input2, int input3, int input4, int input5, int input6) //RAIDER ATTACK
{
    srand(time(0));
    int b = rand()%100;
    int M = 0;
    Milestones member2;
    Store member1;
    M = member2.getmilesTraveled();
    double base = pow(((M/100) - 4), 2);
    string answer3;
    int cash = 0;
    double probabilityRaiders = 0;
    int returnRaider;
   
                        
    probabilityRaiders = (((base + 72)/(base + 12)) - 1)/10;
                        
    if (b <= probabilityRaiders)
    {
        cout << "Raiders ahead! They look hostile!" << endl;
        cout << "Please choose to RUN, ATTACK, or SURRENDER by tying 1, 2, or 3." << endl;
        getline(cin, answer3);
        if (answer3 != "1" && answer3 != "2" && answer3 != "3") //MAKE SURE THE INPUT IS VALID
        {
            cout << "Invalid input please choose to RUN, ATTACK, or SURRENDER by tying 1, 2, or 3." << endl;
            getline(cin, answer3);
        }
        if (answer3 == "1")
        {
            
            // member1.settotalOxen(-1);
            // member1.settotalFood(-10);
            // member1.settotalWagonParts(-1);
            returnRaider = 1;
            // if (member1.gettotalOxen() <= 0 || member1.gettotalFood() <= 0 || member1.gettotalWagonParts() <= 0)
            // {
            //     returnRaider = false;
            //     return returnRaider;
            // }
            cout << "Your party escapes but in the hurry to flee the raiders, you leave behind 1 oxen, 10 lbs of food, and 1 wagon part. Oops!" << endl; //IF YOU FUN YOU LOSE THINGS
        }
        else if (answer3 == "2")
        {
            int number = randomNumbers3(1, 10);
            string inputNumber = 0;
            
            cout << "You have chosen to attack. In order to win the battle, you must pass a puzzle. You have 3 tries to guess a number between 1 and 10." << endl;  //IF YOU ATTACK YOU AHVE TO SOLVE A PUZZLE
            for (int i = 0; i < 3; i++)
            {
                cout << "Please enter a number between 1 and 10." << endl;
                getline(cin, inputNumber);
                if (stoi(inputNumber) == number)
                {
                    cout << "You win the battle. Your party gains 50 lbs of food and 50 bullets." << endl; //IF YOU WIN YOU GAIN FOOD AND BULLETS
                    returnRaider = 2;
                    // member1.settotalFood(50);
                    // member1.settotalBullets(50);
                    break;
                }
            } 
            if (stoi(inputNumber) != number) //IF YOU LOSE YOU LOSE MONEY AND BULLETS
            {
                cout << "You lose the battle. Your party loses a quarter of your cash reserves and 50 bullets" << endl;
                returnRaider = 3;
                // cash = member1.getMoney();
                // member1.setMoney(-(cash*.25));
                // member1.settotalBullets(-50);
            }
                    
        }
        else if (answer3 == "3")
        {
            
            // cash = member1.getMoney();
            // member1.setMoney(-(cash*.25));
            returnRaider = 4;
            cout << "You surrender and lose a quarter of your cash reserves." << endl; 
        }
                            
    } 
    return returnRaider;
}

int misfortuneOccur(int numberofPlayers, string playerName, string player1, string player2, string player3, string player4, int input1, int input2, int input3, int input4)  //MISFORTUNES
{
    srand(time(0));
    int a = rand()%100;
                    
    int numberR = 0;
    int numberP = 0;
    int numberQ = 0;
    int numberChance = 0;
    string person;
    Store member1;
    string talk;
    bool breaker = true;
    int numberofOxen;
    int numberofWagon;
    int cutie = -1;

    if (a <= 40)
    {
        numberR = randomNumbers3(1, 3);
        numberP = randomNumbers3(1, 5);
        numberQ = randomNumbers3(0, 100);
        if (numberP == 1) //SET RANDOM NUMBER TO WHICH PERSON THE NUMBER MATCHES WITH
        {   
            person = playerName;
        }
        else if (numberP == 2)
        {
            person = player1;
        }
        else if (numberP == 3)
        {
            person = player2;
        }
        else if (numberP == 4)
        {
           person = player3;
        }
        else if (numberP == 5)
        {
            person = player4;
        }
                        
        if (numberR == 1) //IF THE RANDOM EVENT IS 1 YOU ARE SICK
        {
            if (input4 > 0)
            {
                cout << person << " got sick. You use a medical aid kit but your team member still has a %50 chance of dying." << endl;
                
                if (numberQ <= 50)
                {
                    cout << "Oh no! " << person << " died of dysentery!" << endl;
                    if (numberP == 1)
                    {
                        //playerName = "";
                        cutie = 5; //HAVE IF PLAYERNAME IS BLANK THEN END THE GAME!!!!!

                        return cutie;
                    }
                    else if (numberP == 2)
                    {
                        player1 = "";
                        numberofPlayers--;
                    }
                    else if (numberP == 3)
                    {
                        player2 = "";
                        numberofPlayers--;
                    }
                    else if (numberP == 4)
                    {
                        player3 = "";
                        numberofPlayers--;
                    }
                    else if (numberP == 5)
                    {
                        player4 = "";
                        numberofPlayers--;
                    }
                }
                else 
                {
                    cout << "Looks like the medical aid kit worked! " << person << " did not die." << endl;
                    cutie = 6;
                    return cutie;
                }
                
                
            }
            else if (input4 <= 0)
            {
                cutie = 8;
                return cutie;
                
            }
            
        }
        if (numberR == 2)
        {
            //member1.settotalOxen(-1);
            cout << "Oh no! One of the oxen has died!" << endl; //IF EVENT 2 OCCURS YOUR OXEN DIES
            if ((input3 - 1) > 0)
            {
                numberofOxen = input3 - 1;
                cout << "You have " << numberofOxen << " oxen left." << endl;
                
                cutie = 1;
                //return cutie;
            }
            else if (input3 - 1 <= 0) //CHECK IF YOU STILL HAVE OXEN LEFT OVER
            {
                cout << "You are unable to continue on your journey. Sorry!" << endl; 
                //numberofOxen = -1;
                cutie = 2;
                //return cutie;
                //HAVE INSTANCE IF YOU RUN OUT OF WAGON PARTS THEN THE GAME IS OVER
            }
            return cutie;
        }
        if (numberR == 3)
        {
            //member1.settotalWagonParts(-1);
            cout << "Oh no! One of your wheels is broken!" << endl;
            if (input2 - 1 > 0) //IF EVENT 3 OCCURS THEN YOU LOSE A WHEEL
            { 
                numberofWagon = input2 - 1;
                cout << "You have " << numberofWagon << " wagon parts left." << endl;
                
                cutie = 3;
                
            }
            else if (input2 - 1 <= 0) //IF YOU HAVE NO PARTS LEFT THEN YOU LOSE
            {
                cout << "You are unable to continue on your journey. Sorry!" << endl; 
                //numberofWagon = -1;
                cutie = 4;
                //return cutie;
                //HAVE INSTANCE IF YOU RUN OUT OF WAGON PARTS THEN THE GAME IS OVER
            }
            return cutie;
        }
        
        
    }
    return cutie;
}


 void displayMenu(){
     cout << "Select a numerical option:" << endl;
     cout << "======Main Menu=====" << endl;
     cout << "1. Rest" << endl;
     cout << "2. Continue" << endl;
     cout << "3. Hunt" << endl;
     cout << "4. Quit" << endl;
 }



int main(int argc, char const *argv[])
{
 //initalization of all of my used variables in the main function
    string choice;
    Turns member;
    Store member1;
    Milestones member2;
    Animals member3;
    string playerName;
    string player1;
    string player2;
    string player3;
    string player4;
    string response = "Y";
    string answer;
    string answer2;
    int minFood = 0;
    int maxFood = 0;
    string numberOxen;
    string poundsFood;
    string numberBullets;
    string numberParts;
    string numberKits;
    int money = 0;
    int breaker;
    int check;
    int returnRaider;
    int returnHunt;
    int returnTrail;
    int input1;
    int input2;
    int input3;
    int input4;
    int input5;
    int input6;
    int cash;
    int returnMilestone;
    int milestoneDistance;
    int inputRabbit;
    int inputFox;
    int inputDeer;
    int inputBear;
    int inputMoose;
    int numberofPlayers = 5;
    
    
    //double inflation = 1.0;
    string filenameFort = "fort-milestones.txt";
    string filenameRiver = "river-milestones.txt";
    int oxCount;
    int wagonCount;
    
    member2.setFort(filenameFort);
    member2.setRiver(filenameRiver);

    cout << "What is your name?: " << endl; //ASK MAIN PLAYER
    getline(cin, playerName);
    while (playerName == "")
    {
        cout << "Invalid name please enter your name." << endl;
        getline(cin, playerName);
    }
    
    cout << "Please enter the names of your companions below:" << endl; //ASK FOR COMPANION
    cout << "1 : " << endl;
    getline(cin, player1);
    while (player1 == "")
    {
        cout << "Invalid name please enter the name of your companion." << endl;
        getline(cin, player1);
    }
    cout << "2 : " << endl; //ASK FOR COMPANION
    getline(cin, player2);
    while (player2 == "")
    {
        cout << "Invalid name please enter the name of your companion." << endl;
        getline(cin, player1);
    }
    cout << "3 : " << endl; //ASK FOR COMPANION
    getline(cin, player3);
    while (player3 == "")
    {
        cout << "Invalid name please enter the name of your companion." << endl;
        getline(cin, player1);
    }
    cout << "4 : " << endl; //ASK FOR COMPANION
    getline(cin, player4);
    while (player4 == "")
    {
        cout << "Invalid name please enter the name of your companion." << endl;
        getline(cin, player1);
    }
    
    
        
   
    cout << "You are starting at mile: 0. There are 2040 that you must travel to reach your destination. Before the start of your trip, you can visit the store and buy supplies: food, oxen, bullets and wagon parts. Would you like to visit the store? Y / N" << endl;
    getline(cin, response);
    while (response == "" || response != "Y" && response != "y" && response != "N" && response != "n") //MAKE SURE THE INPUT IS A VALID STRING
    {
        cout << "Invalid response please enter Y or N." << endl;
        getline(cin, response);
    }
    if (response == "N" || response == "n")
    {
        cout << "Okay." << endl;
    }
    else if (response == "Y" || response == "y") //IF YOU ARE VISITING THE STORE FOR THE FIRST TIME
    {
        cout << "YOU HAD SAVED $1200 TO SPEND FOR THE TRIP, AND YOU'VE JUST PAID $200 FOR A WAGON. YOU WILL NEED TO SPEND THE REST OF YOUR MONEY ON THE FOLLOWING ITEMS:" << endl;
        cout << "-	OXEN. YOU CAN SPEND $100-$200 ON YOUR TEAM. THE MORE YOU SPEND, THE FASTER YOU'LL GO BECAUSE YOU'LL HAVE BETTER ANIMALS" << endl;
        cout << "-	FOOD. THE MORE YOU HAVE, THE LESS CHANCE THERE IS OF GETTING SICK" << endl;
        cout << "-	AMMUNITION - $2 BUYS A BOX OF 20 BULLETS. YOU WILL NEED BULLETS FOR ATTACKS BY ANIMALS AND BANDITS, AND FOR HUNTING FOOD" << endl;
        cout << "-	MISCELLANEOUS SUPPLIES. THIS INCLUDES MEDICINE AND OTHER THINGS YOU WILL NEED FOR SICKNESS AND EMERGENCY REPAIRS" << endl;
        cout << "YOU CAN SPEND ALL YOUR MONEY BEFORE YOU START YOUR TRIP, OR YOU CAN SAVE SOME OF YOUR CASH TO SPEND AT FORTS ALONG THE WAY WHEN YOU RUN LOW. HOWEVER, ITEMS COST MORE AT THE FORTS. YOU CAN ALSO GO HUNTING ALONG THE WAY TO GET MORE FOOD." << endl;
        
              cout << "Please enter the number of oxen you wish to purchase in digit form. You must spend between $100 and $200 on oxen. A yoke of 2 oxen is $40. This number must only be between 6 and 10." << endl;
              getline(cin, numberOxen);
              while (numberOxen == "" || is_number(numberOxen) != true || member1.getMoney() < (stoi(numberOxen)/2)*40 || numberOxen != "6" && numberOxen != "7" && numberOxen != "8" && numberOxen != "9" && numberOxen != "10")
              {
                  cout << "Invalid or unuseable input. Please enter the number of oxen you wish to purchase in digit form. You must spend between $100 and $200 on oxen. A yoke of 2 oxen is $40. This number must only be between 6 and 10." << endl;
                  getline(cin, numberOxen);
              }

              member1.setMoney(-(stoi(numberOxen)/2)*40); //UPDATE MONEY AFTER EACH TIME
 
              
              cout << "Please enter how many pounds of food you wish to purchase in digit form. It is recommended that you purchase at least 200 lbs of food per person at 50 cents per pound. This number must only be between 0 and 2000." << endl;
              getline(cin, poundsFood);
              while (poundsFood == "" || is_number(poundsFood) != true || member1.getMoney() < (stoi(poundsFood)*.5) || (!(stoi(poundsFood) >= 0 && stoi(poundsFood) <= 2000)) )
              {
                  cout << "Invalid input. Please enter how many pounds of food you wish to purchase in digit form. This number must only be between 0 and 2000." << endl;
                  getline(cin, poundsFood);
              }

              member1.setMoney(-(stoi(poundsFood)*.5));//UPDATE MONEY AFTER EACH TIME
 
              
              cout << "Please enter how many bullets you wish to purchase in digit form. A box of 20 bullets costs $2. This number must only be between 0 and 100." << endl;
              getline(cin, numberBullets);
              while (numberBullets == "" || is_number(numberBullets) != true || member1.getMoney() < (stoi(numberBullets)/20)*2 || !(stoi(numberBullets) >= 0 && stoi(numberBullets) <= 100))
              {
                  cout << "Invalid input. Please enter how many bullets you wish to purchase in digit form. This number must only be between 0 and 100." << endl;
                  getline(cin, numberBullets);
              }

              member1.setMoney(-(stoi(numberBullets)/20)*2);//UPDATE MONEY AFTER EACH TIME
 
              
              cout << "Please enter how many wagon parts you wish to purchase in digit form. A wagon part costs $20. This number must only be between 0 and 10." << endl;
              getline(cin, numberParts);
              while (numberParts == "" || is_number(numberParts) != true || member1.getMoney() < (stoi(numberParts)*20) || !(stoi(numberParts) >= 0 && stoi(numberParts) <= 10))
              {
                  cout << "Invalid input. Please enter how many wagon parts you wish to purchase in digit form. This number must only be between 0 and 10." << endl;
                  getline(cin, numberParts);
              }

              member1.setMoney(-(stoi(numberParts)*20));//UPDATE MONEY AFTER EACH TIME
 
              
              cout << "Please enter how many medical aid kits you wish to purchase in digit form. A medical aid kit costs $25. This number must only be between 0 and 10." << endl;
              getline(cin, numberKits);
              while (numberKits == "" || is_number(numberKits) != true || member1.getMoney() < (stoi(numberKits)*25) || !(stoi(numberKits) >= 0 && stoi(numberKits) <= 10)) 
              {
                  cout << "Invalid input. Please enter how many medical aid kits wish to purchase in digit form. This number must only be between 0 and 10." << endl;
                  getline(cin, numberKits);
              }

              
              member1.setMoney(-(stoi(numberKits)*25));
              
              member1.settotalOxen(stoi(numberOxen)); //SET ALL THE VALUES
              member1.settotalFood(stoi(poundsFood));
              member1.settotalBullets(stoi(numberBullets));
              member1.settotalWagonParts(stoi(numberParts));
              member1.settotalMedicalKits(stoi(numberKits));
    }
    
              int oxenBoys = member1.gettotalOxen();
              int foodGuy = member1.gettotalFood();
              int shotMan = member1.gettotalBullets();
              int wagonKid = member1.gettotalWagonParts();
              int medMen = member1.gettotalMedicalKits();
              
              cout << "Oxen: " << oxenBoys << endl; //PRINT OUT THE RESULTING VARIABLES 
              cout << "Food: " << foodGuy << endl;
              cout << "Bullets: " << shotMan << endl;
              cout << "Wagon Parts: " << wagonKid << endl;
              cout << "Medical Aid Kits: " << medMen << endl;
              
              
    //KEEP ASKING IF THEY WOULD LIKE TO VISIT THE STORE UNTIL THE ANSWER IS NO
    while (response == "Y")
    {
        
    cout << "You can visit the store and buy supplies: food, oxen, bullets and wagon parts. Would you like to visit the store again? Y / N" << endl;
    getline(cin, response);
    while (response == "" || response != "Y" && response != "y" && response != "N" && response != "n")
    {
        cout << "Invalid response please enter Y or N." << endl;
        getline(cin, response);
    }
    if (response == "N" || response == "n")
    {
        cout << "Okay." << endl;
    }
    else if (response == "Y" || response == "y")
    {
              cout << "Please enter the number of oxen you wish to purchase in digit form.  A yoke of 2 oxen is $40. This number must only be between 0 and 10." << endl;
              getline(cin, numberOxen);
              while (numberOxen == "" || is_number(numberOxen) != true || member1.getMoney() < (stoi(numberOxen)/2)*40 || numberOxen != "0" && numberOxen != "1" && numberOxen != "2" && numberOxen != "3" && numberOxen != "4" && numberOxen != "5" && numberOxen != "6" && numberOxen != "7" && numberOxen != "8" && numberOxen != "9" && numberOxen != "10")
              {
                  cout << "Invalid or unuseable input. Please enter the number of oxen you wish to purchase in digit form. A yoke of 2 oxen is $40. This number must only be between 0 and 10." << endl;
                  getline(cin, numberOxen);
              }

              member1.setMoney(-(stoi(numberOxen)/2)*40);
 
              
              cout << "Please enter how many pounds of food you wish to purchase in digit form. Food is 50 cents per pound. This number must only be between 0 and 2000." << endl;
              getline(cin, poundsFood);
              while (poundsFood == "" || is_number(poundsFood) != true || member1.getMoney() < (stoi(poundsFood)*.5) || (!(stoi(poundsFood) >= 0 && stoi(poundsFood) <= 2000)) )
              {
                  cout << "Invalid input. Please enter how many pounds of food you wish to purchase in digit form. This number must only be between 0 and 2000." << endl;
                  getline(cin, poundsFood);
              }

              member1.setMoney(-(stoi(poundsFood)*.5));
              
              cout << "Please enter how many bullets you wish to purchase in digit form. A box of 20 bullets costs $2. This number must only be between 0 and 100." << endl;
              getline(cin, numberBullets);
              while (numberBullets == "" || is_number(numberBullets) != true || member1.getMoney() < (stoi(numberBullets)/20)*2 || !(stoi(numberBullets) >= 0 && stoi(numberBullets) <= 100))
              {
                  cout << "Invalid input. Please enter how many bullets you wish to purchase in digit form. This number must only be between 0 and 100." << endl;
                  getline(cin, numberBullets);
              }
 
              member1.setMoney(-(stoi(numberBullets)/20)*2);
              
              cout << "Please enter how many wagon parts you wish to purchase in digit form. A wagon part costs $20. This number must only be between 0 and 10." << endl;
              getline(cin, numberParts);
              while (numberParts == "" || is_number(numberParts) != true || member1.getMoney() < (stoi(numberParts)*20) || !(stoi(numberParts) >= 0 && stoi(numberParts) <= 10))
              {
                  cout << "Invalid input. Please enter how many wagon parts you wish to purchase in digit form. This number must only be between 0 and 10." << endl;
                  getline(cin, numberParts);
              }

              member1.setMoney(-(stoi(numberParts)*20));
              
              cout << "Please enter how many medical aid kits you wish to purchase in digit form. A medical aid kit costs $25. This number must only be between 0 and 10." << endl;
              getline(cin, numberKits);
              while (numberKits == "" || is_number(numberKits) != true || member1.getMoney() < (stoi(numberKits)*25) || !(stoi(numberKits) >= 0 && stoi(numberKits) <= 10)) 
              {
                  cout << "Invalid input. Please enter how many medical aid kits wish to purchase in digit form. This number must only be between 0 and 10." << endl;
                  getline(cin, numberKits);
              }

              member1.setMoney(-(stoi(numberKits)*25));
              
              member1.settotalOxen(stoi(numberOxen));
              member1.settotalFood(stoi(poundsFood));
              member1.settotalBullets(stoi(numberBullets));
              member1.settotalWagonParts(stoi(numberParts));
              member1.settotalMedicalKits(stoi(numberKits));

    }     
              oxenBoys = member1.gettotalOxen();
              foodGuy = member1.gettotalFood();
              shotMan = member1.gettotalBullets();
              wagonKid = member1.gettotalWagonParts();
              medMen = member1.gettotalMedicalKits();
              
              cout << "Oxen: " << oxenBoys << endl;
              cout << "Food: " << foodGuy << endl;
              cout << "Bullets: " << shotMan << endl;
              cout << "Wagon Parts: " << wagonKid << endl;
              cout << "Medical Aid Kits: " << medMen << endl;
              
    }         
    
    member2.setInflation(.25); //update the first inflation for the next store visit 
              
    //tell them their departure date and ask them if they want to change it. make sure it falls in between 1847-03-01 to 1847-05-01
    cout << "Your current departure date is " << member.getcurrentYear() << '-' << member.getcurrentMonth() << '-' << member.getcurrentDay() << ". Would you like to change it?Y/N" << endl; //check if they would like to cahnge the departure date
    getline(cin, response);
    //{
        if (response != "N" && response != "n" && response != "Y" && response != "y") //amke sure input is valid
        {
            cout << "Invalid response please enter Y or N." << endl;
            getline(cin, response);
        }
        else if (response == "N" || response == "n") //if input is no then leave it as before
        {
            cout << "Your current departure date is still " << member.getcurrentYear() << '-' << member.getcurrentMonth() << '-' << member.getcurrentDay() << "." << endl;
        }
        else if (response == "Y" || response == "y") //if the input is yes then cahnge it to what they wish
        {
            cout << "Enter a month number between 03 and 05." << endl;
            getline(cin, response);
            while (response != "" && response != "03" && response != "04" && response != "05")
            {
                cout << "Invlaid input please enter a day number between 03 and 05." << endl;
                getline(cin, response);
            }
            if (response == "03" || response == "04" || response == "05") 
            {
                member.setcurrentMonthOriginal(stoi(response));
            }
            
            cout << "Enter a day number between 01 and 30. NOTE: If the number is less than 10 please input the value with a 0 in front of it." << endl;
            getline(cin, response);
            while (response != "" && response != "01" && response != "02" && response != "03" && response != "04" && response != "05" && response != "06" && response != "07" && response != "08" && response != "09" && response != "10" && response != "11" && response != "12" && response != "13" && response != "14" && response != "15" && response != "16" && response != "17" && response != "18" && response != "19" && response != "20" && response != "21" && response != "22" && response != "23" && response != "24" && response != "25" && response != "26" && response != "27"&& response != "28" && response != "29" && response != "30")
            {
                cout << "Invlaid input please enter a month number between 01 and 30. NOTE: If the number is less than 10 please input the value with a 0 in front of it." << endl;
                getline(cin, response);
            }
            if (response == "01" || response == "02" || response == "03" || response == "04" || response == "05" || response == "06" || response == "07" || response == "08" || response == "09" || response == "10" || response == "11" || response == "12" || response == "13" || response == "14" || response == "15" || response == "16" || response == "17" || response == "18" || response == "19" || response == "20" || response == "21" || response == "22" || response == "23" || response == "24" || response == "25" || response == "26" || response == "27"|| response == "28" || response == "29" || response == "30") 
            {
                member.setcurrentDayOriginal(stoi(response));
            }

            cout << "Your new start date is " << member.getcurrentYear() << '-' << member.getcurrentMonthOriginal() << '-' << member.getcurrentDayOriginal() << "." << endl;
        }
    //}
    
    cout << "Let the journey begin" << endl;
    member2.setmilestoneDistance(0);
    int milestonedis1 = member2.getmilestoneDistance();
    int mi1 = member2.getmilesTraveled();
    
    int yummy1 = member1.gettotalFood();
    int shots1 = member1.gettotalBullets();
    int dinero1 = member1.getMoney();
    
    member.setStatusUpdate(mi1, milestonedis1, yummy1, shots1, dinero1);
    
    if (choice == "4") //print out this if the game ends 
    {
        cout << "Leader: " << playerName << endl;
        cout << "Miles Traveled: " << member2.getmilesTraveled() << endl;
        cout << "Food Remaining: " << member1.gettotalFood() << endl;
        cout << "Cash Remaining: " << member1.getMoney() << endl;
    }
    
    if (member.getcurrentDay() == 30 && member.getcurrentMonth() == 11) //if you have not reach 2040 then you lose
    {
        cout << "The day is November 30th and you have not made it to Oregon City. You lose." << endl;
        choice = "4";
    }
    
    
    
    while (choice != "4") { //while you don't quit
        
            
            
        if (choice != "4")
        {
            if (member2.getmilesTraveled() >= 2040)
            {
                cout << "You have made it to Oregon City! Congrats you win the game!" << endl;
                cout << "Leader: " << playerName << endl;
                cout << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                cout << "Food Remaining: " << member1.gettotalFood() << endl;
                cout << "Cash Remaining: " << member1.getMoney() << endl;
                
                ofstream file;
                file.open("results.txt");
                if (file.is_open())
                {
                    file << "Leader: " << playerName << endl;
                    file << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                    file << "Food Remaining: " << member1.gettotalFood() << endl;
                    file << "Cash Remaining: " << member1.getMoney() << endl;
                }
                file.close();
                break;
                
            }
            member2.setmilestoneDistance(member2.getmilesTraveled());
            milestonedis1 = member2.getmilestoneDistance();
            mi1 = member2.getmilesTraveled();
            yummy1 = member1.gettotalFood();
            shots1 = member1.gettotalBullets();
            dinero1 = member1.getMoney();
            
            //print out the status update each time
            
            member.setStatusUpdate(mi1, milestonedis1, yummy1, shots1, dinero1);
            
            if (member1.gettotalFood() <= 0) //if food is 0 then end
            {
                member1.settotalFood1(0);
              cout << "You have run out of food! The game is over." << endl;
              choice = "4";
                cout << "Leader: " << playerName << endl;
                cout << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                cout << "Food Remaining: " << member1.gettotalFood() << endl;
                cout << "Cash Remaining: " << member1.getMoney() << endl;
                
                ofstream file;
                file.open("results.txt");
                if (file.is_open())
                {
                    file << "Leader: " << playerName << endl;
                    file << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                    file << "Food Remaining: " << member1.gettotalFood() << endl;
                    file << "Cash Remaining: " << member1.getMoney() << endl;
                }
                file.close();

                break;
            }
            if (member1.gettotalOxen() <= 0) //if oxen is 0 then end
            {
                member1.settotalOxen1(0);
                cout << "All of your oxen have died! The game is over." << endl;
                choice = "4";
                cout << "Leader: " << playerName << endl;
                cout << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                cout << "Food Remaining: " << member1.gettotalFood() << endl;
                cout << "Cash Remaining: " << member1.getMoney() << endl;
                
                ofstream file;
                file.open("results.txt");
                if (file.is_open())
                {
                    file << "Leader: " << playerName << endl;
                    file << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                    file << "Food Remaining: " << member1.gettotalFood() << endl;
                    file << "Cash Remaining: " << member1.getMoney() << endl;
                }
                file.close();
                
                break;
            }
            // TEst to see if this works!!
            
            returnMilestone = member2.getMilestones(); //run return milestone
            //cout << returnMilestone << endl;
            if (returnMilestone == 1)
            {
                if (member2.getmilesTraveled() < member2.getriverDistances(member2.getHolderRiver()))
                {
                    cout << "The next milestone is " << member2.getrivers(member2.getHolderRiver()) << "." << endl;
                    milestoneDistance = member2.getriverDistances(member2.getHolderRiver()) - member2.getmilesTraveled();  //check the distance at the holder and compare
                    member2.setmilestoneDistance1(milestoneDistance);
                    cout << "The distance to this milestone is " << member2.getmilestoneDistance() << " miles." << endl;
                } 
                else if (member2.getmilesTraveled() >= member2.getriverDistances(member2.getHolderRiver()))  //if you have reached the milestone stop them
                {
                    cout << "You were prepared to travel " << member2.getmilesTraveled() << " but you arrived at the " << member2.getrivers(member2.getHolderRiver()) << ". What do you want to do? (1) REST, (2) CROSS THE RIVER" << endl; //prompt with options
                    getline(cin, answer);
                    while (answer != "1" && answer != "2")
                    {
                    cout << "Invalid input, please input (1) REST, or (2) CROSS THE RIVER." << endl;
                    getline(cin, answer);
                    }
           
                    while (answer == "1")
                    {
                        cout << "You chose to rest." << endl;
   
                        int numberDays = 1;
                        int food = numberofPlayers*3*numberDays;
   
                        member.setcurrentDay(numberDays);
                        member.setcurrentMonth(member.getcurrentDay());
                        member1.settotalFood(-food);
                        if (food >= member1.gettotalFood())
                        {
                            member1.settotalFood1(0); //RUN OUT OF FOOD
                            cout << "You have run out of food, the game must be over." << endl;
                            choice = "4";
                            cout << "Leader: " << playerName << endl;
                            cout << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                            cout << "Food Remaining: " << member1.gettotalFood() << endl;
                            cout << "Cash Remaining: " << member1.getMoney() << endl;
                            
                            ofstream file;
                            file.open("results.txt");
                            if (file.is_open())
                            {
                                file << "Leader: " << playerName << endl;
                                file << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                                file << "Food Remaining: " << member1.gettotalFood() << endl;
                                file << "Cash Remaining: " << member1.getMoney() << endl;
                            }
                            file.close();
                
                            break;
                        } 
                        else if (food < member1.gettotalFood()) //if you aren't out of food do this
                        {
                            cout << "You have chosen to rest for 1 day. Food will be consumed accordingly and your health will improve as well." << endl;
   
                            cout << "You were prepared to travel " << member2.getmilesTraveled() << " but you arrived at the " << member2.getrivers(member2.getHolderRiver()) << ". What do you want to do? (1) REST, (2) CROSS THE RIVER" << endl;
                            getline(cin, answer);
                            while (answer != "1" && answer != "2")
                            {
                                cout << "Invalid input, please input (1) REST, or (2) CROSS THE RIVER." << endl;
                            }
                            
                        }
              
                        
                    }
           
                    if (answer == "2")
                    {
                        if(member2.getriverDepth(member2.getHolderRiver()) > 3)
                        {
                            cout << member2.getrivers(member2.getHolderRiver()) << " is deeper than 3 feet, so it requires a ferry to cross. The ferry will cost you $10." << endl;
                            member1.setMoney(-10);
                        }
                    }

                    member2.setmilesTraveled1(member2.getriverDistances(member2.getHolderRiver()));
                    //milesTraveled = riverDistances[holderRiver];
                    member2.setHolderRiver(1); 
                    //holderRiver++;
                    
                }
       
      
            }
            if (returnMilestone == 2) //IF MILESTRAVELED IS LESS THEN THE FORT DISTANCE
            {
                
                if (member2.getmilesTraveled() < member2.getfortDistances(member2.getHolderFort()))
                {
                    cout << "The next milestone is " << member2.getforts(member2.getHolderFort()) << "." << endl;
                    milestoneDistance = member2.getfortDistances(member2.getHolderFort()) - member2.getmilesTraveled(); 
                    member2.setmilestoneDistance1(milestoneDistance);
                    cout << "The distance to this milestone is " << member2.getmilestoneDistance() << " miles." << endl;
                }
                else if (member2.getmilesTraveled() >= member2.getfortDistances(member2.getHolderFort())) //IF IT IS GREATER THAN FORT DISTANCE
                {

                    cout << "You were prepared to travel " << member2.getmilesTraveled() << " but you arrived at the " << member2.getforts(member2.getHolderFort()) << ". What do you want to do? (1) REST, (2) VISIT STORE (3) CONTINUE" << endl; //STOP THEM AND GIVE THEM 3 OPTIONS
                    getline(cin, answer);
                    while (answer != "1" && answer != "2" && answer != "3")
                    {
                        cout << "Invalid input, please input (1) REST, (2) VISIT STORE (3) CONTINUE." << endl;
                        getline(cin, answer);
                    }
           
                    while (answer == "1")
                    {
                        cout << "You chose to rest." << endl; //IF YOU REST
                        
                        int numberDays = 1;
                        int food = numberofPlayers*3*numberDays;
   
                        member.setcurrentDay(numberDays);
                        member.setcurrentMonth(member.getcurrentDay());
                        member1.settotalFood(-food);
                        
                        if (food >= member1.gettotalFood())
                        {
                            member1.settotalFood1(0); //RUN OUT OF FOOD
                            cout << "You have run out of food, the game must be over." << endl;
                            choice = "4";
                            cout << "Leader: " << playerName << endl;
                            cout << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                            cout << "Food Remaining: " << member1.gettotalFood() << endl;
                            cout << "Cash Remaining: " << member1.getMoney() << endl;
                            
                            ofstream file;
                            file.open("results.txt");
                            if (file.is_open())
                            {
                                file << "Leader: " << playerName << endl;
                                file << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                                file << "Food Remaining: " << member1.gettotalFood() << endl;
                                file << "Cash Remaining: " << member1.getMoney() << endl;
                            }
                            file.close();
                            
                            break;
                        } 
                        else if (food < member1.gettotalFood()) //IF FOOD IS LESS THEN THE TOTAL YOU CONTINUE ON
                        {
                            cout << "You have chosen to rest for 1 day. Food will be consumed accordingly and your health will improve as well." << endl;
   
                            cout << "You were prepared to travel " << member2.getmilesTraveled() << " but you arrived at the " << member2.getforts(member2.getHolderFort()) << ". What do you want to do? (1) REST, (2) VISIT STORE (3) CONTINUE." << endl;
                            getline(cin, answer);
                            while (answer != "1" && answer != "2" && answer != "3")
                            {
                                cout << "Invalid input, please input (1) REST, (2) VISIT STORE (3) CONTINUE." << endl;
                                getline(cin, answer);
                            }
                        }
              

                    }
    
                    while (answer == "2") //ALLOW THEM TO VISIT THE STORE 
                    {
                        
                        returnTrail = 7;
                        cout << "You have chosen to visit the store. Please enter the number of oxen you wish to purchase in digit form. A yoke of 2 oxen is $" << 40*member2.getInflation() << ". This number must only be between 0 and 10." << endl;
                        getline(cin, numberOxen);
                        while (numberOxen == "" || member1.getMoney() < (stoi(numberOxen)/2)*40*member2.getInflation() || numberOxen != "0" && numberOxen != "1" && numberOxen != "2" && numberOxen != "3" && numberOxen != "4" && numberOxen != "5" && numberOxen != "6" && numberOxen != "7" && numberOxen != "8" && numberOxen != "9" && numberOxen != "10")
                        {
                            cout << "Invalid input. Please enter the number of oxen you wish to purchase in digit form. This number must only be between 1 and 10." << endl;
                            getline(cin, numberOxen);
                        }
                        
                        member1.setMoney(-(stoi(numberOxen)/2)*40*member2.getInflation());
              
                        cout << "Please enter how many pounds of food you wish to purchase in digit form. A pound of food is$ " << .5*member2.getInflation() << ". This number must only be between 0 and 400." << endl;
                        getline(cin, poundsFood);
                        while (poundsFood == "" ||  member1.getMoney() < (stoi(poundsFood)*.5*member2.getInflation()) || (!(stoi(poundsFood) >= 0 && stoi(poundsFood) <= 400)))
                        {
                            cout << "Invalid input. Please enter how many pounds of food you wish to purchase in digit form. This number must only be between 0 and 400." << endl;
                            getline(cin, poundsFood);
                        }
                        
                        member1.setMoney(-(stoi(poundsFood)*.5*member2.getInflation()));
              
                        cout << "Please enter how many bullets you wish to purchase in digit form. A box of 20 bullets is $" << 2*member2.getInflation() << ". This number must only be between 0 and 100." << endl;
                        getline(cin, numberBullets);
                        while (numberBullets == "" ||  member1.getMoney() < (stoi(numberBullets)/20)*2*member2.getInflation() || !(stoi(numberBullets) >= 0 && stoi(numberBullets) <= 100))
                        {
                            cout << "Invalid input. Please enter how many bullets you wish to purchase in digit form. This number must only be between 0 and 100." << endl;
                            getline(cin, numberBullets);
                        }
                        
                        member1.setMoney(-(stoi(numberBullets)/20)*2*member2.getInflation());
              
                        cout << "Please enter how many wagon parts you wish to purchase in digit form. A wagon part costs $" << 20*member2.getInflation() << ". This number must only be between 0 and 10." << endl;
                        getline(cin, numberParts);
                        while (numberParts == ""  || member1.getMoney() < (stoi(numberParts)*20*member2.getInflation()) || !(stoi(numberParts) >= 0 && stoi(numberParts) <= 10))
                        {
                            cout << "Invalid input. Please enter how many wagon parts you wish to purchase in digit form. This number must only be between 0 and 10." << endl;
                            getline(cin, numberParts);
                        }
                        
                        member1.setMoney(-(stoi(numberParts)*20*member2.getInflation()));
                        
                        cout << "Please enter how many medical aid kits you wish to purchase in digit form. A medical aid kit costs $" << 25*member2.getInflation() << ". This number must only be between 0 and 10." << endl;
                        getline(cin, numberKits);
                        while (numberKits == "" || member1.getMoney() < (stoi(numberKits)*25*member2.getInflation()) || !(stoi(numberKits) >= 0 && stoi(numberKits) <= 10))
                        {
                            cout << "Invalid input. Please enter how many medical aid kits wish to purchase in digit form. This number must only be between 0 and 10." << endl;
                            getline(cin, numberKits);
                        }
                        
                        member1.setMoney(-(stoi(numberKits)*25*member2.getInflation()));
 //UPDATE ALL THE VALUES AND THEN PRINT THEM OUT
                        member1.settotalOxen(stoi(numberOxen));
                        member1.settotalFood(stoi(poundsFood));
                        member1.settotalBullets(stoi(numberBullets));
                        member1.settotalWagonParts(stoi(numberParts));
                        member1.settotalMedicalKits(stoi(numberKits)); 
                        
                        
                        // member1.setBill(stoi(numberOxen), stoi(poundsFood), stoi(numberBullets), stoi(numberParts), stoi(numberKits), member2.getInflation());
                        // for (int i = 0; i < 5; i++)
                        // {
                        //     cout << member1.getBill(i) << endl;
                        // }
                    }
                    
                        
                        int oxenBoys = member1.gettotalOxen();
                        int foodGuy = member1.gettotalFood();
                        int shotMan = member1.gettotalBullets();
                        int wagonKid = member1.gettotalWagonParts();
                        int medMen = member1.gettotalMedicalKits();
              
                        cout << "Oxen: " << oxenBoys << endl;
                        cout << "Food: " << foodGuy << endl;
                        cout << "Bullets: " << shotMan << endl;
                        cout << "Wagon Parts: " << wagonKid << endl;
                        cout << "Medical Aid Kits: " << medMen << endl;
                    
                    if (answer == "3")
                    {
                        cout << "You have chosen to continue on the trail, your next milestone is " << member2.getforts(member2.getHolderFort() + 1) << ", and it is " << member2.getfortDistances(member2.getHolderFort() + 1) << " miles away." << endl;
                        input1 = member1.gettotalFood();
                        returnTrail = member.continueTrail(input1);
                        if (returnTrail == -1)
                        {
                            member1.settotalFood1(0);
                           cout << "You have run out of food, the game must be over." << endl;
                           choice = "4";
                           cout << "Leader: " << playerName << endl;
                            cout << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                            cout << "Food Remaining: " << member1.gettotalFood() << endl;
                            cout << "Cash Remaining: " << member1.getMoney() << endl;
                            
                            ofstream file;
                            file.open("results.txt");
                            if (file.is_open())
                            {
                                file << "Leader: " << playerName << endl;
                                file << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                                file << "Food Remaining: " << member1.gettotalFood() << endl;
                                file << "Cash Remaining: " << member1.getMoney() << endl;
                            }
                            file.close();
                            
                           break;
                        }
                        else 
                        {
                             member1.settotalFood(-numberofPlayers*3*14);
                             member2.setmilesTraveled(returnTrail);
                        }
                        
                    }
                }
                
                member2.setmilesTraveled1(member2.getfortDistances(member2.getHolderFort()));
                //milesTraveled = fortDistances[holderFort];
                member2.setHolderFort(1);
                //holderFort++;
                member2.setInflation(.25);
                // inflation = inflation + .25;
            
            }



          
          
          
            displayMenu();
            getline(cin, choice);
            
            while (choice != "1" && choice != "2" && choice != "3" && choice != "4")
            {
                cout << "Invalid input. Please try again." << endl;
                cout << endl;
                displayMenu();
                getline(cin, choice);
            }
            
            member2.setmilestoneDistance(member2.getmilesTraveled());
            milestonedis1 = member2.getmilestoneDistance();
            mi1 = member2.getmilesTraveled();
            yummy1 = member1.gettotalFood();
            shots1 = member1.gettotalBullets();
            dinero1 = member1.getMoney();
            
          
           if (choice == "4") 
           {
               cout << "Leader: " << playerName << endl;
                            cout << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                            cout << "Food Remaining: " << member1.gettotalFood() << endl;
                            cout << "Cash Remaining: " << member1.getMoney() << endl;
                            
                            ofstream file;
                            file.open("results.txt");
                            if (file.is_open())
                            {
                                file << "Leader: " << playerName << endl;
                                file << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                                file << "Food Remaining: " << member1.gettotalFood() << endl;
                                file << "Cash Remaining: " << member1.getMoney() << endl;
                            }
                            file.close();
           }
          
           if (member.getcurrentDay() == 30 && member.getcurrentMonth() == 11) //if you have not reach 2040 then you lose
            {
                cout << "The day is November 30th and you have not made it to Oregon City. You lose." << endl;
                choice = "4";
            }
          
            
        }
            
            switch (stoi(choice)) {
                case 1:
                    
                    input1 = member1.gettotalFood(); //CALL THE REST FUNCTION WITH FOOD INPUT
                    cout << numberofPlayers << endl;
                    check = member.rest(numberofPlayers, input1);
                    if (check == -1)
                    {
                        member1.settotalFood1(0);
                        cout << "You have run out of food, the game must be over." << endl;
                        choice = "4";
                        cout << "Leader: " << playerName << endl;
                            cout << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                            cout << "Food Remaining: " << member1.gettotalFood() << endl;
                            cout << "Cash Remaining: " << member1.getMoney() << endl;
                            
                            ofstream file;
                            file.open("results.txt");
                            if (file.is_open())
                            {
                                file << "Leader: " << playerName << endl;
                                file << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                                file << "Food Remaining: " << member1.gettotalFood() << endl;
                                file << "Cash Remaining: " << member1.getMoney() << endl;
                            }
                            file.close();
                            
                        break;
                    }
                    else 
                    {
                        member1.settotalFood(-check); //SET THE FOOD TO THE RETURN
                    }
                     
                    //CALL MISFORTUNE WITH THE FOLLOWING INPUTS
                    input1 = member1.gettotalFood();
                    input2 = member1.gettotalWagonParts();
                    input3 = member1.gettotalOxen();
                    input4 = member1.gettotalMedicalKits();
                    breaker = misfortuneOccur(numberofPlayers, playerName, player1, player2, player3, player4, input1, input2, input3, input4);
                    if (breaker == 1)
                    {
                        member1.settotalOxen(-1);
                    }
                    else if (breaker == 2)
                    {
                        member1.settotalOxen1(0); //RUN OUT OF OXEN
                        cout << "All of your oxen have died, the game is over." << endl;
                        choice = "4";
                        cout << "Leader: " << playerName << endl;
                            cout << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                            cout << "Food Remaining: " << member1.gettotalFood() << endl;
                            cout << "Cash Remaining: " << member1.getMoney() << endl;
                            
                            ofstream file;
                            file.open("results.txt");
                            if (file.is_open())
                            {
                                file << "Leader: " << playerName << endl;
                                file << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                                file << "Food Remaining: " << member1.gettotalFood() << endl;
                                file << "Cash Remaining: " << member1.getMoney() << endl;
                            }
                            file.close();
                            
                        break;
                    }
                    else if (breaker == 3)
                    {
                        member1.settotalWagonParts(-1); //SUBTRACT ONE WAGON PART
                    }
                    else if (breaker == 4)
                    {
                        member1.settotalWagonParts1(0); //FUN OUT OF WAGON PARTS
                        cout << "You have run out of wagon parts and cannot fix your wagon, the game is over." << endl;
                        choice = "4";
                        cout << "Leader: " << playerName << endl;
                            cout << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                            cout << "Food Remaining: " << member1.gettotalFood() << endl;
                            cout << "Cash Remaining: " << member1.getMoney() << endl;
                            
                            ofstream file;
                            file.open("results.txt");
                            if (file.is_open())
                            {
                                file << "Leader: " << playerName << endl;
                                file << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                                file << "Food Remaining: " << member1.gettotalFood() << endl;
                                file << "Cash Remaining: " << member1.getMoney() << endl;
                            }
                            file.close();
                            
                        break;
                    }
                    else if (breaker == 5)
                    {
                        cout << "You have died, the game must be over." << endl;
                        choice = "4";
                        cout << "Leader: " << playerName << endl;
                            cout << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                            cout << "Food Remaining: " << member1.gettotalFood() << endl;
                            cout << "Cash Remaining: " << member1.getMoney() << endl;
                            
                            ofstream file;
                            file.open("results.txt");
                            if (file.is_open())
                            {
                                file << "Leader: " << playerName << endl;
                                file << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                                file << "Food Remaining: " << member1.gettotalFood() << endl;
                                file << "Cash Remaining: " << member1.getMoney() << endl;
                            }
                            file.close();
                            
                        break;
                    }
                    else if (breaker == 6)
                    {
                        member1.settotalMedicalKits(-1); //SUBTRACT A MEDICAL AID KIT
                    }
                    else if (breaker == 8)
                    {
                        int numberQ;
                        int numberP;
                        string person;
                        string talk;
                        numberP = randomNumbers3(1, 5);
                        numberQ = randomNumbers3(0, 100);
                        
                        //SET PERSONT TO VALUE IN NUMBERP
                        if (numberP == 1)
                        {
                            person = playerName;
                        }
                        else if (numberP == 2)
                        {
                            person = player1;
                        }
                        else if (numberP == 3)
                        {
                            person = player2;
                        }
                        else if (numberP == 4)
                        {
                            person = player3;
                        }
                        else if (numberP == 5)
                        {
                            person = player4;
                        }
                        
                        
                        cout << person << " is sick and you do not have any medical aid kits. You would like to rest (1) or press on (2)? If you rest, you must rest for 3 days and " << person << " still has a %30 chance of dying. If you press on " << person << " has a %70 chance of dying." << endl;
                        getline(cin, talk);
                        while(talk != "1" && talk != "2")
                        {
                            cout << "Invalid input. Please chose to rest (1) or press on (2)." << endl;
                            getline(cin, talk);
                        }
                        if (talk == "1")
                        {

                            cout << "You have chosen to rest for 3 days. Food will be consumed accordingly and your health will improve as well." << endl;

                            int numberDays = 3;
                            int food = numberofPlayers*3*numberDays;
                            bool check = true;
                            int foodResult;
   
                            member.setcurrentDay(numberDays);
                            member.setcurrentMonth(member.getcurrentDay());

                            if (food >= input1)
                            {
                                member1.settotalFood(-food);
                            }
                            else if (food < input1)
                            {
                                member1.settotalFood1(0); //RUN OUT OF FOOD
                                cout << "You have run out of food, the game must be over." << endl;
                                choice = "4";
                                cout << "Leader: " << playerName << endl;
                                cout << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                                cout << "Food Remaining: " << member1.gettotalFood() << endl;
                                cout << "Cash Remaining: " << member1.getMoney() << endl;
                            
                                ofstream file;
                                file.open("results.txt");
                                if (file.is_open())
                                {
                                    file << "Leader: " << playerName << endl;
                                    file << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                                    file << "Food Remaining: " << member1.gettotalFood() << endl;
                                    file << "Cash Remaining: " << member1.getMoney() << endl;
                                }
                                file.close();
                            
                                break;
                            }

                            if (numberQ <=30)
                            {
                        
                                cout << "Oh no! You chose to rest but " << person << " still died of dysentery!" << endl;
                                
                                if (numberP == 1)
                                {
                                    numberofPlayers--; //IF YOU DIE GAME IS OVER
                                    cout << "You have died, the game must be over." << endl;
                                    choice = "4";
                                    cout << "Leader: " << playerName << endl;
                                    cout << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                                    cout << "Food Remaining: " << member1.gettotalFood() << endl;
                                    cout << "Cash Remaining: " << member1.getMoney() << endl;
                                    
                                    ofstream file;
                                    file.open("results.txt");
                                    if (file.is_open())
                                    {
                                        file << "Leader: " << playerName << endl;
                                        file << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                                        file << "Food Remaining: " << member1.gettotalFood() << endl;
                                        file << "Cash Remaining: " << member1.getMoney() << endl;
                                    }
                                    file.close();
                            
                                    break;
                              
                                }
                                else if (numberP == 2)
                                {
                                    player1 = "";
                                    numberofPlayers--;
                                }
                                else if (numberP == 3)
                                {
                                    player2 = "";
                                    numberofPlayers--;
                                }
                                else if (numberP == 4)
                                {
                                    player3 = "";
                                    numberofPlayers--;
                                }
                                else if (numberP == 5)
                                {
                                    player4 = "";
                                    numberofPlayers--;
                                }
                            }
                            else 
                            {
                                cout << person << " did not die!" << endl;
                            }
                        }
                        if (talk == "2")
                        {
                            if (numberQ <= 70)
                            {
                                cout << "Oh no! You chose to press on and " << person << " died of dysentery!" << endl; //IF YOU PRESS ON THEN TAKE THIS ROUTE 
                                if (numberP == 1)
                                {
                                    numberofPlayers--;
                                    cout << "You have died, the game must be over." << endl; //GAME IS OVER IF YOU DIE
                                    choice = "4";
                                    cout << "Leader: " << playerName << endl;
                                    cout << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                                    cout << "Food Remaining: " << member1.gettotalFood() << endl;
                                    cout << "Cash Remaining: " << member1.getMoney() << endl;
                                    
                                    ofstream file;
                                    file.open("results.txt");
                                    if (file.is_open())
                                    {
                                        file << "Leader: " << playerName << endl;
                                        file << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                                        file << "Food Remaining: " << member1.gettotalFood() << endl;
                                        file << "Cash Remaining: " << member1.getMoney() << endl;
                                    }
                                    file.close();
                            
                                    break;
                              
                                }
                                else if (numberP == 2)
                                {
                                    player1 = "";
                                    numberofPlayers--;
                                }
                                else if (numberP == 3)
                                {
                                    player2 = "";
                                    numberofPlayers--;
                                }
                                else if (numberP == 4)
                                {
                                    player3 = "";
                                    numberofPlayers--;
                                }
                                else if (numberP == 5)
                                {
                                    player4 = "";
                                    numberofPlayers--;
                                }
                            }
                        }
                    }
                
             
                    
                    input2 = member1.gettotalWagonParts();
                    input3 = member1.gettotalOxen();
                    input4 = member1.gettotalFood();
                    input5 = member1.gettotalBullets();
                    input6 = member1.getMoney();
                    returnRaider = raiderAttack(input1, input2, input3, input4, input5, input6); //CALL RAIDER ATTACK
                    if (returnRaider == 1)
                    {
                        member1.settotalOxen(-1);
                        member1.settotalFood(-10);
                        member1.settotalWagonParts(-1);
                        if (member1.gettotalOxen() <= 0)
                        {
                            member1.settotalOxen1(0); //OXEN IS 0
                            cout << "All of your oxen have died, the game is over." << endl;
                            choice = "4";
                            cout << "Leader: " << playerName << endl;
                            cout << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                            cout << "Food Remaining: " << member1.gettotalFood() << endl;
                            cout << "Cash Remaining: " << member1.getMoney() << endl;
                            
                            ofstream file;
                            file.open("results.txt");
                            if (file.is_open())
                            {
                                file << "Leader: " << playerName << endl;
                                file << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                                file << "Food Remaining: " << member1.gettotalFood() << endl;
                                file << "Cash Remaining: " << member1.getMoney() << endl;
                            }
                            file.close();
                        }
                        else if (member1.gettotalFood() <= 0)
                        {
                            member1.settotalFood1(0); //FOOD IS 0
                            cout << "You have run out of food, the game must be over." << endl;
                            choice = "4";
                            cout << "Leader: " << playerName << endl;
                            cout << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                            cout << "Food Remaining: " << member1.gettotalFood() << endl;
                            cout << "Cash Remaining: " << member1.getMoney() << endl;
                            
                            ofstream file;
                            file.open("results.txt");
                            if (file.is_open())
                            {
                                file << "Leader: " << playerName << endl;
                                file << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                                file << "Food Remaining: " << member1.gettotalFood() << endl;
                                file << "Cash Remaining: " << member1.getMoney() << endl;
                            }
                            file.close();
                        }
                        else if (member1.gettotalWagonParts() <= 0)
                        {
                            member1.settotalWagonParts1(0); //WAGON PARTS IS 0
                            cout << "You have run out of wagon parts and cannot fix your wagon, the game is over." << endl;
                            choice = "4";
                            cout << "Leader: " << playerName << endl;
                            cout << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                            cout << "Food Remaining: " << member1.gettotalFood() << endl;
                            cout << "Cash Remaining: " << member1.getMoney() << endl;
                            
                            ofstream file;
                            file.open("results.txt");
                            if (file.is_open())
                            {
                                file << "Leader: " << playerName << endl;
                                file << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                                file << "Food Remaining: " << member1.gettotalFood() << endl;
                                file << "Cash Remaining: " << member1.getMoney() << endl;
                            }
                            file.close();
                        }
                        break;    
                    }
                    else if (returnRaider == 2)
                    {
                        member1.settotalFood(50);
                        member1.settotalBullets(50);
                    }
                    else if (returnRaider == 3)
                    {
                        cash = member1.getMoney();
                        member1.setMoney(-(cash*.25));
                        member1.settotalBullets(-50);
                        if (member1.gettotalBullets() <= 0)
                        {
                            member1.settotalBullets1(0);
                        }
                    }
                    else if (returnRaider == 4)
                    {
                        cash = member1.getMoney();
                        member1.setMoney(-(cash*.25));
                    }

                    cout << endl;
                    break;

                case 2:

                    input1 = member1.gettotalFood();
                    returnTrail = member.continueTrail(input1); //CALL THE CONTINUE FUNCTION
                    if (returnTrail == -1)
                    {
                        member1.settotalFood1(0); //FOOD IS 0
                        cout << "You have run out of food, the game must be over." << endl;
                        choice = "4";
                        cout << "Leader: " << playerName << endl;
                            cout << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                            cout << "Food Remaining: " << member1.gettotalFood() << endl;
                            cout << "Cash Remaining: " << member1.getMoney() << endl;
                            
                            ofstream file;
                            file.open("results.txt");
                            if (file.is_open())
                            {
                                file << "Leader: " << playerName << endl;
                                file << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                                file << "Food Remaining: " << member1.gettotalFood() << endl;
                                file << "Cash Remaining: " << member1.getMoney() << endl;
                            }
                            file.close();
                            
                        break;
                    }
                    else 
                    {
                        member1.settotalFood(-5*3*14);
                        member2.setmilesTraveled(returnTrail);
                    }
                    
                    //SAME AS IN CASE 1
                    input1 = member1.gettotalFood();
                    input2 = member1.gettotalWagonParts();
                    input3 = member1.gettotalOxen();
                    input4 = member1.gettotalMedicalKits();
                    breaker = misfortuneOccur(numberofPlayers, playerName, player1, player2, player3, player4, input1, input2, input3, input4);
                    if (breaker == 1)
                    {
                        member1.settotalOxen(-1);
                    }
                    else if (breaker == 2)
                    {
                        member1.settotalOxen1(0); //
                        cout << "All of your oxen have died, the game is over." << endl;
                        choice = "4";
                        cout << "Leader: " << playerName << endl;
                            cout << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                            cout << "Food Remaining: " << member1.gettotalFood() << endl;
                            cout << "Cash Remaining: " << member1.getMoney() << endl;
                            
                            ofstream file;
                            file.open("results.txt");
                            if (file.is_open())
                            {
                                file << "Leader: " << playerName << endl;
                                file << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                                file << "Food Remaining: " << member1.gettotalFood() << endl;
                                file << "Cash Remaining: " << member1.getMoney() << endl;
                            }
                            file.close();
                            
                        break;
                    }
                    else if (breaker == 3)
                    {
                        member1.settotalWagonParts(-1);
                    }
                    else if (breaker == 4)
                    {
                        member1.settotalWagonParts1(0);
                        cout << "You have run out of wagon parts and cannot fix your wagon, the game is over." << endl;
                        choice = "4";
                        cout << "Leader: " << playerName << endl;
                            cout << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                            cout << "Food Remaining: " << member1.gettotalFood() << endl;
                            cout << "Cash Remaining: " << member1.getMoney() << endl;
                            
                            ofstream file;
                            file.open("results.txt");
                            if (file.is_open())
                            {
                                file << "Leader: " << playerName << endl;
                                file << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                                file << "Food Remaining: " << member1.gettotalFood() << endl;
                                file << "Cash Remaining: " << member1.getMoney() << endl;
                            }
                            file.close();
                            
                        break;
                    }
                    else if (breaker == 5)
                    {
                        cout << "You have died, the game must be over." << endl;
                        choice = "4";
                        cout << "Leader: " << playerName << endl;
                            cout << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                            cout << "Food Remaining: " << member1.gettotalFood() << endl;
                            cout << "Cash Remaining: " << member1.getMoney() << endl;
                            
                            ofstream file;
                            file.open("results.txt");
                            if (file.is_open())
                            {
                                file << "Leader: " << playerName << endl;
                                file << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                                file << "Food Remaining: " << member1.gettotalFood() << endl;
                                file << "Cash Remaining: " << member1.getMoney() << endl;
                            }
                            file.close();
                            
                        break;
                    }
                    else if (breaker == 6)
                    {
                        member1.settotalMedicalKits(-1);
                    }
                    else if (breaker == 8)
                    {
                        int numberQ;
                        int numberP;
                        string person;
                        string talk;
                        numberP = randomNumbers3(1, 5);
                        numberQ = randomNumbers3(0, 100);
                        
                        
                        if (numberP == 1)
                        {
                            person = playerName;
                        }
                        else if (numberP == 2)
                        {
                            person = player1;
                        }
                        else if (numberP == 3)
                        {
                            person = player2;
                        }
                        else if (numberP == 4)
                        {
                            person = player3;
                        }
                        else if (numberP == 5)
                        {
                            person = player4;
                        }
                        
                        
                        cout << person << " is sick and you do not have any medical aid kits. You would like to rest (1) or press on (2)? If you rest, you must rest for 3 days and " << person << " still has a %30 chance of dying. If you press on " << person << " has a %70 chance of dying." << endl;
                        getline(cin, talk);
                        while(talk != "1" && talk != "2")
                        {
                            cout << "Invalid input. Please chose to rest (1) or press on (2)." << endl;
                            getline(cin, talk);
                        }
                        if (talk == "1")
                        {

                            cout << "You have chosen to rest for 3 days. Food will be consumed accordingly and your health will improve as well." << endl;

                            int numberDays = 3;
                            int food = numberofPlayers*3*numberDays;
                            bool check = true;
                            int foodResult;
   
                            member.setcurrentDay(numberDays);
                            member.setcurrentMonth(member.getcurrentDay());

                            if (food >= input1)
                            {
                                member1.settotalFood(-food);
                            }
                            else if (food < input1)
                            {
                                member1.settotalFood1(0);
                                cout << "You have run out of food, the game must be over." << endl;
                                choice = "4";
                                cout << "Leader: " << playerName << endl;
                                cout << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                                cout << "Food Remaining: " << member1.gettotalFood() << endl;
                                cout << "Cash Remaining: " << member1.getMoney() << endl;
                            
                                ofstream file;
                                file.open("results.txt");
                                if (file.is_open())
                                {
                                    file << "Leader: " << playerName << endl;
                                    file << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                                    file << "Food Remaining: " << member1.gettotalFood() << endl;
                                    file << "Cash Remaining: " << member1.getMoney() << endl;
                                }
                                file.close();
                            
                                break;
                            }

                            if (numberQ <=30)
                            {
                        
                                cout << "Oh no! You chose to rest but " << person << " still died of dysentery!" << endl;
                                
                                if (numberP == 1)
                                {
                                    numberofPlayers--;
                                    cout << "You have died, the game must be over." << endl;
                                    choice = "4";
                                    cout << "Leader: " << playerName << endl;
                                    cout << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                                    cout << "Food Remaining: " << member1.gettotalFood() << endl;
                                    cout << "Cash Remaining: " << member1.getMoney() << endl;
                                    
                                    ofstream file;
                                    file.open("results.txt");
                                    if (file.is_open())
                                    {
                                        file << "Leader: " << playerName << endl;
                                        file << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                                        file << "Food Remaining: " << member1.gettotalFood() << endl;
                                        file << "Cash Remaining: " << member1.getMoney() << endl;
                                    }
                                    file.close();
                            
                                    break;
                              
                                }
                                else if (numberP == 2)
                                {
                                    player1 = "";
                                    numberofPlayers--;
                                }
                                else if (numberP == 3)
                                {
                                    player2 = "";
                                    numberofPlayers--;
                                }
                                else if (numberP == 4)
                                {
                                    player3 = "";
                                    numberofPlayers--;
                                }
                                else if (numberP == 5)
                                {
                                    player4 = "";
                                    numberofPlayers--;
                                }
                            }
                            else 
                            {
                                cout << person << " did not die!" << endl;
                            }
                        }
                        if (talk == "2")
                        {
                            if (numberQ <= 70)
                            {
                                cout << "Oh no! You chose to press on and " << person << " died of dysentery!" << endl;
                                if (numberP == 1)
                                {
                                    numberofPlayers--;
                                    cout << "You have died, the game must be over." << endl;
                                    choice = "4";
                                    cout << "Leader: " << playerName << endl;
                                    cout << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                                    cout << "Food Remaining: " << member1.gettotalFood() << endl;
                                    cout << "Cash Remaining: " << member1.getMoney() << endl;
                                    
                                    ofstream file;
                                    file.open("results.txt");
                                    if (file.is_open())
                                    {
                                        file << "Leader: " << playerName << endl;
                                        file << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                                        file << "Food Remaining: " << member1.gettotalFood() << endl;
                                        file << "Cash Remaining: " << member1.getMoney() << endl;
                                    }
                                    file.close();
                            
                                    break;
                              
                                }
                                else if (numberP == 2)
                                {
                                    player1 = "";
                                    numberofPlayers--;
                                }
                                else if (numberP == 3)
                                {
                                    player2 = "";
                                    numberofPlayers--;
                                }
                                else if (numberP == 4)
                                {
                                    player3 = "";
                                    numberofPlayers--;
                                }
                                else if (numberP == 5)
                                {
                                    player4 = "";
                                    numberofPlayers--;
                                }
                            }
                        }
                    }
                    //SAME AS CASE 1
                    input2 = member1.gettotalWagonParts();
                    input3 = member1.gettotalOxen();
                    input4 = member1.gettotalFood();
                    input5 = member1.gettotalBullets();
                    input6 = member1.getMoney();
                    returnRaider = raiderAttack(input1, input2, input3, input4, input5, input6);
                    if (returnRaider == 1)
                    {
                        member1.settotalOxen(-1);
                        member1.settotalFood(-10);
                        member1.settotalWagonParts(-1);
                        if (member1.gettotalOxen() <= 0)
                        {
                            member1.settotalFood1(0);
                            cout << "All of your oxen have died, the game is over." << endl;
                            choice = "4";
                            cout << "Leader: " << playerName << endl;
                            cout << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                            cout << "Food Remaining: " << member1.gettotalFood() << endl;
                            cout << "Cash Remaining: " << member1.getMoney() << endl;
                            
                            ofstream file;
                            file.open("results.txt");
                            if (file.is_open())
                            {
                                file << "Leader: " << playerName << endl;
                                file << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                                file << "Food Remaining: " << member1.gettotalFood() << endl;
                                file << "Cash Remaining: " << member1.getMoney() << endl;
                            }
                            file.close();
                        }
                        else if (member1.gettotalFood() <= 0)
                        {
                            member1.settotalFood1(0);
                            cout << "You have run out of food, the game must be over." << endl;
                            choice = "4";
                            cout << "Leader: " << playerName << endl;
                            cout << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                            cout << "Food Remaining: " << member1.gettotalFood() << endl;
                            cout << "Cash Remaining: " << member1.getMoney() << endl;
                            
                            ofstream file;
                            file.open("results.txt");
                            if (file.is_open())
                            {
                                file << "Leader: " << playerName << endl;
                                file << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                                file << "Food Remaining: " << member1.gettotalFood() << endl;
                                file << "Cash Remaining: " << member1.getMoney() << endl;
                            }
                            file.close();
                        }
                        else if (member1.gettotalWagonParts() <= 0)
                        {
                            member1.settotalWagonParts1(0);
                            cout << "You have run out of wagon parts and cannot fix your wagon, the game is over." << endl;
                            choice = "4";
                            cout << "Leader: " << playerName << endl;
                            cout << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                            cout << "Food Remaining: " << member1.gettotalFood() << endl;
                            cout << "Cash Remaining: " << member1.getMoney() << endl;
                            
                            ofstream file;
                            file.open("results.txt");
                            if (file.is_open())
                            {
                                file << "Leader: " << playerName << endl;
                                file << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                                file << "Food Remaining: " << member1.gettotalFood() << endl;
                                file << "Cash Remaining: " << member1.getMoney() << endl;
                            }
                            file.close();
                        }
                        break;    
                    }
                    else if (returnRaider == 2)
                    {
                        member1.settotalFood(50);
                        member1.settotalBullets(50);
                    }
                    else if (returnRaider == 3)
                    {
                        cash = member1.getMoney();
                        member1.setMoney(-(cash*.25));
                        member1.settotalBullets(-50);
                        if (member1.gettotalBullets() <= 0)
                        {
                            member1.settotalBullets1(0);
                        }
                    }
                    else if (returnRaider == 4)
                    {
                        cash = member1.getMoney();
                        member1.setMoney(-(cash*.25));
                    }
                    
                    cout << endl;
                    break;

                case 3:
                    cout << "In order to hunt and encounter animals you must correctly solve puzzles. Please enter the numbers as prompted." << endl;
                    input1 = member1.gettotalFood();
                    input2 = member1.gettotalBullets();
                    inputRabbit = member3.getRabbit(2, 2, input2); //RUN ALL THE INPUTS
                        if (inputRabbit != -1)
                        {
                            member1.settotalBullets(-10);
                            if (member1.gettotalBullets() <= 0)
                            {
                                member1.settotalBullets1(0);
                            }
                        }
                    inputFox = member3.getFox(5, 5, input2);
                        if (inputFox != -1)
                        {
                            member1.settotalBullets(-8);
                            if (member1.gettotalBullets() <= 0)
                            {
                                member1.settotalBullets1(0);
                            }
                        }
                    inputDeer = member3.getDeer(30, 55, input2);
                        if (inputDeer != -1)
                        {
                            member1.settotalBullets(-5);
                            if (member1.gettotalBullets() <= 0)
                            {
                                member1.settotalBullets1(0);
                            }
                        }
                    inputBear = member3.getBear(100, 350, input2);
                        if (inputBear != -1)
                        {
                            member1.settotalBullets(-10);
                            if (member1.gettotalBullets() <= 0)
                            {
                                member1.settotalBullets1(0);
                            }
                        }
                    inputMoose = member3.getMoose(300, 600, input2);
                        if (inputMoose != -1)
                        {
                            member1.settotalBullets(-12);
                            if (member1.gettotalBullets() <= 0)
                            {
                                member1.settotalBullets1(0);
                            }
                        }
                    returnHunt = member.hunt(numberofPlayers, input1, inputRabbit, inputFox, inputDeer, inputBear, inputMoose); //RUN THE HUNT FUNCTION
                    if (returnHunt == -1 )
                    {
                        cout << "Sorry you hunt was unsuccessful better luck next time!" << endl;
                    }
                    else if (returnHunt == 0)
                    {
                        member1.settotalFood1(0);
                        cout << "You have run out of food, the game must be over." << endl;
                        choice = "4";
                        cout << "Leader: " << playerName << endl;
                            cout << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                            cout << "Food Remaining: " << member1.gettotalFood() << endl;
                            cout << "Cash Remaining: " << member1.getMoney() << endl;
                            
                            ofstream file;
                            file.open("results.txt");
                            if (file.is_open())
                            {
                                file << "Leader: " << playerName << endl;
                                file << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                                file << "Food Remaining: " << member1.gettotalFood() << endl;
                                file << "Cash Remaining: " << member1.getMoney() << endl;
                            }
                            file.close();
                        break;
                    }
                    else if (returnHunt < 0)
                    {
                        member1.settotalFood(returnHunt); //SET FOOD TO THE RETURN
                    }
                    else if (returnHunt > 0)
                    {
                        member1.settotalFood(-returnHunt); //SET FOOD TO THE NEGATIVE RETURN
                    }
              
              //SAME AS CASE 1
                    input1 = member1.gettotalFood();
                    input2 = member1.gettotalWagonParts();
                    input3 = member1.gettotalOxen();
                    input4 = member1.gettotalMedicalKits();
                    breaker = misfortuneOccur(numberofPlayers, playerName, player1, player2, player3, player4, input1, input2, input3, input4);
                    if (breaker == 1)
                    {
                        member1.settotalOxen(-1);
                    }
                    else if (breaker == 2)
                    {
                        member1.settotalOxen1(0);
                        cout << "All of your oxen have died, the game is over." << endl;
                        choice = "4";
                        cout << "Leader: " << playerName << endl;
                            cout << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                            cout << "Food Remaining: " << member1.gettotalFood() << endl;
                            cout << "Cash Remaining: " << member1.getMoney() << endl;
                            
                            ofstream file;
                            file.open("results.txt");
                            if (file.is_open())
                            {
                                file << "Leader: " << playerName << endl;
                                file << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                                file << "Food Remaining: " << member1.gettotalFood() << endl;
                                file << "Cash Remaining: " << member1.getMoney() << endl;
                            }
                            file.close();
                            
                        break;
                    }
                    else if (breaker == 3)
                    {
                        member1.settotalWagonParts(-1);
                    }
                    else if (breaker == 4)
                    {
                        member1.settotalWagonParts1(0);
                        cout << "You have run out of wagon parts and cannot fix your wagon, the game is over." << endl;
                        choice = "4";
                        cout << "Leader: " << playerName << endl;
                            cout << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                            cout << "Food Remaining: " << member1.gettotalFood() << endl;
                            cout << "Cash Remaining: " << member1.getMoney() << endl;
                            
                            ofstream file;
                            file.open("results.txt");
                            if (file.is_open())
                            {
                                file << "Leader: " << playerName << endl;
                                file << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                                file << "Food Remaining: " << member1.gettotalFood() << endl;
                                file << "Cash Remaining: " << member1.getMoney() << endl;
                            }
                            file.close();
                            
                        break;
                    }
                    else if (breaker == 5)
                    {
                        cout << "You have died, the game must be over." << endl;
                        choice = "4";
                        cout << "Leader: " << playerName << endl;
                            cout << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                            cout << "Food Remaining: " << member1.gettotalFood() << endl;
                            cout << "Cash Remaining: " << member1.getMoney() << endl;
                            
                            ofstream file;
                            file.open("results.txt");
                            if (file.is_open())
                            {
                                file << "Leader: " << playerName << endl;
                                file << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                                file << "Food Remaining: " << member1.gettotalFood() << endl;
                                file << "Cash Remaining: " << member1.getMoney() << endl;
                            }
                            file.close();
                            
                        break;
                    }
                    else if (breaker == 6)
                    {
                        member1.settotalMedicalKits(-1);
                    }
                    else if (breaker == 8)
                    {
                        int numberQ;
                        int numberP;
                        string person;
                        string talk;
                        numberP = randomNumbers3(1, 5);
                        numberQ = randomNumbers3(0, 100);
                        
                        
                        if (numberP == 1)
                        {
                            person = playerName;
                        }
                        else if (numberP == 2)
                        {
                            person = player1;
                        }
                        else if (numberP == 3)
                        {
                            person = player2;
                        }
                        else if (numberP == 4)
                        {
                            person = player3;
                        }
                        else if (numberP == 5)
                        {
                            person = player4;
                        }
                        
                        
                        cout << person << " is sick and you do not have any medical aid kits. You would like to rest (1) or press on (2)? If you rest, you must rest for 3 days and " << person << " still has a %30 chance of dying. If you press on " << person << " has a %70 chance of dying." << endl;
                        getline(cin, talk);
                        while(talk != "1" && talk != "2")
                        {
                            cout << "Invalid input. Please chose to rest (1) or press on (2)." << endl;
                            getline(cin, talk);
                        }
                        if (talk == "1")
                        {

                            cout << "You have chosen to rest for 3 days. Food will be consumed accordingly and your health will improve as well." << endl;

                            int numberDays = 3;
                            int food = numberofPlayers*3*numberDays;
                            bool check = true;
                            int foodResult;
   
                            member.setcurrentDay(numberDays);
                            member.setcurrentMonth(member.getcurrentDay());

                            if (food >= input1)
                            {
                                member1.settotalFood(-food);
                            }
                            else if (food < input1)
                            {
                                member1.settotalFood1(0);
                                cout << "You have run out of food, the game must be over." << endl;
                                choice = "4";
                                cout << "Leader: " << playerName << endl;
                                cout << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                                cout << "Food Remaining: " << member1.gettotalFood() << endl;
                                cout << "Cash Remaining: " << member1.getMoney() << endl;
                            
                                ofstream file;
                                file.open("results.txt");
                                if (file.is_open())
                                {
                                    file << "Leader: " << playerName << endl;
                                    file << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                                    file << "Food Remaining: " << member1.gettotalFood() << endl;
                                    file << "Cash Remaining: " << member1.getMoney() << endl;
                                }
                                file.close();
                            
                                break;
                            }

                            if (numberQ <=30)
                            {
                        
                                cout << "Oh no! You chose to rest but " << person << " still died of dysentery!" << endl;
                                
                                if (numberP == 1)
                                {
                                    numberofPlayers--;
                                    cout << "You have died, the game must be over." << endl;
                                    choice = "4";
                                    cout << "Leader: " << playerName << endl;
                                    cout << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                                    cout << "Food Remaining: " << member1.gettotalFood() << endl;
                                    cout << "Cash Remaining: " << member1.getMoney() << endl;
                                    
                                    ofstream file;
                                    file.open("results.txt");
                                    if (file.is_open())
                                    {
                                        file << "Leader: " << playerName << endl;
                                        file << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                                        file << "Food Remaining: " << member1.gettotalFood() << endl;
                                        file << "Cash Remaining: " << member1.getMoney() << endl;
                                    }
                                    file.close();
                            
                                    break;
                              
                                }
                                else if (numberP == 2)
                                {
                                    player1 = "";
                                    numberofPlayers--;
                                }
                                else if (numberP == 3)
                                {
                                    player2 = "";
                                    numberofPlayers--;
                                }
                                else if (numberP == 4)
                                {
                                    player3 = "";
                                    numberofPlayers--;
                                }
                                else if (numberP == 5)
                                {
                                    player4 = "";
                                    numberofPlayers--;
                                }
                            }
                            else 
                            {
                                cout << person << " did not die!" << endl;
                            }
                        }
                        if (talk == "2")
                        {
                            if (numberQ <= 70)
                            {
                                cout << "Oh no! You chose to press on and " << person << " died of dysentery!" << endl;
                                if (numberP == 1)
                                {
                                    numberofPlayers--;
                                    cout << "You have died, the game must be over." << endl;
                                    choice = "4";
                                    cout << "Leader: " << playerName << endl;
                                    cout << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                                    cout << "Food Remaining: " << member1.gettotalFood() << endl;
                                    cout << "Cash Remaining: " << member1.getMoney() << endl;
                                    
                                    ofstream file;
                                    file.open("results.txt");
                                    if (file.is_open())
                                    {
                                        file << "Leader: " << playerName << endl;
                                        file << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                                        file << "Food Remaining: " << member1.gettotalFood() << endl;
                                        file << "Cash Remaining: " << member1.getMoney() << endl;
                                    }
                                    file.close();
                            
                                    break;
                              
                                }
                                else if (numberP == 2)
                                {
                                    player1 = "";
                                    numberofPlayers--;
                                }
                                else if (numberP == 3)
                                {
                                    player2 = "";
                                    numberofPlayers--;
                                }
                                else if (numberP == 4)
                                {
                                    player3 = "";
                                    numberofPlayers--;
                                }
                                else if (numberP == 5)
                                {
                                    player4 = "";
                                    numberofPlayers--;
                                }
                            }
                        }
                    }
                    //SAME AS CASE 1
                    input2 = member1.gettotalWagonParts();
                    input3 = member1.gettotalOxen();
                    input4 = member1.gettotalFood();
                    input5 = member1.gettotalBullets();
                    input6 = member1.getMoney();
                    returnRaider = raiderAttack(input1, input2, input3, input4, input5, input6);
                    if (returnRaider == 1)
                    {
                        member1.settotalOxen(-1);
                        member1.settotalFood(-10);
                        member1.settotalWagonParts(-1);
                        if (member1.gettotalOxen() <= 0)
                        {
                            member1.settotalOxen1(0);
                            cout << "All of your oxen have died, the game is over." << endl;
                            choice = "4";
                            cout << "Leader: " << playerName << endl;
                            cout << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                            cout << "Food Remaining: " << member1.gettotalFood() << endl;
                            cout << "Cash Remaining: " << member1.getMoney() << endl;
                            
                            ofstream file;
                            file.open("results.txt");
                            if (file.is_open())
                            {
                                file << "Leader: " << playerName << endl;
                                file << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                                file << "Food Remaining: " << member1.gettotalFood() << endl;
                                file << "Cash Remaining: " << member1.getMoney() << endl;
                            }
                            file.close();
                        }
                        else if (member1.gettotalFood() <= 0)
                        {
                            member1.settotalFood1(0);
                            cout << "You have run out of food, the game must be over." << endl;
                            choice = "4";
                            cout << "Leader: " << playerName << endl;
                            cout << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                            cout << "Food Remaining: " << member1.gettotalFood() << endl;
                            cout << "Cash Remaining: " << member1.getMoney() << endl;
                            
                            ofstream file;
                            file.open("results.txt");
                            if (file.is_open())
                            {
                                file << "Leader: " << playerName << endl;
                                file << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                                file << "Food Remaining: " << member1.gettotalFood() << endl;
                                file << "Cash Remaining: " << member1.getMoney() << endl;
                            }
                            file.close();
                        }
                        else if (member1.gettotalWagonParts() <= 0)
                        {
                            member1.settotalWagonParts1(0);
                            cout << "You have run out of wagon parts and cannot fix your wagon, the game is over." << endl;
                            choice = "4";
                            cout << "Leader: " << playerName << endl;
                            cout << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                            cout << "Food Remaining: " << member1.gettotalFood() << endl;
                            cout << "Cash Remaining: " << member1.getMoney() << endl;
                            
                            ofstream file;
                            file.open("results.txt");
                            if (file.is_open())
                            {
                                file << "Leader: " << playerName << endl;
                                file << "Miles Traveled: " << member2.getmilesTraveled() << endl;
                                file << "Food Remaining: " << member1.gettotalFood() << endl;
                                file << "Cash Remaining: " << member1.getMoney() << endl;
                            }
                            file.close();
                        }
                        break;    
                    }
                    else if (returnRaider == 2)
                    {
                        member1.settotalFood(50);
                        member1.settotalBullets(50);
                    }
                    else if (returnRaider == 3)
                    {
                        cash = member1.getMoney();
                        member1.setMoney(-(cash*.25));
                        member1.settotalBullets(-50);
                        if (member1.gettotalBullets() <= 0)
                        {
                            member1.settotalBullets1(0);
                        }
                    }
                    else if (returnRaider == 4)
                    {
                        cash = member1.getMoney();
                        member1.setMoney(-(cash*.25));
                    }
                    
                    cout << endl;
                    break;

                case 4:
                    // quit
                    member.quit(); //CALL THE QUIT AND GAME IS OVER!
                    
                    cout << endl;
                    break;

                default:
                    cout << "invalid input" << endl;
                    cout << endl;
                    
            }
    }
    
            

    return 0;
}

