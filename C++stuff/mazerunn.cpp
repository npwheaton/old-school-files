#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
using namespace std;

bool findway(int v, int w, int (&x)[22][76],int y, int z)//i passed the dimensions of the maze, the array, and 2 variables to increment by.
{if (x[v][w-1]==1 and x[v][w-1]> x[v-1][w-1])//base case if the maze reaches the end the function stops.
{return true;}

else if (x[y+1][z]==x[y][z] or x[y+1][z]==1)//IF you can go south
{x[y][z]=0;
	if (findway(v,w,x,y+1,z)==false)//try south
	{	if(findway(v,w,x,y,z-1)==false)//try west
			{if(findway(v,w,x,y-1,z)==false)//try north
				{findway(v,w,x,y,z+1);}//try east
			}
	}
	else
	{findway(v,w,x,y+1,z);}
}
else if (x[y][z+1]==x[y][z] or x[y][z+1]==1)//IF you can go east
{x[y][z]=0;
	if (findway(v,w,x,y,z+1)==false)//try east
	{	if(findway(v,w,x,y+1,z)==false)//try south
			{if(findway(v,w,x,y,z-1)==false)//try west
				{findway(v,w,x,y-1,z);}//try north
			}
	}
	else
	{findway(v,w,x,y,z+1);}
}
else if (x[y][z-1]==x[y][z] or x[y][z-1]==1)//IF you can go west
{x[y][z]=0;
	if (findway(v,w,x,y,z-1)==false)//try west
	{	if(findway(v,w,x,y-1,z)==false)//try north
			{if(findway(v,w,x,y,z+1)==false)//try east
				{findway(v,w,x,y+1,z);}//try south
			}
	}
	else
	{findway(v,w,x,y,z-1);}
}
else if (x[y-1][z]<x[y][z])//IF you can go north, 
{x[y][z]=0;                    // mark your spot first
	if (findway(v,w,x,y-1,z)==false)// recurse at the north position to see if you can go north on from there
	{	if(findway(v,w,x,y,z+1)==false)     //if you cannot go on from north, recurse east instead, if going east gives no more options after try south
			{if(findway(v,w,x,y+1,z)==false) //if going south gives no more options after try west
				{findway(v,w,x,y,z-1);} //recurse west
			}        
	}
	else
	{findway(v,w,x,y-1,z);}
}

else
{return false;}
}

void printset(int v, int w, int x[22][76])
{for (int i = 0; i < v; i++) 
 {  cout<<"\n";
 for (int j = 0; j < w; j++) 
		{cout<<x[i][j]<<" ";} 
		 }
}

int main()
{ifstream file;
char name[50];
int guessx;
int guessy;
int maze[22][76];

cout<<"Input the file of the maze you want to test\n";// reads the maze file
cin.getline(name,50);
cout<<"Input the dimensions of the maze.\n";//reads the inputs of the dimension
cout<<"The X dimension is ";
cin>>guessx;
cout<<"\nThe Y dimension is ";
cin>>guessy;
file.open(name); //opens the file

if (!file.is_open())
{exit(EXIT_FAILURE);}

 for (int i = 0; i<guessx; i++) //sets the input of the file into an array
 {  
 for (int j = 0; j <guessy; j++) 
		{file>>maze[i][j];} 
	}

findway(guessx, guessy,maze,1,1);
cout<<"I have solved the maze! Follow the 0s to the 1.\n";	
printset(guessx, guessy, maze);
return 0;
}
