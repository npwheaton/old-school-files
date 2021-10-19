#include <stdio.h>
#include <string.h>

#include "proj1.h"
char binary[500];
void bin(unsigned n) 
{ char temp[0];
int t;
	/* step 1 */
	if (n > 1)
		{bin(n/2); } 
		

	/* step 2 */
	 t= n % 2;
	snprintf(temp, 1, "%d", t);
	 strcat(binary, temp);
} 
int main()
{int number;
int determine;
int answer;
determine = SHIFTCOUNT;
printf("Input a number\n");
	scanf("%d", &number);
while (answer!=4)
{answer = menu();
	switch(answer)
		{case 1:
			if(determine==4)
				{printf("The number in Hexadecimal is %x\n", number);}
			else
				{memset(binary, '\0',sizeof(binary));
				bin(number);
				atoi(binary);
				printf("The number in Binary is %d\n", number);}
			break;
		case 2:
			number = SLC(number);
			break;
		case 3:
			number = SRC(number);
			break;
		case 4:
			break;
		}
}

	return 0;
}
