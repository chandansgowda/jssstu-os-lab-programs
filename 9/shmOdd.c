#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/shm.h>

void main(){
	
	pid_t child_pid, wait_pid;
	int n,i,shmid;
	int *shared_memory;
	
	printf("Enter n>> ");
	scanf("%d", &n);
	
	shmid = shmget((key_t)110011,1024,0666|IPC_CREAT);
	shared_memory = (int*)shmat(shmid,NULL,0);
	
	child_pid = fork();
	
	if (child_pid<0){
		printf("Child creation failed!\n");
		exit(0);
	}	
	
	if (child_pid==0){
		int j=0;
		for(i=1;i<2*n;i++){
			if (i%2!=0){
				shared_memory[j] = i;
				j++;
			}
		}
	}
	else{
		wait_pid = wait(NULL);
		for(i=0;i<n;i++){
			printf("%d ",shared_memory[i]);
		}
		printf("\n");
		shmdt(shared_memory);
	}
	
}
