// CSCI1300 Fall 2018
// Author: Raegan Rychecky
// Recitation: <104> – Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/rmrychecky/csci1300
// Homework 5 - Problem 1

/*
1. write function to calculate hamming distance
	a. initialize hamming distance, genome length and same to 0
	b. for loop to trace string and add one to string everytime same characters occur
	c. set genome length to what you are comparing with, hamming distance is the length - same.
	d. return the hamming distance as a double
2. write function for similarity score
	a. set similarity score and new similarity score to 0.
	b. genome length is the length of sequence 2.
	c. if the inputs are empty the similarity score is 0
	d. else if they are equal to begin with then calculate score as (genome_length - hammingDistance(sequence1, sequence2)) / genome_length
	e. else use a for loop to trace through string
	f. create new substrings the length of sequence 
	g. if string 1 becomes less than sequence 2 then calculate the newsimilarity score and check if it is larger than old similarity score
	h. then break
	i. else if they are equal calculate new similarity as (genome_length - hammingDistance(string1, sequence2)) / genome_length
	j. check if the newsimilarity score is greater than the previous similarity score.
	k. if it is then similarity score is the newsimilarity score
	l. else similarity score remains the same
	m. return the similarity score 
3. create a function called analyzer to print out statements about the genomes and bacteria
	a. declare maxscore
	b. if any of the input strings are empty print related statement
	c. else if they dont equal each other print the length doesn't match
	d. else if the bacteria length is longer than any of the genomes print the sequence length must be smaller.
	e. else if  they are all equal length
		1. declare and set double score1, socre2, and score3, by calling simScore
		2. if the scores are equal print all three are the best match
		3. if two of the scores are equal and greater than the third print that each one is the best match.
		4. find the maxscore by comparing score1, score2, and score3
		5. check if each invidiual score is the maxscore and not equal to the others
			i. if so print out the genome is the best match
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <string>
using namespace std; 

double hammingDistance(string sequence1, string sequence2) //calculates the hamming distance between two strings with the same length
{ 
	
	double hamming_distance = 0; //initalize three variables used to 0
	int genome_length = 0;
	int same = 0;
	for (int i = 0; i < sequence2.length(); i++) //trace over the sequence and check if any characters match up
	{
		if (sequence1[i] == sequence2[i])
		{
			same++; //if they do add one to same
		}
			
	}
	genome_length = sequence2.length(); //set the genome length to the length of the sequence2 
	hamming_distance = genome_length - same; //calculate hamming distance as the genome length - same

	return hamming_distance; //return the hamming distance as a double
}

double simScore(string sequence1, string sequence2) //take two string inputs to calculate the similarity score 
{
	double similarity_score = 0; //initalize similarity variables to 0
	double newsimilarity_score = 0;
    int genome_length = sequence2.length();

    if (sequence1 == "" && sequence2 == "") //if the sequences are empty the score is 0
	{
		similarity_score = 0;
	}
	else if (sequence1.length() == sequence2.length()) //if the lengths of the original strings are the same calcualte the similarity score right away
	{
		similarity_score = (genome_length - hammingDistance(sequence1, sequence2)) / genome_length; //use the equation given to calculate similarity score
	}
	else //if neither of these situations are true, trace over the longer sequence
	{
		for (int i = 0; i < sequence1.length(); i++) //add one to position on string every time keeping the same string length
		{
		
			string string1 = sequence1.substr(i, sequence2.length()); //create a new substring the length of the sequence2 string
			//cout << string1 << endl;
			if (string1.length() < sequence2.length()) //if the length of the substring becomes less than that of the sequence2, find similarity and break
			{
				string1 = sequence1.substr(i - 1, sequence2.length());
				//cout << string1 << endl;
				newsimilarity_score = (genome_length - hammingDistance(string1, sequence2)) / genome_length; 
				if (newsimilarity_score > similarity_score)
				{
					similarity_score = newsimilarity_score;
				}
				break;
			}
			else if (string1.length() == sequence2.length()) //else if they are equal
			{
				newsimilarity_score = (genome_length - hammingDistance(string1, sequence2)) / genome_length; //find newsimilarity and compare with the old similarity 
				if (newsimilarity_score > similarity_score)
				{
					similarity_score = newsimilarity_score; //set similarity to whichever is greater!
				}
				else 
				{
					similarity_score = similarity_score;
				}
			}

		}
	}
	
	return similarity_score; //return the similarity score
}



void analyzer(string genome1, string genome2, string genome3, string bacteria) //compare three genomes and a bacteria
{
	double maxscore; //create a maxscore variable
	
	if (genome1 == "" || genome2 == "" || genome3 == "" || bacteria == "") //if any input is empty return the following phrase
	{
		cout << "Genome and sequence cannot be empty." << endl;
	}
	else if (genome1.length() != genome2.length() || genome1.length() != genome3.length() || genome2.length() != genome3.length()) //if any lengths don't match return the following phrase
	{
		cout << "Genome length does not match." << endl;
	}
	else if (bacteria.length() > genome1.length() || bacteria.length() > genome2.length() || bacteria.length() > genome3.length()) //if the bacteria length is greater than any of the genome lengths return the following phrase
	{
		cout << "Sequence length must be smaller than genome length." << endl;
	}
	else if (genome1.length() == genome2.length() && genome1.length() == genome3.length()) //if all the genomes are of equal length
	{

		double score1 = simScore(genome1, bacteria); //find the similarity scores for each genome using the simScore function
		double score2 = simScore(genome2, bacteria);
		double score3 = simScore(genome3, bacteria);
		
		
		if (score1 == score2 && score1 == score3) //if the scores are equal print all are the best match
		{
			cout << "Genome 1 is the best match." << endl;
			cout << "Genome 2 is the best match." << endl;
			cout << "Genome 3 is the best match." << endl;
		}
		
			if (score1 == score2 && score1 > score3) //if two of the scores are equal and greater than the third then print those two are the best match
		{
			cout << "Genome 1 is the best match." << endl;
			cout << "Genome 2 is the best match." << endl;
		}
		if (score1 == score3 && score1 > score2)
		{
			cout << "Genome 1 is the best match." << endl;
			cout << "Genome 3 is the best match." << endl;
		}
		if (score2 == score3 && score2 > score1)
		{
			cout << "Genome 2 is the best match." << endl;
			cout << "Genome 3 is the best match." << endl;
		}
		
		if(score1 > score2) //find the max score between all of the resulting scores
		{
    		if(score1 > score3)
    		{
        		maxscore = score1;
    		}
		}
		else if(score2 > score1) 
		{
    		if(score2 > score3)
    		{
        		maxscore = score2;
    		}
		}
		else if(score3 > score2)
		{
   			if(score3 > score1)
    		{
      			maxscore = score3;
    		}
		}
		
		if (score1 == maxscore && score1 != score2 && score1 != score3) //if one of the scores is the max score and not equal to any of the other scores then print out that genome is the best match
		{
			cout << "Genome 1 is the best match." << endl;
		}
		else if (score2 == maxscore && score2 != score1 && score2 != score3)
		{
			cout << "Genome 2 is the best match." << endl;
		}
		if (score3 == maxscore && score3 != score1 && score3 != score2)
		{
			cout << "Genome 3 is the best match." << endl;
		}
	}
}

int main() //test cases for each function
{
//test cases for hammingDistance
cout << hammingDistance("ACCT", "ACCG") << endl; //expected value: 1
cout << hammingDistance("ACCTA", "ACCGG") << endl; //expected value: 2
cout << hammingDistance("", "ACCGG") << endl; //expected value: 0
cout << hammingDistance("ACCTAAAAAAAA", "ACCGG") << endl; //expected value: 0
cout << hammingDistance("ACCTAAAAAAAA", "0") << endl; //expected value: 0
cout << hammingDistance("ACCTAAAAAAAA", "ACCTAAAAAAAT") << endl; //expected value: 1

//test cases for simScore
cout << simScore("ATGC", "ATGA") << endl; //expected value: .75
cout << simScore("AATGTTTCAC", "TACTA") << endl;
cout << simScore("CCDCCD", "CCDCCD") << endl; //expected value: 1
cout << simScore("ATG", "GAT") << endl; //expected value: 0
cout << simScore("ACCDT", "ACCT") << endl; //expected value: 0
cout << simScore("CGT", "DGGTA") << endl; //expected value: 0
cout << simScore("GGGDADSFADSFASDF", "ACC") << endl; //expected value: 0
cout << simScore("", "ACC") << endl; //expected value: 0
cout << simScore("", ""); //expected value: 0

//test cases for analyzer
analyzer("AATGTTTCAC", "GACCGACTAA", "AAGGTGCTCC", "TACTA"); //expected output: Genome 2 is the best match.
analyzer("AACT", "AACT", "AATG", "AACT"); //expected output: Genome 1 is the best match. Genome 2 is the best match.
analyzer("ACATC", "ACTTA", "TACAT", "AACT"); //expected output: Genome 1 is the best match. Genome 2 is the best match. Genome 3 is the best match.
analyzer("", "CATTA", "TAATC", "ACTA"); //expected output: Genome and sequence cannot be empty
analyzer("TAATC", "CATTAA", "TAATC", "ACTA"); //expected output: Genome length does not match
analyzer("TAATC", "CATTA", "TAATC", "ACTATTT"); //expected output: Sequence length must be smaller than genome length.

}
