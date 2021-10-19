#ifndef STACK_H
#define STACK_H

class stack
{private:
	static const int capacity=100;
	char data[capacity];
	int used;
	
public:
	
	stack();
	void push(char x);
	char pop();
	bool empty();
};
#endif
