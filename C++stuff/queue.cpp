#include <iostream>
#include "QUEUE.h"
#include <stdlib.h>
using namespace std;
queue::queue()//everything initialized to zero
{front=0;
rear=capacity-1;
length=0;
accumtime=0;
waittime=0;
customers=0;
}
int queue::nextindex(int i)
{return (i+1)%capacity;
}
void queue::enqueue(int x)
{rear=nextindex(rear);
data[rear]=x;
length++;
}
int queue::dequeue()
{
int it;
it=data[front];
front=nextindex(front);
length--;
customers++;//i increment customers on dequeue so i can differentiate from customers served from teh customers still in line
return it;
}
int queue::sizeofline(){return length;}
bool queue::empty(){return length==0;}
int queue::tellcust(){return customers;}

int queue::makewait(int x)
{
waittime=rand()%(x+1);//creates random waittime
accumtime+=waittime;//adds the wait time to the accumtime for calculate average later
}
int queue::tellwait(){return waittime;}
void queue::minustime(){waittime-=1;}//decrements waittime
float queue::tellavgtime()
{float average;
if (customers>0)//to avoid divide by 0 errors
{average=(accumtime)/(customers);}
else
average=0;
return average;
}
void queue::printstat()
{cout<<customers<<" customers served\n"<<"Average waiting time: ";
cout<<tellavgtime();
cout<<"\nCustomers still in line: "<<length;
cout<<"\n";
}


