#include <iostream>
#include "array.h"
using namespace std;

array::array(int x){ 
size=x;
pt1=new int[size];
pt2=new int[size];
arraycount=0;
for (int i=0; i<size; i++)//sets contents to zero of both arrays
	{pt1[i]=0;
	pt2[i]=0;}
    
}

void array::fillelements(int input[])
{ for (int i=0; i<size; i++)
	{pt1[i]=input[i];}
}
void array::fillelements2(int input[])
{ for (int i=0; i<size; i++)
	{pt2[i]=input[i];}
}
void array::copyarray()
{  arraycount++;
for (int i = 0; i < size; i++)
     {pt2[i]= pt1[i];}  
}
bool array::compareit()
{ for (int i = 0; i < size; i++)
      if (pt1[i] != pt2[i])
      {return false;}
   return true; 
}
array::~array()
{ arraycount=0;                             
   delete [] pt1;
    delete [] pt2;                       
  pt1 = NULL;
  pt2 = NULL;
}
void array::printelements()
{  for (int i = 0; i < size; i++)
     {cout<<pt1[i];
	 cout<<" ";}  
}
void array::printelements2()
{  for (int i = 0; i < size; i++)
     {cout<<pt2[i];
	 cout<<" ";}  
}
int array::getsize(){return size;}


