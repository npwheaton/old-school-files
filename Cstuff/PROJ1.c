#include <stdio.h>
#include "proj1.h"



int menu(){
int determine;
determine = SHIFTCOUNT;
int answer;
	printf("Choose a number from this menu\n");
	if (determine==4)
	{printf("1. Display number in Hexadecimal\n");	}
	else
	{printf("1. Display number in Binary\n");}
	printf("2. Shift left circular one digit\n");
	printf("3. Shift right circular one digit\n");
	printf("4. exit\n");
	printf("Input a number\n");
	scanf("%d", &answer);
return answer;
}



