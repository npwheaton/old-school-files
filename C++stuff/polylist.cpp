#include <iostream>
#include <cstdlib>
#include "polylist.h"
using namespace std;

poly::poly()//constructor 
{p=NULL;}
void poly::insert(int x, float y)// insert function
{polyn temp1= new node;
temp1->next=NULL;
temp1->coef=y;
temp1->exp=x;
polyn temp2=p;
if (p!=NULL) //if function is not null it searches for the exponent to either add the coefficient or add the node at the end
	{ while (x!=temp2->exp && temp2->next!=NULL)
		{temp2=temp2->next;}
	if (x==temp2->exp)
		{temp2->coef=(temp2->coef)+y;}
	else
	{temp2->next=temp1;}
	}	
else// if node if null it creates a new node 
	{p= new node;
	p->coef=temp1->coef;
	p->exp=temp1->exp;
	p->next=temp1->next;}
	
}
int poly::senddegr()
{int degree=0;
polyn temp=p;
while (temp!=NULL)// checcks entire list for the hishest number and returns it
	{if (degree<temp->exp)
		{degree=temp->exp;
		temp=temp->next;
		}
	else
	{temp=temp->next;}
	}
	return degree;
}
void poly::multiply(float x)// multiplies the polynomial by a float number
{polyn temp=p;
while (temp!=NULL)
	{temp->coef=(temp->coef)*x;
	temp=temp->next;
	}
}
void poly::deriv()//takes the derivative of the polynomial by using a formula
{polyn temp=p;
while (temp!=NULL)
	{if (temp->exp==0)
	{temp=temp->next;}
	else
	{temp->coef=(temp->coef)*temp->exp;
	temp->exp=(temp->exp)-1;
	temp=temp->next;
	}
	}
}
void poly::print()
{polyn temp=p;
cout<<"f(x)= ";
while (temp!=NULL)// uses a while loop to print 
	{cout<<temp->coef;
	cout<<"x^"<<temp->exp;
	cout<<" + ";
	temp=temp->next;
	}
cout<<"\n";
}
void poly::set(node* &x)// assigns a node sent to the function the polynomials
{polyn temp=p;
while (temp!=NULL)
	{x->coef=temp->coef;
	x->exp=temp->exp;
	x=x->next;
	temp=temp->next;
	}
}
void poly::copynode()// creates a new node that copies th existing list
{
polyn temp=p;
polyn temp3=new node;
while (temp!=NULL)
	{temp3->coef=temp->coef;
	temp3->exp=temp->exp;
	temp3=temp3->next;
	temp=temp->next;
	}
	temp3->next=NULL;
}
void poly::emptyit()// reinitializes the polynomial to 0
{polyn temp;
while (p!=NULL)
	{temp=p;
	temp->coef=0;
	temp->exp=0;
	p=p->next;
	}

}

poly::~poly()//destructor deletes node and contents
{polyn temp;
while (p!=NULL)
	{temp=p;
	p=p->next;
	delete temp;
	}
}
