#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
using namespace std;

int sorttest(int n, int x[10][10])
{ int max=n*n;
int flat[max];
int k=0;
int y=0;
for (int i=0; i<n; i++)
{for (int j=0; j<n; j++,k++)
	{flat[k]=x[i][j];}
}
sort(flat, flat + max);
	for (int i=1; i<(max-1); i++)
 		{if (flat[i]==flat[i+1] || flat[i]==flat[i-1])
			 {y++;}
}
return y;
}
void calcsum( int n, int x[10][10])
{int row=0;
int column=0;
int daig=0;
 for (int i = 0; i < n; i++) 
 {  for (int j = 0; j < n; j++) 
		{row+=x[i][j];} 
		
 }
 row/=n;
 for (int i = 0; i < n; i++) 
 {    
	for (int j = 0; j < n; j++) 
	{column+=x[j][i];} 
 }
 column/=n;
for (int i = 0; i < n; i++) 
   {daig+=x[i][i];}   
   
if (row==column && row==daig)
{ cout<<"\nThis is a magic square of "<<n<<" and the sum is "<<daig<<endl;}
else
{cout<<"This is not a magic square"<<endl;} 
}
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
calcsum(guess, test);
cout<<" And the set repeats "<<sorttest(guess,test)<<" time(s).";
printset(guess,test);

return 0;
}
