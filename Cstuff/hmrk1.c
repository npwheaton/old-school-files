#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>

//global variables
#define MAX 500
int inc = 5;
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
void* threadfunc(void* arg) {

    clock_t t;
    t = clock();
     int Id = *(( int*) arg);
    int count = 0;
    for( int i = Id * inc; i < ((Id + 1) * inc); ++i) {
        if(prime(i)) 
        {count++;}
    }

    t = clock() - t;
    int timepast = ((double)t) / CLOCKS_PER_SEC;
    printf("id = %d, count = %d, elapsed time= %d seconds\n", Id, count, timepast);

    pthread_exit(NULL);
}
int main(int argc, char* argv[]){
int threadn = atoi(argv[1]);
 inc = atoi(argv[2]);

//threads
pthread_t runner[MAX];
    int args[MAX];
    for( int i = 0; i < threadn; i++) {
        args[i] = i;
        err = pthread_create(&runner[i], NULL, threadfunc, (void*) &args[i]);
        if(err)
        {printf("Thread: %d failed\n", i)}
    }

    for(int i = 0; i < threadn; i++) {
        pthread_join(runner[i], NULL);
    }
    
    printf("All threads completed.\n");

    return 0;
}