#include <stdio.h>
#ifndef PROJ1_H
#define PROJ1_H

#ifdef HEX
#define SHIFTCOUNT 4
#else
#define SHIFTCOUNT 1
#endif
#define SRC(x) (x) >> (SHIFTCOUNT)
#define SLC(x) (x) << (SHIFTCOUNT)
int menu();







#endif
