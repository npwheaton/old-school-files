#include <iostream>
#include "surgtype.h"
#include "surgtypeclass.cpp"
#include "medtypeclass.h"
#include "medtypeclass.cpp"
#include "pntacntclass.h"
#include "pntacntclass.cpp"
using namespace std;


int main()
{ptntacntclass person;
medtype med;
surgtype surg;
person.initial();
surg.startsurg();
med.startmed();
char whichsurg;
int again;
cout<<"Hello and welcome to St. Nathaniel's hospital, if you have an appointment for a procedure please press the corresponding letter:\n";
do
{cout<<"A. Lip injection\nB. Glute implants\nC. Breast Implant\nD. Liposuction\nE.Lasik eye surgery\n or F to cancel.\n";
cin>>whichsurg;
switch (whichsurg)
{case 'a':
	surg.lipinject();
	cout<<"\nYou will also need to\nTake Prozac twice daily to reduce swelling and\nTake Clarolium three times daily to reduce gas after your procedure.";
	cout<<"\n\n Your procedure is done.\n\n";
	break;
	
case 'b':
	surg.gluteimp();
	cout<<"\nYou will also need to\nTake Dolisol three times a day as a antibiotic,\nTake Prozac twice daily to reduce swelling";
	cout<<" and\nTake Triliscene daily to reduce pain after your procedure.";
	cout<<"\n\n Your procedure is done.\n\n";
	med.dolisol();
	med.prozac();
	med.triliscene();
	break;
case 'c':
	surg.breastimp();
	cout<<"\nYou will also need to\nTake Dolisol three times a day as a antibiotic,\nTake Prozac twice daily to reduce swelling";
	cout<<" and\nTake Triliscene daily to reduce pain after your procedure.";
	cout<<"\n\n Your procedure is done.\n\n";
	med.dolisol();
	med.prozac();
	med.triliscene();
	break;
case 'd':
	surg.lipo();
	cout<<"\nYou will also need to\nTake Dolisol three times a day as a antibiotic,\nTake Prozac twice daily to reduce swelling";
	cout<<", and\nTake Triliscene daily to reduce pain after your procedure.";
	cout<<"\n\n Your procedure is done.\n\n";
	med.dolisol();
	med.prozac();
	med.triliscene();
	break;
case 'e':
	surg.lasik();
	cout<<"\nYou will also need to\nTake Osephrine twice daily to dialate eyes and\nTake Triliscene daily to reduce pain after your procedure.";
	cout<<"\n\n Your procedure is done.\n\n";
	med.osephrine();
	med.triliscene();
	break;
case 'f':
	cout<<"\n";
	break;
default:
	cout<<"Please input a number in the choice range\n";

}
cout<<"\nIf you are scheduled for another procedure please press 0, if not press 1\n";
cin>>again;
}while(again==0);
person.addtocharges(surg.getsurgcost());
person.addtocharges(med.getmed());
person.addtodays(surg.getsurgdays());

cout<<"Thank you for choosing St. Nathaniel's hospital, after spending "<<person.getdays()<<" days, the cost for your stay adds up to $"<<person.getcharges();

}
