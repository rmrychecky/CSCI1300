#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// Zelle: Python Programming - An Introduction to Computer Science
//   Simulation of a racquetball game. Illustrates use of random
//       numbers and functions to implement a simulation experiment 
//       in a top-down design approach.

void printIntro();
double getProbA();
double getProbB();
int getNumGames();
bool simOneGame(double, double);
bool gameOver(int a, int b);
void simNGames(double probA, double probB, int numGames);
void printSummary(int tA, int tB);

int main()
{
    printIntro();
    double probA = getProbA();
    double probB = getProbB();
    int numGames = getNumGames();
    srand(time(0));
    simNGames(probA, probB, numGames);
    
 

    return 0;
}
void printIntro()
{
    // Prints an introduction to the program
    cout << "This program simulates a game of racquetball between two\n";
    cout << "players called 'A' and 'B'.  The abilities of each player are\n";
    cout << "indicated by a probability (a number between 0 and 1) that\n";
    cout << "the player wins the point when serving. Player A always\n";
    cout << "has the first serve.\n";
    
}
double getProbA()
{
    cout << "\nWhat is the prob. player A wins a serve? " << endl;
    cout << "The probability should be a number between 0 and 1 ";
    double pA;
    cin >> pA;
    return pA;
}
double getProbB()
{
    cout << "\nWhat is the prob. player B wins a serve? " << endl;
    cout << "The probability should be a number between 0 and 1 ";
    double pB;
    cin >> pB;
    return pB;
}
int getNumGames()
{
    cout << "\nHow many games do you wish to simulate? ";
    int n;
    cin >> n;
    return n;
}
bool simOneGame(double pA, double pB)
{
    // Simulates a single game of racquetball between two players whose
    //  abilities are represented by the probability of winning a serve.
    //  Print score for A and B
    string serving = "A";
    int scoreA = 0;
    int scoreB = 0;
    int r;
    while (!gameOver(scoreA, scoreB))
    {
        if (serving == "A")
        {
            r = rand() % 100 + 1;
            if (r < pA*100)
                scoreA = scoreA + 1;
            else
                serving = "B";
        }
        else
        {
            r = rand() % 100 + 1;
            if (r < pB*100)
                scoreB = scoreB + 1;
            else
                serving = "A";
        }
    }
    // cout << "A: " << scoreA << endl;
    // cout << "B: " << scoreB << endl;
    if (scoreA > scoreB)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool gameOver(int a, int b)
{
    // a and b are scores for players in a racquetball game
    // Returns true if game is over, false otherwise
    return (a == 15 || b == 15);
}
void printSummary(int tA, int tB)
{
    cout << "Final score: " << endl;
    cout << "A: " << tA << endl;
    cout << "B: " << tB << endl;
}
void simNGames(double prA, double prB, int nG)
{
    bool aWins;
    int totA = 0;
    int totB = 0;
    for (int i = 0; i < nG; i++)
    {
        aWins = simOneGame(prA, prB);
        if (aWins)
        {
            totA++;
        }
        else
        {
            totB++;
        }
    }
    printSummary(totA, totB);
}

int main(){
   printIntro();
   double probA = getProbA();
   
   srand(time(0));
   int r = rand()%100; //values between 0 and 99
   
   //generate a random integer in a range : between a and b values
   int min = 35;
   int max = 57;
   r = rand()%(max - min) + 35;
   
   
   cout << r<< endl;
   if (r <= probA*100)
   {
      cout << "A wins";
   }
   else
   {
      cout << "B wins";
   }
}