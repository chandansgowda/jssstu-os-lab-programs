#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void main(){
	pid_t child_pid, parent_pid;
	
	child_pid=fork();
	
	if (child_pid<0){
		printf("Fork Unsucessful\n");
		exit(0);
	}
	if (child_pid==0){
		printf("[CHILD] My PID is %d\n", getpid());
		printf("[CHILD] My parent's PID is %d\n", getppid());
		
		printf("[CHILD] I am sleeping for 10 secs...\n");
		sleep(10);
		
		printf("[CHILD] My Parent Process has terminated. I am an orphan process adopted by Init Process(pid:%d)\n",getppid());
	}
	else{
		printf("[PARENT] My PID is %d\n", getpid());
		printf("[PARENT] My child's PID is %d\n", child_pid);
		
		printf("[PARENT] I am exitting...\n");
		exit(0);
	}
}
