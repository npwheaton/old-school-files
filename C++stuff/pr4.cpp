// This progam calculates the user's tax rate.
#include <iostream>
using namespace std;

int main()
{
	double income, file, tax;
	
	cout<< "Enter the number that represents your filing status"<<endl;
	cout<< "1=single"<<endl;
	cout<<"2=married jointly or qualifying widow"<<endl;
	cout<<"3=married but separately filing"<<endl;
	cout<<"4=head of household"<<endl;
	cin>>file;
	
	//dividing out which filing section the user is, and then calculating
	if (file==1)
		{
		cout<< "Enter your income ";
		cin>>income;
		
			if (income>=307051)
			{
		tax=income*0.386;
			cout<<" Your federal income tax will be " <<tax<<endl;	
		}
			else if (income>=141251)	
		{
			tax=income*0.35;
			cout<<" Your federal income tax will be " <<tax<<endl;
			}	
			
			else if (income>=67701)
			{
				tax=income*0.30;
			cout<<" Your federal income tax will be " <<tax<<endl;
			}
			
			else if (income>=27951)
			{
				tax=income*0.27;
			cout<<" Your federal income tax will be " <<tax<<endl;	
			}
			
			else if (income>=6001)
			{
				tax=income*0.15;
			cout<<" Your federal income tax will be " <<tax<<endl;
			}
		
			else if (income<=6000)
			{
				tax=income*0.10;
			cout<<" Your federal income tax will be " <<tax<<endl;
			}
		}
		else if (file==2)
		{
		cout<< "Enter your income ";
		cin>>income;
			if (income>=307051)
			{
		tax=income*0.386;
			cout<<" Your federal income tax will be " <<tax<<endl;	
		}
			else if (income>=171951)	
		{
			tax=income*0.35;
			cout<<" Your federal income tax will be " <<tax<<endl;
			}	
			
			else if (income>=112851)
			{
				tax=income*0.30;
			cout<<" Your federal income tax will be " <<tax<<endl;
			}
			
			else if (income>=46701)
			{
				tax=income*0.27;
			cout<<" Your federal income tax will be " <<tax<<endl;	
			}
			
			else if (income>=12001)
			{
				tax=income*0.15;
			cout<<" Your federal income tax will be " <<tax<<endl;
			}
		
			else if (income<=12000)
			{
				tax=income*0.10;
			cout<<" Your federal income tax will be " <<tax<<endl;
			}
		}
		else if (file==3)
		{
		cout<< "Enter your income ";
		cin>>income;
			if (income>=153526)
			{
		tax=income*0.386;
			cout<<" Your federal income tax will be " <<tax<<endl;	
		}
			else if (income>=85976)	
		{
			tax=income*0.35;
			cout<<" Your federal income tax will be " <<tax<<endl;
			}	
			
			else if (income>=56426)
			{
				tax=income*0.30;
			cout<<" Your federal income tax will be " <<tax<<endl;
			}
			
			else if (income>=23351)
			{
				tax=income*0.27;
			cout<<" Your federal income tax will be " <<tax<<endl;	
			}
			
			else if (income>=6001)
			{
				tax=income*0.15;
			cout<<" Your federal income tax will be " <<tax<<endl;
			}
		
			else if (income<=6000)
			{
				tax=income*0.10;
			cout<<" Your federal income tax will be " <<tax<<endl;
			}
		}
		else if (file==4)
		{
		cout<< "Enter your income ";
		cin>>income;
				if (income>=307051)
			{
		tax=income*0.386;
			cout<<" Your federal income tax will be " <<tax<<endl;	
		}
			else if (income>=156601)	
		{
			tax=income*0.35;
			cout<<" Your federal income tax will be " <<tax<<endl;
			}	
			
			else if (income>=96701)
			{
				tax=income*0.30;
			cout<<" Your federal income tax will be " <<tax<<endl;
			}
			
			else if (income>=37451)
			{
				tax=income*0.27;
			cout<<" Your federal income tax will be " <<tax<<endl;	
			}
			
			else if (income>=10001)
			{
				tax=income*0.15;
			cout<<" Your federal income tax will be " <<tax<<endl;
			}
		
			else if (income<=10000)
			{
				tax=income*0.10;
			cout<<" Your federal income tax will be " <<tax<<endl;
			}
		}
		else
		{
			cout<<"you entered the wrong filing number, please try again"<<endl;
		}
	
}
