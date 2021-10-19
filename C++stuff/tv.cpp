//Tv turning on and off.
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

class TV
{public:
int channel;
int volumelevel;
bool on;

TV();
void turnon();
void turnoff();
void setchannel(int newchannel);
void setvolume(int newvolume);
void channelup();
void channeldown();
void volumeup();
void volumedown();
};

TV::TV()
{srand (time(0));
channel=1; 
volumelevel=1, on=false;
}
void TV::turnon()
{on=true;
cout<<"Power: on.";
}
void TV::turnoff()
{on=false;
cout<<"Power: off.";
}
void TV::setchannel(int newchannel)
{newchannel=rand()%120+1;
channel=newchannel;
cout<<"\nChannel: "<<channel<<endl;
}
void TV::setvolume(int newvolume)
{newvolume=rand()%70+1;
volumelevel=newvolume;
cout<<"Volume: "<<volumelevel<<endl;
}
void TV::channelup()
{channel++;
cout<<"\nChannel: "<<channel<<endl;
}
void TV::channeldown()
{channel--;
cout<<"\nChannel: "<<channel<<endl;
}
void TV::volumeup()
{volumelevel++;
cout<<"Volume: "<<volumelevel<<endl;
}
void TV::volumedown()
{volumelevel--;
cout<<"Volume: "<<volumelevel<<endl;
}
int main()
{int answer; 
char answer2;
char answer3;
char answer4;
char answer5;
cout<<"Press any key to turn on the Tvs.\n";
system("pause"); 
//chooses which tv to go to.
cout<<"Press 1 to use Tv1 or 2 to use Tv2: ";
cin>>answer;
//Tv1 options and control
if (answer==1)
{TV TV1;
cout<<"TV1\n";
TV1.turnon();
TV1.setchannel(1);
TV1.setvolume(1);
//deciding whether to change volume or channel.
tvchoice1: cout<<"Press 'c' to change the channel or press 'v' to change the volume: ";
cin>>answer2;
//changing channel
switch (answer2)
{case 'c':
tvchoice2: cout<<"Press '+' in order to increase the channel by 1 or press '-' to decrease the channel by 1: ";
cin>>answer3;
	switch (answer3)
	{case '+':
		TV1.channelup();
		goto turnoff;
	case '-':
		TV1.channeldown();
		goto turnoff;
	default:
		cout<<"Your input cannot be read";
		goto turnoff;	
	}	
//changing volume
case 'v':
tvchoice3: cout<<"Press '+' in order to increase the volume by 1 or press '-' to decrease the volume by 1: ";
cin>>answer4;
	switch (answer4)
	{case '+':
		TV1.volumeup();
		goto turnoff;
	case '-':
		TV1.volumedown();
		goto turnoff;
	default:
		cout<<"Your input cannot be read";
		goto turnoff;	
	}
default:
cout<<"Your input cannot be read please try again";
goto tvchoice1;
}
turnoff: TV1.turnoff();
//Goto statement to turning off complete program.
cout<<"\nPress 'x' to end the program.";
cin>>answer5;
switch (answer5)
{case 'x':
goto endstatement;
default:
goto endstatement;
}
}
//Tv2 options and control
else if (answer==2)
{TV TV2;
cout<<"TV2\n";
TV2.turnon();
TV2.setchannel(1);
TV2.setvolume(1);
//deciding whether to change volume or channel.
tvchoice4: cout<<"Press 'c' to change the channel or press 'v' to change the volume: ";
cin>>answer2;
//changing channel
switch (answer2)
{case 'c':
tvchoice5: cout<<"Press '+' in order to increase the channel by 1 or press '-' to decrease the channel by 1: ";
cin>>answer3;
	switch (answer3)
	{case '+':
		TV2.channelup();
		goto turnoff2;
	case '-':
		TV2.channeldown();
		goto turnoff2;
	default:
		cout<<"Your input cannot be read";
		goto turnoff2;	
	}
//changing volume
case 'v':
tvchoice6: cout<<"Press '+' in order to increase the volume by 1 or press '-' to decrease the volume by 1: ";
cin>>answer4;
	switch (answer4)
	{case '+':
		TV2.volumeup();
		goto turnoff2;
	case '-':
		TV2.volumedown();
		goto turnoff2;
	default:
		cout<<"Your input cannot be read";
		goto turnoff2;	
	}
default:
cout<<"Your input cannot be read please try again";
goto tvchoice4;
}
turnoff2: TV2.turnoff();
//Goto statement to turning off complete program.
cout<<"\nPress 'x' to end the program.";
cin>>answer5;
switch (answer5)
{case 'x':
goto endstatement;
default:
goto endstatement;
}
}
else
{cout<<"You did not input 1 or 2, the Tv's will turn off";
}
endstatement: return 0;	
}





