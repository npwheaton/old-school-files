#ifndef EXPRESS_H
#define EXPRESS_H
#include <fstream>
class expresstree
{private:
struct node{
int operand;
char optr;
node* left;
node* right;
};
node* root;
void start();
node* rbuild(std::istream& in);
void  infix(node* r);
void prefix(node* r);
void postfix(node* r);
void destroyexp(node* r);
int findequation(node* r);
int solve(int x, char y, int z);
public:
expresstree();
~expresstree();
void build(std::istream& in);
void printin();
void printpre();
void printpos();
int sendvalue();
void emptytree();
};
#endif

