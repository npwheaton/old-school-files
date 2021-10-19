// This progam calculates the user's amount of pennies.
#include <iostream>
using namespace std;

int main()
{
int	pennies, Dollars, quarters, dimes, nickels;
	
	// Get the number of pennies.
	cout<< "How many pennies do you have?";
	cin>> pennies;

	// Calculate Dollars.
	Dollars=pennies/100;

	// Calculate leftover pennies.
pennies=pennies%100;

	// Calculate quarters.
quarters=pennies/25;

	// Calculate leftover pennies.
	pennies=pennies%25;

	// Calculate dimes.
	dimes=pennies/10;
	
	// Calculate leftover pennies
	pennies%=10;

	// Calculate nickels.
	nickels=pennies/5;

	// Calculate leftover pennies.
	pennies=pennies%5;
	
	// Display amount of Dollars, quarters, dimes, nickels, and pennies.
	cout<< "You have earned $" <<Dollars<< " Dollar(s)," <<quarters<< " quarter(s)," <<dimes<< " dime(s)," <<nickels<< " nickel(s), and " <<pennies<< " pennies";

}
