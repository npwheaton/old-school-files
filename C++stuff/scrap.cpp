#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
using namespace std;




void printset(int n, int x[10][10])
{for (int i = 0; i < n; i++) 
 {  cout<<"\n";
 for (int j = 0; j < n; j++) 
		{cout<<x[i][j]<<" ";} 
		 }
}
int main()
{
ifstream thefile;
char name[50];
int guess;
int i;
int j;
int test[10][10];

cout<<"Input the file of the magic square you want to test\n";
cin.getline(name,50);
cout<<"Input your guess of what order this magic square is\n";
cin>>guess;
thefile.open(name);

if (!thefile.is_open())
{exit(EXIT_FAILURE);}
 for (int i = 0; i<guess; i++) 
 {  
 for (int j = 0; j < guess; j++) 
		{thefile>>test[i][j];} 
	}
printset(guess, test);
cout<<"IS"<<1<<"greater than"<<test[0][0];
}
