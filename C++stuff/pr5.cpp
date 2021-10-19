// This progam genreates a random 2 digit nuumber and prompts the user to input a 2 digit number
//and based on the matchings of the numbers the user gets money.
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;



int main()
{// Declaring variables and equations.
	int lottery,uguess,lotteryd1,lotteryd2,guessd1,guessd2;
	srand (time(0));
	lottery=rand()%100+10;
	lotteryd1=lottery/10;
	lotteryd2=lottery%10;
	
	//Prompting the user for input and explaining the rules of the lottery.
	cout<<"Guess a 2-digit number for the lottery,\nand if that guess is the exactly like the lottery number,\nyou'll win $10,000.\n";
	cout<<"If you guess the same numbers as the lottery,\nbut not the exact match you'll win $3,000.\n";
	cout<<"If you guess one number correctly, you get $1,000.\n";
	cin>>uguess;
	
	guessd1=uguess/10;
	guessd2=uguess%10;
	//Using If statements to determine the outcome based on the number

if (lottery>=100)
{
	cout<<"Sorry, the lottery number was " <<lottery<<  " This was an error, please try again.";
}
	else if (uguess>99)
	{
		cout<<"Sorry, the lottery number was " <<lottery<<  " \nBut you input 3 numbers, which is illegal and so you didn't win any money, please try again.";
	}
	else if (uguess==lottery)
	{
		cout<<"Congratulations, the lottery number was " <<lottery<< " and you have won $10,000";
	}
	else if (guessd1==lotteryd2, guessd2==lotteryd1)
	{
		cout<<"Congratulations, the lottery number was " <<lottery<< " and you have won $3,000";
	}
	else if (guessd1==lotteryd1)
	{
		cout<<"Congratulations, the lottery number was " <<lottery<< " and you have won $1,000";
	}
	else if (guessd1==lotteryd2)
	{
		cout<<"Congratulations, the lottery number was " <<lottery<< " and you have won $1,000";
	}
	else if (guessd2==lotteryd1)
	{
		cout<<"Congratulations, the lottery number was " <<lottery<< " and you have won $1,000";
	}	
	else if (guessd2==lotteryd2)
	{
		cout<<"Congratulations, the lottery number was " <<lottery<< " and you have won $1,000";
	}
	else
	{
		cout<<"Sorry, the lottery number was "<<lottery<<". None of the numbers matched and so you didn't win any money, please try again."<<endl;
	}
	
	

}
