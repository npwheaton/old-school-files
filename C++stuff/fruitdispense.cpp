#include <iostream>
using namespace std;

class cshregister
{private:
	float cashonhand;
	public:
	float getcurrentbalance();
	void acceptamount(float x);
	void strtregister();
	
};

float cshregister::getcurrentbalance()
{return cashonhand;}
void cshregister::acceptamount(float x)
{cashonhand+=x;}
void cshregister::strtregister()
{cashonhand=500;}

class dispenser
{private:
	int items;
	float cost;
	public:
	float getcost();
	void makesale();
	void strtdispense(int x,float y);
	int getitems();

};

float dispenser::getcost()
{return cost;}
void dispenser::makesale()
{cout<<" Your item is dispensed"<<endl;
items--;
}
void dispenser::strtdispense(int x, float y)
{items=x;
cost=y;
}
int dispenser::getitems()
{return items;}

int main()
{float x;
char ans1;
int ans2;
cshregister cashier;
dispenser orange;
dispenser banana;
dispenser mango;
dispenser apple;


cashier.strtregister();
orange.strtdispense(50, 1.50);
mango.strtdispense(50, 1.75);
banana.strtdispense(50, 1.75);
apple.strtdispense(50, 1.00);

do
{cout<<"Press o for Orange juice $1.50\n Press m for Mango juice $1.75\n Press b for Banana juice $1.75\n Press a for Apple juice $1.00\n";
cout<<"Or x to choose nothing\n";
cin>>ans1;
switch (ans1)
{
	case 'o':
		
		do
		{cout<<"pls enter the cost in the machine, the cost is "<<orange.getcost()<<endl;
		cin>>x;
		if (x==1.50)
		{cashier.acceptamount(x);
		orange.makesale();}
		else
		{cout<<"Plz input the exact amount";}
		}while(x!=1.50);
		break;
		
	case 'm':
		
		do
		{cout<<"pls enter the cost in the machine, the cost is "<<mango.getcost()<<endl;
		cin>>x;
		if (x==1.75)
		{cashier.acceptamount(x);
		mango.makesale();}
		else
		{cout<<"Plz input the exact amount";}
		}while(x!=1.75);
		break;
	
	case 'b':
		
		do
		{cout<<"pls enter the cost in the machine, the cost is "<<banana.getcost()<<endl;
		cin>>x;
		if (x==1.75)
		{cashier.acceptamount(x);
		banana.makesale();}
		else
		{cout<<"Plz input the exact amount";}
		}while(x!=1.75);
		break;
	
	case 'a':
		
		do
		{cout<<"pls enter the cost in the machine, the cost is "<<apple.getcost()<<endl;
		cin>>x;
		if (x==1.00)
		{cashier.acceptamount(x);
		apple.makesale();}
		else
		{cout<<"Plz input the exact amount";}
		}while(x!=1.00);
		break;
	
	case 'x':
		cout<<"\n";
		break;
	default:
	 cout<<"The input cannot be read\n";			
}
cout<<"There are "<<orange.getitems()<<" oranges left\n";
cout<<mango.getitems()<<" mangoes left\n";
cout<<banana.getitems()<<" bananas left\n";
cout<<apple.getitems()<<" apples left\n";
cout<<"If you would you like to buy some more juice press 0, if not press 1\n";
cin>>ans2;
if (ans2!=0 and ans2!=1)
{ans2=1;}
else
{cout<<"";}
}while (ans2!=1);
cout<<"Thank you for using this fruit dispenser";
return 0;
}
