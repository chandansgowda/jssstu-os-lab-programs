//Include -lrt while compiling

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/mman.h>

void main(int argc, char* argv[]){
	
	if (argc<2){
		printf("Didn't pass range\n");
		exit(0);
	}
	
	pid_t child_pid, wait_pid;
	int m = atoi(argv[1]);
	int n = atoi(argv[2]);
	int fd, i, j,flag;
	int* shared_memory;
	
	fd = shm_open("chandan", O_CREAT|O_RDWR , S_IRUSR|S_IWUSR);
	ftruncate(fd,1024);
	
	shared_memory = (int*) mmap(NULL,1024, PROT_WRITE, MAP_SHARED, fd, 0);
	
	child_pid = fork();
	
	if (child_pid<0){
		printf("Fork failed!\n");
		exit(0);
	}
	
	if (child_pid==0){
		int k=0;
		for(i=m;i<=n;i++){
			flag=1;
			for(j=2;j<n/2;j++){
				if (i%j==0){
					flag=0;
					break;
				}
			}
			if (flag){
				shared_memory[k++] = i;
			}
		}
		shared_memory[k]=0;
	
	}
	else{
		wait_pid = wait(NULL);
		int i=0;
		while(shared_memory[i]!=0){
			printf("%d ",shared_memory[i++]);
		}
		printf("\n");
		shm_unlink("chandan");
	}
}
