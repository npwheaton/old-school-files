#include "STACK.h"
#include <iostream>

using namespace std;

stack::stack(){used=0;}
void stack::push(char x){data[used++]=x;}
char stack::pop(){return data[--used];}
bool stack::empty(){return used==0;}
