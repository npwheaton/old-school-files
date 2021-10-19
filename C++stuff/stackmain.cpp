#include "stack.h"
#include "stack.cpp"
#include <iostream>
#include <string.h>
#include <cstdlib>


using namespace std;

int main()
{stack first;//first stack
stack second;//second stack is the first stack in reverse
int k=0;//used in for loop to increment array
int L=0;//used in while loop to increment array
int answer;//used to tell program how many characters there are
char sets[100];//used to transfer array of getline
char tailfirst[100];//the outputs of the first stack
char frontfirst[100];//outputs of the second stack


cout<<"enter a sentence or word (21 characters max) and this program will tell you if its a palindrome or not\n";
cin.getline(sets,100);//gets input
cout<<"tell this program the amount of characters your palindrome will have including all the spaces\n";
cin>>answer;//gets the size of the palindrome

for(int i=0; i!=answer; i++)//pushes the values of sets[] into the first stack stopped by the size of the palindrome
{first.push(sets[k]);
k++;
}

for(int i=0; i!=answer; i++)//pushes the values of sets[] into the second stack in reverse
{k--;
second.push(sets[k]);
}
tailfirst[L]=first.pop();//assigns the first popped value of the first stack
frontfirst[L]=second.pop();//assigns the first popped value of the second stack

while (tailfirst[L]==frontfirst[L] && first.empty()==false)//compares the pops but stops if they dont equal or the stack is empty
{L++;
tailfirst[L]=first.pop();
frontfirst[L]=second.pop();
}
if (tailfirst[L]==frontfirst[L] && first.empty()==true)//tells if palindrome or not by telling if its empty or not and the last pop values are equal to eachother
{cout<<"This is a palindrome\n";
}
else 
{cout<<"This is not a palindrome\n";}
return 0;
}

