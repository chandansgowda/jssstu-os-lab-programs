#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>

void main(){
	int shmid, n;
	int *shared_memory;
	
	shmid = shmget((key_t)110011, 1024, 0666|IPC_CREAT);
	shared_memory = (int*)shmat(shmid,NULL,0);
	
	printf("Enter n>> ");
	scanf("%d",&n);
	char nstr[20];
	sprintf(nstr, "%d", n);
	
	if (fork()==0){
		execlp("./child", "child", nstr, NULL);
	}
	else{
		wait(NULL);
		
		for(int i=0;i<n;i++){
			printf("%d ",shared_memory[i]);
		}
		printf("\n");
		
		shmdt(shared_memory);
	
	}
}
