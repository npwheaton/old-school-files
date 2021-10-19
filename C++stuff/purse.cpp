#include <iostream>
using namespace std;

void initial (int& pennies, int& nickels, int& dimes, int& quarters)
{pennies=0;
nickels=0;
dimes=0;
quarters=0;
float x=pennies+(5*nickels)+(10*dimes)+(25*quarters);
x=(float)x/100;

cout<<"You have\n";
cout<<quarters<< " quarters + "<<dimes<<" dimes + "<<nickels<<" nickels + "<<pennies<<" pennies which equals\n$"<<x<<endl;}

void insert (int& pennies, int& nickels, int& dimes, int& quarters, int& p,int& n,int& d,int& q)
{cout<<"Enter the amount of pennies, nickels, dimes and quarters respectively that you want to deposit.\nAnd press enter after each amount:\n";
cin>>p>>n>>d>>q;
pennies+=p;
nickels+=n;
dimes+=d;
quarters+=q;
float x=pennies+(5*nickels)+(10*dimes)+(25*quarters);
x=(float)x/100;

cout<<"You have\n";
cout<<quarters<< " quarters + "<<dimes<<" dimes + "<<nickels<<" nickels + "<<pennies<<" pennies which equals\n$"<<x<<endl;
}

void removal (int& pennies, int& nickels, int& dimes, int& quarters, int& p,int& n,int& d,int& q)
{cout<<"Enter the amount of pennies, nickels, dimes and quarters repectively that you want to withdraw.\nAnd press enter after each amount:\n";
cin>>p>>n>>d>>q;
pennies-=p;
nickels-=n;
dimes-=d;
quarters-=q;
float x=pennies+(5*nickels)+(10*dimes)+(25*quarters);
x=(float)x/100;

cout<<"You have\n";
cout<<quarters<< " quarters + "<<dimes<<" dimes + "<<nickels<<" nickels + "<<pennies<<" pennies which equals\n$"<<x<<endl;
}

int main()
{int pennies, nickels, dimes, quarters, p, n, d, q; 
float x;
char answer;
initial(pennies, nickels, dimes,quarters);

choice: cout<<"Would you like to deposit or withdraw money?\n";
cout<<"Press 'd' to deposit money, 'w' to withdraw money, or 'x' to cancel all action:\n";
cin>>answer;

 switch (answer)
{case 'd':
	insert (pennies, nickels, dimes, quarters, p, n, d, q);
	goto choice;
case'w':
	removal (pennies, nickels, dimes, quarters, p, n, d, q);
	goto choice;
case 'x':
	return 0;
	break;
	
default:
cout<<"Sorry, your input did not match any of the options given please try again.\n...\n...\n...\n";
goto choice;	
}
}

