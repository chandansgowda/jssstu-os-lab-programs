//Include -lrt -o while compiling

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/mman.h>

void main(int argc, char* argv[]){
	
	int m = atoi(argv[1]);
	int n = atoi(argv[2]);
	int fd, i, j,flag;
	int* shared_memory;
	
	fd = shm_open("chandan", O_RDWR , 0666);	
	shared_memory = (int*) mmap(NULL,1024, PROT_WRITE, MAP_SHARED, fd, 0);
	
	
	int k=0;
	for(i=m;i<=n;i++){
		flag=1;
		for(j=2;j<=i/2;j++){
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
