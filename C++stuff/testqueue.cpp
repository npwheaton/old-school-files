#include <iostream>
#include <stdlib.h>
#include <stdio.h> 

#include "queue.h"
#include "queue.cpp"
using namespace std;

int main(){
	
queue lines[3000];
int arrive;
int transtime;
int snapshot;
unsigned seed=0;
srand (seed);
int chance;
int numlines;
int snap;
int a;
int b;
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
{lines[i].makewait(transtime);}
while (snapshot>0)
{chance=rand()%101;
if (chance<=arrive)
{	a=0;
	 b=0;
	for (int i=0; i<numlines+1;i++)
		{if (i==numlines)
		{lines[a].enqueue(1);
		cout<<lines[0].sizeofline();
		cout<<"\n";
		cout<<lines[1].sizeofline();
		cout<<"\n";
		cout<<lines[2].sizeofline();
		cout<<"\n";
		cout<<lines[3].sizeofline();
		cout<<"\n";
		cout<<lines[4].sizeofline();
		cout<<"\n";
		cout<<lines[5].sizeofline();
		cout<<"\n";
		cout<<lines[6].sizeofline();
		cout<<"\n";
		cout<<lines[7].sizeofline();
		cout<<"\n";
		cout<<lines[8].sizeofline();
		cout<<"\n";
		cout<<lines[9].sizeofline();
		cout<<"\n";}
		else if (lines[a].sizeofline()>lines[i].sizeofline())
		{a=i;}
		}
		
snapshot--;
}
}

for (int i=0; i<numlines; i++)
{cout<<"line "<<(i+1)<<": ";
lines[i].printstat();}


}

