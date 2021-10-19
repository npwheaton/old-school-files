#ifndef ARRAY_H
#define ARRAY_H

class array
{private:
 int size;//size of array
	int *pt1;//pointer for array 1
	int *pt2;//pointer for array 2
	int arraycount;//counts how many arrays there are
	
public:
	array(int x=10);//constructor passes default 10 size
	~array();//destructor
	void fillelements(int input[]);//fills the elements of array
	void fillelements2(int input[]);//fills elements of 2nd array
	void printelements();//prints elements of 1st array
	void printelements2();//prints elements of 2nd array
	bool compareit();//compares 2 arrays
	void copyarray();//copies the 2nd array to the first array elements
	int getsize();//gets the size of array.
	

};
#endif
