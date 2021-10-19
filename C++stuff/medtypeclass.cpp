#include <iostream>
#include "medtypeclass.h"
using namespace std;

void medtype::prozac()
{
medcost+=23.75;
}
void medtype::triliscene()
{
medcost+=14.75;
}
void medtype::dolisol()
{
medcost+=35.25;
}
void medtype::osephrine()
{
medcost+=10.75;
}
void medtype::clarolium()
{
medcost+=5.50;
}
float medtype::getmed()
{return medcost;
}
void medtype::startmed()
{medcost=0;
}

