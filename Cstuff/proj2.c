#include <stdio.h>

int main(int argc, char*argv[]){
	int sendto;
	int fd[2];
	if (pipe(fd)==-1){
		printf("Pipe failed \n");
	}
	int id = fork();
	if(id== 0){
		close(fd[0]);
		printf("Input a number\n 1. Account\n 2. List\n 3. Date\n 4. Exit ");
		scanf("%d", &sendto);
		write(fd[1], &sendto, sizeof(int));

		execv(./proj25, args);
	}
	
}


