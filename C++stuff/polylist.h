#ifndef POLYLIST_H
#define POLYLIST_H

class poly
{private:
	typedef struct node{
		int exp;
	double coef;
	node* next;
	}*polyn;
	polyn p;
public:
poly();
void insert(int x, float y);
void multiply(float x);
void copynode();
void set(node* &x);
int senddegr();
void deriv();
void print();
~poly();
void emptyit();
};
#endif
