#ifndef RLIST_H
#define RLIST_H

class rlist
{private:
	struct node{
		int data;
	node* next;
	};
	node* first;
void initial();//constructor function
void destroy(node* p);// destructor function
void putin(int x, node* &p);// create node function
void takeout(int x, node* &p);//remove node function
bool checkempty(node* p);//check if the function is empty function
int checklength(node* p);//check the length of the list function
void checkpresent(int x, node* p);//check if the value is present in list function
void rprint(node* p);//prints function
void remptyit(node* p);//reinitialize to 0 function
public:	
rlist();//friend function for constructor
~rlist();//friend function for destructor
void insert(int x);//friend function for create node function
void remove(int x);//friend function for remove function
bool tellempty();//friend function for check empty function
int sendlength();//friend function for check length
void tellpresent(int x);//friend function for check th value function
void toprint();//friend function for print function
void telltoempty();//friend frunction for reinitialize function
};
#endif
