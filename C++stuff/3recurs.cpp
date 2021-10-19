#include <iostream> //nathaniel Wheaton csc301 

using namespace std;    //Uses 3 recursive functions to check digits in integers, check palindromes, and multiply x to the power of n

bool doappear(int x, int y) //This function sees if the digit is in the integer
{int q=x%10;           // q is equal to modulus which is then compared to y in the if statements
int r=x/10;     // When r becomes 0, the function is on its last digit it needs to check
if (q==y) // stops and returns the true if the digit is found
{return true;}
else if (r==0 and q>0) //Returns false if r=0 and q>0 so the function stops if it doesnt find the digit after going through all the numbers
{return false;}
else if (q>y or q<y)
{ doappear(x/10,y);} // recurses the function excluding the last number checked

}
double expo(double x, int y, int z)  //This function raises the double x to the integer y. I needed z to simplify the if statement
{                                      // z is called at 1 initially
if (y==0)  //if y==0 the function returns 1 
{return x/x;}
else if (z<y)  //when z is less y the function recurses.
{return x*expo(x,y,z+1);}

}
bool chkstrg(char w[],char x[], int i, int j,int k) //This function checks the palindrome
{                                // i and j are used for counters
if (i>k)                      //k is the size of the palindrome the user input, if i is greater then k that means the program checked through 
{return true;}                  //the way to the last number, returns true
else if (w[i]!=x[j])            //stops the function and returns false if a letter doesnt match
{return false;}
else if (w[i]==x[j])           // if the number matches it recurses and checks the next number
{chkstrg(w, x, i+1,j+1, k);}
}

int main()
{

double x; //user input for 1st function
int nextdigit;
int answer; //used in 2nd function
int integer; //user input for 2nd function
int digit;
char forward[50]; //user input for 3rd function
char reverse[50];
int answer2;  //used in 3rd function
int numword; //used in 3rd function
cout<<"Enter  a double x and integer digit and this program will raise x to the power of the integer\n";  //gets user input for double x and n
cin>>x;
cout<<endl;
cin>>nextdigit;
cout<<expo(x,nextdigit, 1); //displays the result

cout<<"\nEnter an integer and a digit to see if the digit is in that integer\n";  //gets user inputs for integer and digit
cin>>integer;
cout<<"Enter a digit\n";
cin>>digit;

answer=doappear(integer,digit); // I set the value of the digit integr function to a variable so I could use it in if statements

if (answer==1)
{cout<<digit<<" was a digit in "<<integer<<endl;}
else                                                        //These 2 statements tell the user if digit was in the integer
{cout<<"\n"<<digit<<" was not a digit in "<<integer<<endl;}
cout<<"This program will check if a word it is a palindrome. First, input the number of letters the word has\n";
cin>>numword;
cout<<"Enter the word and  make sure to put a space after every letter\n";
for (int i=0; i<numword; i++)
{cin>>forward[i]; }           //takes the string

  

for(int i=0, j=numword-1;  i<numword; i++, j--) //Copies the string to another array in reverse order
{reverse[i]=forward[j];}

answer2=chkstrg(forward,reverse,0,0, numword);       //since the function is bool the variable will be a 0 or 1 for true or false

if (answer2==1)
{cout<<"This is a palindrome"<<endl;}
else                                                        //These 2 statements tell the user if the string is a palindrome
{cout<<"This is not an palindrome"<<endl;}

}
