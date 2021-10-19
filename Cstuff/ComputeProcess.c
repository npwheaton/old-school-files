#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>


//prime function
int prime(int value) {
    for(int i=2; i<=value/2; i++) {
        if(value%i == 0) {
                return 0;
        }
    }
    return 1;
}
//function that thread runs on
int main(int argc, char* argv[]) {
	if (argc<2)
		{
		printf("Not enough arguments");
		exit(1);
		}
    int temp = atoi(argv[1]);
     int Id = temp;
    int count = 0;
    for( int i = Id * INC; i < ((Id + 1) * INC); ++i) {
        if(prime(i)) 
        {count++;}
    }
    printf("id = %d, count = %d\n", Id, count);
return 0;
}
