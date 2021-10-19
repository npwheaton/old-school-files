#include "LINKARRAY.H"
#include <iostream>
#include <cstdlib>
using namespace std;

linkarray::linkarray(int x){
if(x==1)
{rowsize=0;}
else
{rowsize= x;}
top=NULL;
upper=NULL;
mid=NULL;
lower=NULL;
bottom=NULL;
initial(0,top, upper, mid, lower, bottom);
connector(0,top, upper, mid, lower, bottom);
}
void linkarray::initial( int i, node* &a, node* &b, node* &c, node* &d, node* &e){
if (i=0 and a==NULL and b==NULL and c==NULL and d==NULL and e==NULL)
	{a= new node;
	a->id=i;
	a->left=NULL;
	a->up=NULL;
	a->down=NULL;
	a->right=NULL;
	b= new node;
	b->id=i+10;
	b->left=NULL;
	b->up=NULL;
	b->down=NULL;
	b->right=NULL;
	c= new node;
	c->id=i+20;
	c->left=NULL;
	c->up=NULL;
	c->down=NULL;
	c->right=NULL;
	d= new node;
	d->id=i+30;
	d->left=NULL;
	d->up=NULL;
	d->down=NULL;
	d->right=NULL;
	e= new node;
	e->id=i+40;
	e->left=NULL;
	e->up=NULL;
	e->down=NULL;
	e->right=NULL;
	initial(i++, a->right, b->right, c->right,d->right, e->right);
	}
else if (i>0 and i<rowsize and a==NULL and b==NULL and c==NULL and d==NULL and e==NULL)
	{node* v;
	node* w;
	node* x;
	node* y;
	node* z;
	v=new node;
	v->id=i;
	v->right=NULL;
	a->right=v;
	w=new node;
	w->id=i+10;
	w->right=NULL;
	b->right=w;
	x=new node;
	x->id=i+20;
	x->right=NULL;
	c->right=x;
	y=new node;
	y->id=i+30;
	y->right=NULL;
	d->right=y;
	z=new node;
	z->id=i+40;
	z->right=NULL;
	e->right=z;
	initial(i++, a->right, b->right, c->right,d->right, e->right);
	}	
}
void linkarray::connector(int i,node* &a, node* &b, node* &c, node* &d, node* &e){
if (i=0)
	{a->down=b;
	b->down=c;
	c->down=d;
	d->down=e;
	e->up=d;
	d->up=c;
	c->up=b;
	b->up=a;
	a->right->left=a;
	b->right->left=b;
	c->right->left=c;
	d->right->left=d;
	e->right->left=e;
	connector(i++, a->right, b->right, c->right,d->right, e->right);
	}
else if (i>0 and i<rowsize and a!=NULL)
	{a->down=b;
	b->down=c;
	c->down=d;
	d->down=e;
	e->up=d;
	d->up=c;
	c->up=b;
	b->up=a;
	a->right->left=a;
	b->right->left=b;
	c->right->left=c;
	d->right->left=d;
	e->right->left=e;
	connector(i++, a->right, b->right, c->right,d->right, e->right);
	}
}
void linkarray::search(int x, node* a, node* b, node* c, node* d, node* e){
if (x==a->id or x==b->id or x==c->id or x==d->id or x==e->id)
	{cout<<"The input has been found\n";}
else if (a->right==NULL)
	{cout<<"The input has not been found\n";}
else
search(x, a->right, b->right, c->right,d->right, e->right);
}

