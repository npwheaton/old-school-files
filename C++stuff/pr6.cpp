// This progam genreates a random number and prompts the user to input the same number wth hints.
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;



int main()
{
	int lottery,uguess;
	srand (time(0));
	lottery=rand()%100+1;

	cout<<"This program will randomly generate a number between 0-100\nTry and guess that number: ";
	cin>>uguess;
	
	do
	{
	if (uguess<lottery)
	{
		cout<<"The random number is higher please try again: ";
		cin>>uguess;
	}
	else if (uguess>lottery)
	{
		cout<<"The random number is lower please try again: ";
	cin>>uguess;
}
	}while (uguess!=lottery);
	
	cout<<"Congratulations, you guessed correctly, the number was " <<lottery;
	return 0;
}
	
