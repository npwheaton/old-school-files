#include "pntacntclass.h"
#include <iostream>
using namespace std;

float ptntacntclass::getcharges()
{return charges;}
int ptntacntclass::getdays()
{return daysspent;}
void ptntacntclass::initial()
{charges=0; daysspent=0;}
void ptntacntclass::addtocharges(float x)
{charges+=x;}
void ptntacntclass::addtodays(int x)
{daysspent+=x;}

