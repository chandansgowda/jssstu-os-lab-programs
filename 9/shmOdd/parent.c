#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/shm.h>

void main(){
	
	int n,i,shmid;
	int *shared_memory;
	
	printf("Enter n>> ");
	scanf("%d", &n);
	char nstr[20];
	sprintf(nstr, "%d", n);
	
	shmid = shmget((key_t)110011,1024,0666|IPC_CREAT);
	shared_memory = (int*)shmat(shmid,NULL,0);
	
	if (fork()==0){
		execlp("./child","child",nstr,NULL);
	}
	else{
		wait(NULL);
		for(i=0;i<n;i++){
			printf("%d ",shared_memory[i]);
		}
		printf("\n");
		shmdt(shared_memory);
	}
	
}
