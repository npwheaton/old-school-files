#ifndef LINKARRAY_H
#define LINKARRAY_H

class linkarray
{private:
	int rowsize;
	struct node{
		int id;
		node* up;
		node* down;
		node* left;
		node* right;
	};
	node* top;
	node* upper;
	node* mid;
	node* lower;
	node* bottom;
public:
void initial(int i,node* &a, node* &b, node* &c, node* &d, node* &e);//creates 10 nodes
linkarray(int x);//constructor
~linkarray();//destructor
void connector(int i,node* &a, node* &b, node* &c, node* &d, node* &e);//connects all nodes
void search(int x, node* a, node* b, node* c, node* d, node* e);//searches nodes for id
};
#endif
