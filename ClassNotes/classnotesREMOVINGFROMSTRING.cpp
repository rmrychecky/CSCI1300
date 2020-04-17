#include<iostream>
#include<string>
using namespace std; 

// Removes all spaces or dashes from a string with for loop
int main() 
{ 
	string credit_card_number = "4123-5678-9012-3450"; 
	int i = 0; 
	while (i < credit_card_number.length()) 
	{ 	
		string ch = credit_card_number.substr(i, 1); 
		if (ch == " " || ch == "-") //must remove char
 		{ 
			string before = credit_card_number.substr(0, i); 
			string after = credit_card_number.substr(i + 1); 				
			credit_card_number = before + after; 
		} 
		else // no need to remove it, go to next char
		{ 
			i++; 
		} 
	} 
	cout << credit_card_number << endl; 
	return 0; 
}



//Option 2
// Removes all spaces or dashes from a string with a while loop 
int main() 
{ 
	string credit_card_number = "4123-5678-9012-3450";
	string newString = "";
	 
	for (int i = 0; i < credit_card_number.length(); i++) 
	{ 	
		if (credit_card_number[i] != ' ' && credit_card_number[i] != '-') //don't add them to newString
 		{ 
			newString += credit_card_number[i];	
 		}
	} 
	cout << newString << endl; 
	return 0; 
}
