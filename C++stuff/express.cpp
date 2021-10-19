#include "EXPRESS.H"
#include <iostream>
#include <cstdlib>
using namespace std;

expresstree::node* expresstree::rbuild(std::istream& in){
char ch;
node* temp;
in>>ch;
if(isdigit(ch)){
	temp=new node;
	temp->operand=ch-'0';
	temp->left=NULL;
	temp->right=NULL;
}
else if(ch==')')
	{ }
else
	{temp=new node;
	temp->left=rbuild(in);
	in>>temp->optr;
	temp->right=rbuild(in);
	}
return temp;
}
void expresstree::infix(node* r){
	if(r->left==NULL)
	{cout<<r->operand<<" ";}
	else
	cout<<"(";
	infix(r->left);
	cout<<r->optr<<" ";
	infix(r->right);
	cout<<")";
}
void expresstree::prefix(node* r){
	if(r->left==NULL)
	{cout<<r->operand<<" ";}
	else
	
	cout<<r->optr<<" ";
	infix(r->left);
	infix(r->right);
	
}
void expresstree::postfix(node* r){
	if(r->left==NULL)
	{cout<<r->operand<<" ";}
	else
	infix(r->left);
	infix(r->right);
	cout<<r->optr<<" ";
	
}
void expresstree::start(){root=NULL;}
void expresstree::destroyexp(node* r){
if (r!=NULL)
	{destroyexp(r->left);
	destroyexp(r->right);
	delete r;
	}
}
expresstree::expresstree(){start();}
expresstree::~expresstree(){destroyexp(root);}
void expresstree::build(std::istream& in){rbuild(in);}
void expresstree::printin(){infix(root);}
void expresstree::printpos(){postfix(root);}
void expresstree::printpre(){prefix(root);}
int expresstree::findequation(node* r){
	int a, b;
	if (r->left->left==NULL && r->right->left==NULL)
		{return solve(r->left->operand,r->optr, r->right->operand);}
	else if(r->left->left==NULL)
		{int a, b;
		a=r->left->operand;
		b=findequation(r->right);
		return solve(a,r->optr,b);
		}
	else if( r->right->left==NULL)
		{
		a=findequation(r->left);
		b=r->right->operand;
		return solve(a,r->optr,b);
		}
	else
	a=findequation(r->left);
	b=findequation(r->right);
	return solve(a,r->optr,b);
}
int expresstree::solve(int x, char y, int z)
{int answer=0;
switch(y)
	{case '+':
	answer=x+z;
	break;
	
	case '-':
	answer=x-z;
	break;
	
	case '/':
	answer=x/z;
	break;
	
	case '*':
	answer=x*z;
	break;
	
	case '%':
	answer=x%z;
	break;
	}
return answer;
}
int expresstree::sendvalue(){return findequation(root);}
void expresstree::emptytree(){
destroyexp(root);
start();
}
