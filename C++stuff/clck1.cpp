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
{if(0<=seconds && seconds<59)
	{sec=seconds;
	}
else if(seconds>59)
{min=seconds/60;
sec=seconds%60;
}
else
{sec=0;}
if(0<=minutes && minutes<59)
	{min=minutes;
	}
else if(minutes>59)
{hr=minutes/60;
min=minutes%60;
}
else
{min=0;
}
if(0<=hours && hours<=23)
	{hr=hours;
	}
else if(hours>23)
{hr=hours%24;
}
else
{hr=0;
}



}

void clocktype::gettime(int& hours, int& minutes, int& seconds)
{hours=hr;
minutes=min;	
seconds=sec;}

void clocktype::printtime()
{cout<<hr<<":"<<min<<":"<<sec<<endl;}

int main()
{clocktype myclock;

int hours;
int minutes;
int seconds;


cout<<"Set the clock by the hour in military time"<<endl;
cin>>hours;
cout<<"Set the clock by the minutes"<<endl;
cin>>minutes;
cout<<"Set the clock by the seconds"<<endl;
cin>>seconds;

myclock.settime(hours, minutes, seconds);
myclock.incrementseconds();
cout<<"After a second, the time is\n";
myclock.printtime();


}

