#include <iostream>
#include "array.h"
#include "array.cpp"
using namespace std;

int main()
{array first;//array object
char answer2;//used in yes or no
int answer3;// used to ask if the user wants to fill 2nd array or copy it
int copyexist=0;//state used to check if the 2nd array exists
int tellele[10];//holds inputs to be passed to class for  1st array elements
int tellele2[10];//holds inputs to be passed to class for  2nd array elements

cout<<"Tell me the inputs of the array\n";
for (int i=0; i<first.getsize(); i++)
	{cin>>tellele[i];}//gets first array inputs
first.fillelements(tellele);//fills first array elements

cout<<"Would you Like to create another array of the same size? Y or N\n";//uses 2nd array
cin>>answer2;
if (answer2=='y' or answer2=='Y')
	{cout<<"Press 1 to fill the elements of the array, Press 2 to copy the elements of the first array to the 2nd array.\n";
	cin>>answer3;
	if (answer3==1)
		{cout<<"Tell me the inputs of the array\n";
		for (int i=0; i<first.getsize(); i++)
			{cin>>tellele2[i];}//gets 2nd array inputs
		first.fillelements2(tellele2);//fill 2nd array elements
		copyexist++;//shows that 2nd array was used
		}
	else if (answer3==2)
		{first.copyarray();//copies 2nd array to first
		copyexist++;}//shows that 2nd array was used
	else 
		cout<<"The input cannot be read\n";
	}
if (copyexist>0)
{cout<<"Would you like to compare the first array to the 2nd array Y or N\n";
cin>>answer2;
	if (answer2=='y' or answer2=='Y')
		{int state=first.compareit();//starts the compare function and gives the return to a variable
		if (state>0)
			{cout<<"the arrays are equal\n";}
		else
			cout<<"The arrays are not equal\n";
		}

}
cout<<"Would you like to print the elements of the first array Y or N\n";
cin>>answer2;
	if (answer2=='y' or answer2=='Y')
		{first.printelements();}//prints 1st array
if (copyexist>0)
{cout<<"\nWould you like to print the elements of the second array Y or N\n";
cin>>answer2;
	if (answer2=='y' or answer2=='Y')
		{first.printelements2();}//prints 2nd array
}

first.~array();//destroys array and frees up memory


}


