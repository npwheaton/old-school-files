// This program generates a random number 1-3 and the user picks one as well. The numbers are given assignments to the objects to determine the winner
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

int main ()
{
	int upick, cpick;
	char answer;
	srand (time(0));
	cpick=rand()%3+1;
	
	choice: cout<<"The computer will play rock, paper, scissors against you.\n In order to play, pick the number corresponding to the object you want\n";
	cout<<"rock=1\npaper=2\nscissors=3\n";
	cin>>upick;
	
	if (upick==1)
	{cout<<"You picked rock\n";
	}
	else if (upick==2)
	{cout<<"You picked paper\n";
	}
	else if (upick==3)
	{cout<<"You picked scissors\n";	
	}
	
	system("pause");
	
	if (cpick==1)
	{cout<<"And the computer picked rock.";
	}
	else if (cpick==2)
	{cout<<"And the computer picked paper.";
	}
	else if (cpick==3)
	{cout<<"And the computer picked scissors.";	
	}
	
	if (upick==1 and cpick==3)
	{cout<<" You won, you beat the computer good job!";
	}
	else if (upick==3 and cpick==1)
	{cout<<" You lost to the computer, nice try though";
	}
	else if (upick>3 or upick<1)
	{cout<<" but you didn't input a valid number, so you lost by default sorry";
	}
	else if (upick<cpick)
	{cout<<" You lost to the computer, nice try though";
	}
	else if (upick>cpick)
	{cout<<" You won, you beat the computer good job";
	}
	else if (upick==cpick)
	{cout<<" You and the computer tied";
	}
	
	choice2: cout<<"\n............................GAMEOVER.............................\n";
	system("pause");
	cout<<"Do you want to play again? Enter y or n:\n";
	cin>>answer;
	
	
	switch (answer)
	{
		case 'y':
		system("CLS");
		goto choice;
			
		case 'n':
		return 0;
		break;
		
		default:
		system("CLS");
		cout<<"The program couldn't recognize your decision, please input only 'y' or 'n' and try again"<<flush<<endl;
		goto choice2;
	}
	
}
	


