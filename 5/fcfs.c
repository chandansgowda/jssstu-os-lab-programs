#include <stdio.h>
#include <stdlib.h>

struct process {
	int pid, at, bt, ct, tt, wt;
};

void main(){

	int n, i;
	
	printf("Enter no. of processes: ");
	scanf("%d",&n);
	
	struct process p[n];
	

	printf("PID\tAT\tBT\n");
    for(int i= 0; i<n; ++i)
        scanf("%d%d%d", &p[i].pid, &p[i].at, &p[i].bt);
	
	
	int* isCompleted = (int*)calloc(n,sizeof(int));
	
	int min, index, curtime=0, completed=0, tottt=0, totwt=0, j=0, prev=-2, len=n, pid[20], ct[20];
	
	while(completed!=n){
		index=-1; min=9999;
		for(i=0;i<n;i++){
			if (p[i].at<=curtime && !isCompleted[i] && min>p[i].at){
				index=i;
				min=p[i].at;
			}
		}
		
		if (index!=-1){
			p[index].ct = p[index].bt + curtime;
			p[index].tt = p[index].ct - p[index].at;
			p[index].wt = p[index].tt - p[index].bt;
			
			tottt+=p[index].tt;
			totwt+=p[index].wt;
			
			ct[j]=p[index].ct;
			pid[j]=p[index].pid;
			j++;
			
			curtime = p[index].ct;
			isCompleted[index]=1;
			completed++;
		}
		else{
			if (prev=curtime-1){
				ct[j-1]++;
				prev=curtime;
			}
			else{
				pid[j]=-1;
				ct[j]=curtime+1;
				j++;
				len++;
				prev=curtime;
			}
			curtime++;
		}
	}
	
	printf("\nPID\tAT\tBT\tCT\tTT\tWT\n");
    for(int i = 0; i<n; ++i)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tt, p[i].wt);
        
    printf("\nGhant Chart \n");
    for(i=0;i<len;i++)
    	printf("-------");
    printf("\n");
    for(i=0;i<len;i++){
    	if(pid[i]!=-1)
    		printf("  P%d  |",pid[i]);
    	else
    		printf(" IDLE |");
    }
	printf("\n");
	for(i=0;i<len;i++)
    	printf("-------");
    printf("\n");
    printf("0     ");
    for(int i = 0; i<len; ++i)
        printf("%d      ", ct[i]);
        
        
   printf("\n\nAvg turn around time >> %.2f\n", (float)tottt/n);
   printf("Avg waiting time >> %.2f\n", (float)totwt/n);
}















