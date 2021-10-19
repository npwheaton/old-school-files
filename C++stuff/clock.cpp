#include <iostream>
using namespace std;

class clocktype
{private:
	int hr;
	int min;
	int sec;
	
public:
	void settime(int, int, int);
	void gettime(int&, int&, int&);
	void printtime();
	int incrementseconds();
	int incrementminutes();
	int incrementhours();
	bool equaltime(clocktype& otherclock);
	
};
int clocktype::incrementseconds()
{sec++;
if (sec>59)
	{sec=0;
	incrementminutes();
	}
}
int clocktype::incrementminutes()
{min++;
if (min>59)
	{min=0;
	incrementhours();
	}
}
int clocktype::incrementhours()
{hr++;
if (hr>23)
	{hr=0;
	}
}
void clocktype::settime(int hours, int minutes, int seconds)
{if(0<=hours && hours<23)
	{hr=hours;
	}
else
{hr=0;
}
if(0<=minutes && minutes<59)
	{min=minutes;
	}
else
{min=0;
}
if(0<=seconds && seconds<59)
	{sec=seconds;
	}
else
{sec=0;
}
}
void clocktype::gettime(int& hours, int& minutes, int& seconds)
{hours=hr;
minutes=min;	
seconds=sec;
}
void clocktype::printtime()
{cout<<hr<<":"<<min<<":"<<sec<<endl;
}
bool clocktype::equaltime(clocktype& otherclock)
{return(hr==otherclock.hr
&&min==otherclock.min
&&sec==otherclock.sec);
}

int main()
{clocktype myclock;
clocktype yourclock;

int hours;
int minutes;
int seconds;
char answer;
int answer2;

myclock.settime(5, 4, 30);

cout<<"my clock is: ";

myclock.printtime(); 
cout<<endl;

cout<<"your clock is: ";
yourclock.printtime(); 

yourclock.settime(5, 45, 16);

cout<<"After setting, yourclock is: ";
yourclock.printtime(); 
cout<<endl;	

if (myclock.equaltime(yourclock))
	{cout<<"Both times are equal."<<endl;
	}
else
{cout<<"The two tmes are not equal."<<endl;
}
cout<<"Enter the hours, minutes and seconds: ";
cin>>hours>>minutes>>seconds;
cout<<endl;
myclock.settime(hours, minutes, seconds);

option1: cout<<"New myclock: ";
myclock.printtime();
cout<<endl;

cout<<"Press 'h' to increase the clock by an hour\n";
cout<<"'m' to increase the clock by a minute\n";
cout<<"'s to increase the clock by a second \nOr any other button to end the program: ";
cin>>answer;

switch (answer)
{case'h':
myclock.incrementhours();
cout<<"After incrementing myclock by 1 hour, myclock is: ";
myclock.printtime();
cout<<endl;
option2: cout<<"If u want to increment by another hour, minute, second press 1, if not press 2.";
cin>>answer2;
if (answer2==1)
{goto option1;
}
else if (answer2==2)
{goto final;
}
else
{cout<<"The input cannot be read please try again";
goto option2;
}
case 'm':
myclock.incrementminutes();
cout<<"After incrementing myclock by 1 minute, myclock is: ";
myclock.printtime();
cout<<endl;
cout<<"If u want to increment by another hour, minute, second press 1, if not press 2.";
cin>>answer2;
if (answer2==1)
{goto option1;
}
else if (answer==2)
{goto final;
}
else
{cout<<"The input cannot be read please try again";
goto option2;
}
case 's':
myclock.incrementseconds();
cout<<"After incrementing myclock by a second, myclock is: ";
myclock.printtime();
cout<<endl;
cout<<"If u want to increment by another hour, minute, second press 1, if not press 2.";
cin>>answer2;
if (answer2==1)
{goto option1;
}
else if (answer==2)
{goto final;
}
else
{cout<<"The input cannot be read please try again";
goto option2;
}
default:
	goto final;
}

final: myclock.gettime(hours, minutes, seconds);
cout<<"My clock is Hours="<<hours<<", minutes="<<minutes<<", seconds="<<seconds<<endl;
return 0;
}


