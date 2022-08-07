#include <stdio.h>
#include <stdlib.h>

struct process{
	int pid,at,bt,tt,wt,ct;
};

void main(){
	int n,i;
	printf("No. of processes: ");
	scanf("%d",&n);
	struct process p[n];
	int burstRemain[n];
	
	printf("\nPID\tAT\tBT\n");
	for(i=0;i<n;i++){
		scanf("%d\t%d\t%d", &p[i].pid, &p[i].at, &p[i].bt);
		burstRemain[i] = p[i].bt;
	}
	
	int* isCompleted = (int*)calloc(n,sizeof(int));
	
	int min, index, curtime=0, completed=0, j=0, len=0, prev=-2, ct[20], pid[20], tottt=0, totwt=0;
	
	while(completed<n){
		index=-1; min=9999;
		for(i=0;i<n;i++){
			if (p[i].at<=curtime && !isCompleted[i]){
				if (min>burstRemain[i]){
					index = i;
					min = burstRemain[i];
				}
				
				if (min==burstRemain[i]){
					if (p[i].at<p[index].at){
						index = i;
						min = burstRemain[i];
					}
				}
			}
		}
		
		if (index!=-1){
			if (prev==curtime-1 && pid[j-1]==p[index].pid){
				ct[j-1]++;
				prev = curtime;
			}
			else{
				ct[j]= curtime+1;
				pid[j]=p[index].pid;
				j++;
				len++;
				prev=curtime;
			}
			curtime++;
			burstRemain[index]--;
			
			if (burstRemain[index]==0){
				p[index].ct = curtime;
				p[index].tt = p[index].ct - p[index].at;
				p[index].wt = p[index].tt - p[index].bt;
				
				tottt+=p[index].tt;
				totwt+=p[index].wt;
				
				completed++;
				isCompleted[index]=1;
			}
		}
		else{
			if (prev==curtime-1 && pid[j-1]==-1){
				ct[j-1]++;
				prev=curtime;
			}
			else{
				ct[j]=curtime+1;
				pid[j]=-1;
				j++;
				len++;
				prev=curtime;
			}
			curtime++;
		}
	}
	
	printf("\nPID\tAT\tBT\tCT\tTT\tWT\n");
	for(i=0;i<n;i++){
		printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt ,p[i].ct, p[i].tt, p[i].wt);
	}
	
	printf("\nGhant Chart\n");
	for(i=0;i<len;i++)
		printf("-------");
	printf("\n");
	for(i=0;i<len;i++){
		if (pid[i]!=-1)
			printf("  P%d  |", pid[i]);
		else
			printf(" IDLE |");
	}
	printf("\n");
	for(i=0;i<len;i++)
		printf("-------");
	printf("\n");
	printf("0     ");
	for(i=0;i<len;i++)
		printf("%d      ", ct[i]);
	printf("\n\n");
	
	printf("Avg. Turnaround Time: %.2f\n", (float)tottt/n);
	printf("Avg. Waiting Time: %.2f\n", (float)totwt/n);
}








