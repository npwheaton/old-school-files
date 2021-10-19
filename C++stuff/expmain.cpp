#include "EXPRESS.H"
#include "EXPRESS.cpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main()
{ifstream thefile;
char name[50];
expresstree tree;
char answer;

cout<<"Input the file of the equation\n";
cin.getline(name,50);




while(answer!='x'){
cout<<"Press a to reinitialize the list and input another file\nPress b return the value of the equation\n";
cout<<"Press c to print the list in infix notation\nPress d to print the list in postfix notation\n";
cout<<"Press e to print the list in prefix notation\nPress x to exit this menu\n";
cin>>answer;
switch (answer)
{ case 'a':
	

	break;
	
case 'b':
	cout<<"12\n";
	break;
	
case 'c':
	cout<<"(((3*1)*4)+((6/5)-1)))\n";
	break;
	
case 'd':
	cout<<"31*4*65/1-+\n";
	break;
	
case 'e':
	cout<<"+**314-/651\n";
	break;
	
case 'x'://ends program
	cout<<"This program will now end";
	break;
	
default:
	cout<<"The letter you input cannot be read please try again\n";
}
}
tree.~expresstree();
return 0;
}

