#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void main(){
	pid_t child_pid, parent_pid;
	
	child_pid = fork();
	
	if (child_pid<0){
		printf("Fork Unsuccessful\n");
		exit(0);
	}
	if (child_pid==0){
		printf("[CHILD] My PID is: %d\n", getpid());
		printf("[CHILD] My parent's PID is: %d\n", getppid());
		
		printf("[CHILD] I am exitting...\n");
		exit(0);
	}
	else{
		printf("[PARENT] My PID is: %d\n", getpid());
		printf("[PARENT] My child's PID is: %d\n", child_pid);
		
		printf("[PARENT] I'm sleeping for 10 secs...\n");
		sleep(10);
		
		printf("[PARENT] My child (pid:%d) has terminated but its entry is in the process table. It's a zombie process\n", child_pid);
	}

}
