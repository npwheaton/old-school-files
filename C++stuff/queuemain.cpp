#include <iostream>
#include <stdlib.h>
#include <stdio.h> 
#include "queue.h"
#include "queue.cpp"
using namespace std;

int main()
{queue lines[3000];//queue constructors in array
int arrive;//theuser input for probabiloty a customer will arrive
int transtime;//the longest a transaction can take
int snapshot;//user input How many minutes until the statististics are printed
unsigned seed=0;//seed for rand
srand (seed);
int chance;//used to determine if customers arrive
int numlines;//max nuber of lines
int snap;//used in cout statement
int a;//used in for loop to find lowest line
cout<<"Input seed for randomness\n";
cin>>seed;
cout<<"Input the number of lines in the store\n";
cin>>numlines;
cout<<"input the probability that a customer will arrive between 1-100\n";
cin>>arrive;
cout<<"Input the longest time in minutes a transaction can take\n";
cin>>transtime;
cout<<"Input in how many minutes should the snapshot of store progress should be taken\n";
cin>>snapshot;
snap=snapshot;
for (int i=0; i<numlines; i++)
{lines[i].makewait(transtime);}//sets an initial waittime for everyline
while (snapshot>0)
{chance=rand()%101;
a=0;

if (chance<=arrive)//if  the random chance number is<=arrival then a customer arrives
	{
	for (int i=0; i<(numlines+1);i++)//finds lowest lines using for loop that repeats until it checks all lines
		{
		if (i==numlines)
		{lines[a].enqueue(1);}
		else if (lines[a].sizeofline()>lines[i].sizeofline())
		{a=i;}
		}
//loops to deque and make new waittimes
	for (int i=0; i<numlines; i++)//1 customer can come out of each line if the wait time is up.
		{if (lines[i].tellwait()==0&&lines[i].sizeofline()>0)
			{lines[i].dequeue();
			lines[i].makewait(transtime);
			}
		}
	}
//minustime loops
for (int i=0; i<numlines; i++)//for loop subtracts 1 from all waitimes
{if (lines[i].tellwait()!=0)
	{lines[i].minustime();}
}
snapshot--;//1 minute in the store has passed
}
//print statistics with loop
cout<<"After "<<snap<<" minutes, this progress of this store with "<<numlines<<" lines is\n";
for (int i=0; i<numlines; i++)//for loops goes trough print to return statistics
{cout<<"line "<<(i+1)<<": ";
lines[i].printstat();}

return 0;
}

