#include <iostream>
#include "pntacntclass.h"
using namespace std;

float ptntacnt::getcharges()
{return charges;}
int ptntacnt::getdays()
{return daysspent;}
void ptntacnt::initial()
{charges=0; daysspent=0;}
void ptntacnt::addtocharges(float x)
{charges+=x;}
void ptntacnt::addtodays(int x)
{daysspent+=x;}

