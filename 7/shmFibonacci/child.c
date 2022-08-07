//Compile this program with arguments -> ( -o child )

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/wait.h>

void main(int argc, char* argv[]){

	int shmid, n;
	int buffer[25];
	int *shared_memory;
	n = atoi(argv[1]);
	
	shmid = shmget((key_t)110011, 1024, 0666);
	shared_memory = (int*)shmat(shmid,NULL,0);
		
	buffer[0] = 0;
	buffer[1] = 1;
	for(int i=2; i<n;i++){
		buffer[i] = buffer[i-1] + buffer[i-2];
	}
	
	for(int i=0;i<n;i++)
		shared_memory[i]=buffer[i];
}
