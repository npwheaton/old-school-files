#include "bst.h"
#include "bst.cpp"
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{ bst tree;
 char answer='a';//initial user input answer
int a1;//used in case a
int b1;//used in case b
int e1;//used in case e


while (answer!='x')//while loop takes user to the menu over ad over again until they exit with x
{cout<<"Press a to insert a term into the list\nPress b to remove a term\nPress c to reinitialize the list\n";
cout<<"Press d check the length of the list\nPress e to search for a term in the list\nPress f to print the list\nPress x to exit this menu\n";
cin>>answer;
switch (answer)
{ case 'a'://inserts term
	cout<<"insert data you want to insert\n";
	cin>>a1;
tree.insert(a1);
	break;
	
case 'b'://removes term
	cout<<"Enter the number you want remove\n";
	cin>>b1;
	tree.remove(b1);
	break;
	
case 'c':// reinitializes list
	tree.initialize();
	break;
	
case 'd'://tells the length
	cout<<"The length of the tree is "<<tree.length()<<endl;
	break;
	
case 'e'://searches the term
	cout<<"Enter the term you want to search for\n";
	cin>>e1;
	if (tree.presence(e1)==true)
		{cout<<"The data item is present in the list\n";}
	else
	cout<<"The data item is not present in the list\n";
	break;
	
case 'f':// prints function
	cout<<"Tree data members: ";
	tree.print();
	cout<<"\n";
	break;

case 'x'://ends program
	cout<<"This program will now end";
	break;
	
default:
	cout<<"The letter you input cannot be read please try again\n";
}
}

tree.~bst();// cleans memory
	
}
