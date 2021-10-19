#include <iostream>
#include <cstdlib>
#include "rlist.h"
#include "rlist.cpp"
using namespace std;

int main()
{rlist r;
char answer='a';//initial user input answer
int a1;//used in case a
int b1;//used in case b
int f1;//used in case f
bool d1;//used in case d
while (answer!='x')//while loop takes user to the menu over ad over again until they exit with x
{cout<<"Press a to insert data member\nPress b to remove a data member\nPress c to reinitialize the list to 0\n";
cout<<"Press d to check if the list is empty\nPress e to check the length of the list\nPress f to check if a data member is in a list\n";
cout<<"Press g to print out the list\nPress x to exit this menu\n";
cin>>answer;
switch (answer)
{ case 'a'://inserts data member
	cout<<"insert the data member\n";
	cin>>a1;
	r.insert(a1);
	break;
	
case 'b'://removes data member
	cout<<"Enter the data member you want to remove\n";
	cin>>b1;
	r.remove(b1);
	break;
	
case 'c':// reinitializes list
	r.telltoempty();
	break;
	
case 'd'://checks if the list is empty
	d1=r.tellempty();
	if (d1==true)
	{cout<<"The list is empty\n";}
	else
	cout<<"The list is not empty\n";
	break;
	
case 'e':// checks the length
	cout<<"The length of the list is "<<r.sendlength();
	cout<<"\n";
	break;

case 'f':// checks if the data member is in the list
	cout<<"Enter the data member you want to check\n";
	cin>>f1;
	r.tellpresent(f1);
	break;	
case 'g':// prints function
	r.toprint();
	cout<<"\n";
	break;

case 'x'://ends program
	cout<<"This program will now end";
	break;
	
default:
	cout<<"The letter you input cannot be read please try again\n";
}
}

r.~rlist();// cleans memory
return 0;
		
}
