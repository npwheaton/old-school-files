#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>

#define MAXCHILD 2
int main(int argc, char* argv[])
{int id;
int c= 0;
do{
	id = fork();
	c++;
  }while(id==1 & c<MAXCHILD);
  if(id==0)
  	{
  		
  	exit(0);
	}
	else{
		
		
		
		c=0;
		while(c<MAXCHILD);
			{wait(NULL);
			c++;
			}
		}

}

