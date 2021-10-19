#include "RLIST.H"
#include <iostream>
#include <cstdlib>
using namespace std;

void rlist::initial()//constructor function
{first=NULL;}
void rlist::destroy(node* p)//destrctor funtion
{ if(p!=NULL)
	{destroy(p->next);
	delete p;
	}
}
void rlist::putin(int x, node* &p)//inserts a node and data member into the list
{ 
if(p==NULL)//creates the first node if list is NULL
	{p= new node;
	p->data=x;
	p->next=NULL;
	}
	else if (x>p->data && p->next==NULL)// if the x is greater than all the data members and the next node is NULL, it inserts a node at the end
	{node* temp;
	temp=new node;
	temp->data=x;
	temp->next=NULL;
	p->next=temp;
	}
	else if (x<p->data)//if x is greater than the last data and less then the next data it inserts a node in the middle
	{node* temp;
	temp=new node;
	temp->data=x;
	temp->next=p;
	p=temp;
	}
	else if (x>p->data)//recurses the function 
	{putin(x,p->next);}
	else//for when x is equal to a data member
	{ }
}
void rlist::takeout(int x, node* &p)//removes a node in a list
{node* temp;
if (p->data==x)
	{temp=p;
	p=p->next;
	delete temp;
	}
else if(p->next==NULL)
{cout<<"The data member is not in the list\n";}
else
{takeout(x,p->next);}
}
bool rlist::checkempty(node* p)//checks if the list is empty
{ if(p==NULL)
	{return true;}
else
{return false;}
	
}
int rlist::checklength(node* p)//checks the length by incrementing k every time the list isnt NULL
{int k=0;
if (p!=NULL)
	{k++;
	return k+checklength(p->next);
	}
	else
	{return k;}
}
void rlist::checkpresent(int x, node* p)//checks if the value is in the list with a if loop and recursion
{if (p==NULL)
	{cout<<"The data element is not present in the list\n"; }
	else if (x!=p->data)
	{checkpresent(x,p->next);}
	else if (x==p->data)
	{cout<<"The data element is present in the list\n";}
}
void rlist::rprint(node* p)
{if (p!=NULL)// uses a while loop to print 
	{cout<<p->data<<" ";
	rprint(p->next);
	}
}
void rlist::remptyit(node* p)//deletes the list and sets first to NULL again
{if (p!=NULL)
	{remptyit(p->next);
	delete p;
	}
first=NULL;
}//all of the public functions
rlist::rlist(){initial();}//friend function for constructor function
rlist::~rlist(){destroy(first);}//friend for destructor
void rlist::insert(int x){putin(x, first); }//friend for insert
void rlist::remove(int x){takeout(x, first); }//friend for remove
bool rlist::tellempty(){return checkempty(first);}//friend for checkempty
int rlist::sendlength(){checklength(first); }//friend for check length
void rlist::tellpresent(int x){checkpresent(x, first);}//friend for check present
void rlist::telltoempty(){remptyit(first);}//friend for reinitialize
void rlist::toprint(){rprint(first);}//friend for print
