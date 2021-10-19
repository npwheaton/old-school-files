// This progam calculates the amount of stamps the user can buy.
#include <iostream>
using namespace std;

int main()
{
	int money;
	
	cout<<"Enter How much money you want to use in pennies\nFor example, $1.39 = 139 pennies. ";
	cin>>money;
	
	
	//Display result
	cout<<"You will get " <<money/49<< " 1st class stamps and you will have " <<money%49<< " cents of change."; 
	

}
