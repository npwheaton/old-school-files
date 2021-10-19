#ifndef BST_H
#define BST_H

class bst{
	private:
	struct node{
		int data;
		node* left;
		node* right;
	};
node* root;
void destroytree(node* root);
void starttree();
void insertbranch(int x, node* &p);
void helpcut(int x, node* &p);
void cutbranch(node* &p);
int countbranch(node* p);
bool searchtree(int x,node* p);
void printtree(node* p);
public:
bst();
~bst();
void insert(int x);
void remove(int x);
void initialize();
int length();
bool presence(int x);
void print();
	
};
#endif
