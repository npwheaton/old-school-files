#include "BST.H"
#include <iostream>
#include <cstdlib>
using namespace std;

void bst::destroytree(node* p)//destructor function
{if (p!=NULL)
	{destroytree(p->left);
	destroytree(p->right);
	delete p;
	}
}
void bst::starttree()//constructor
{root=NULL;}
void bst::insertbranch(int x,node* &p)//inserts new node, in order of value
{if (p==NULL)
	{p=new node;
	p->data=x;
	p->left=NULL;
	p->right=NULL;
	}
else if (x<p->data)
	{insertbranch(x,p->left);}
else if (x>p->data)
{insertbranch(x,p->right);}

}
void bst::cutbranch(node* &p)//remove function that actually removes node and replaces the node's data with another
{node* pt, * back;
if (p->left==NULL && p->right==NULL)
	{delete p;
	p=NULL;
	}
else if (p->left==NULL)
	{pt=p;
	p=p->right;
	delete pt;
	}
else if (p->right==NULL)
	{pt=p;
	p=p->left;
	delete pt;
	}
else
{	back=p;
	pt=p->right;
	while (pt->left!=NULL)
		{back=pt;
		pt=pt->left;
		}
	p->data=pt->data;
	if (back==p)
	{cutbranch(back->right);
	}
	else 
	cutbranch(back->left);
}
}
void bst::helpcut(int x, node* &p)//first remove function, it searches for the value to remove and returns it. if the root becomes NULL it stops
{if (p==NULL)
{cout<<"The data member does not exist in this list\n";}
else if (p->data==x)
	{cutbranch(p);}
else if (p->data>x)
	{helpcut(x,p->left);}
else
{helpcut(x,p->right);}

}
bool bst::searchtree(int x, node* p)// goes through every branch, and returns true if number is found if the list is NULL it returns false
{if (p==NULL)
{return false;}
else if (p->data==x)
	{return true;}
else if (p->data>x)
	{searchtree(x,p->left);}
else
	{searchtree(x,p->right);}
}
void bst::printtree(node* p)
{if (p!=NULL)//prints the tree in order
	{printtree(p->left);
	cout<<p->data;
	cout<<" ";
	printtree(p->right);
	}
}
int bst::countbranch(node* p)
{int counted=0;
if (p!=NULL)
	{counted++;
	return counted + countbranch(p->left) + countbranch(p->right);//goes through all branches and returns a 1+ all the branches
	}
}
bst::bst(){starttree();}//public constructor
void bst::remove(int x){helpcut(x,root);}//public remove function
void bst::insert(int x){insertbranch(x, root);}//public insert function
void bst::initialize(){//initialize fnction just calls the private destructor and private constructor
destroytree(root);
starttree();
}
bst::~bst(){destroytree(root);}//destructor
int bst::length(){return countbranch(root);}//public count tree function
bool bst::presence(int x){return searchtree(x, root);}//public search tree function
void bst::print(){printtree(root);}//public print function

