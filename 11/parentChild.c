#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>


void main(){
	
	pid_t child_pid, wait_pid, parent_pid;
	
	child_pid = fork();
	
	if (child_pid<0){
		printf("Fork Failed\n");
		exit(0);
	}
	
	if (child_pid==0){
		printf("[CHILD] My PID is: %d\n", getpid());
		printf("[CHILD] My Parent's PID is: %d\n", getppid());
		
		printf("[CHILD] I am executing another program now...\n");
		execlp("pwd","pwd",NULL);
	}
	else{
		printf("[PARENT] My PID is: %d\n", getpid());
		printf("[PARENT] My Child's PID is: %d\n", child_pid);
		
		printf("[PARENT] I am waiting for child to terminate...\n");
		wait_pid = wait(NULL);
		
		printf("[PARENT] My child process (PID:%d) has terminated\n", wait_pid);
		printf("[PARENT] Even I am terminating now...\n");
	}
}
