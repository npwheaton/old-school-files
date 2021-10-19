#ifndef QUEUE_H
#define QUEUE_H

class queue
{private:
	static const int capacity=100;
	int data[capacity];
	int front;
	int rear;
	int length;//size of line
	int customers;//the  amount of people dequed
	int waittime;//the waitime
	int accumtime;//used to calculate average time
	
	
public:
	void enqueue(int x);//adds someone to line
	int dequeue();//takes someone out of line
	int sizeofline();//tells teh size of line
	bool empty();//checks if teh line is empty
	int nextindex(int i);//for circular queue
	queue();//constructor
	int tellcust();//tells the amount of peple dequed from a line
	float tellavgtime();//tells average waittime
	int makewait(int x);//creates a random waitime
	int tellwait();//tells the waittime
	void minustime();//decrements wait time
	void printstat();//prints statistics
	
};
#endif

