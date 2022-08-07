#include <stdio.h>
#include <stdlib.h>

struct process{
	int pid, at, bt, wt, tt, ct, pri;
};

void main(){
	int n,i;
	printf("No. of Processes>> ");
	scanf("%d",&n);
	struct process p[n];
	
	printf("\nPID\tAT\tBT\tPRI\n");
	for(i=0;i<n;i++)
		scanf("%d\t%d\t%d\t%d", &p[i].pid, &p[i].at, &p[i].bt, &p[i].pri);
		
	int* isCompleted = (int*) calloc(n,sizeof(int));
	
	int max, index, curtime=0, completed=0, j=0, prev=-2, len=n, tottt=0, totwt=0, pid[20], ct[20];
	
	while(completed!=n){
		index=-1; max=-1;
		for(i=0;i<n;i++){
			if (p[i].at<=curtime && !isCompleted[i]){
				if (max<p[i].pri){
				index = i;
				max = p[i].pri;
				}
			
				if (p[i].pri==max){
					if (p[i].at<p[index].at){
						index = i;
						max = p[i].pri;
					}
				}
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
			
			completed++;
			isCompleted[index]=1;
			curtime=p[index].ct;
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
	printf("\nPID\tAT\tBT\tPRI\tCT\tTT\tWT\n");
	for(i=0;i<n;i++){
		printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].pri, p[i].ct, p[i].tt, p[i].wt);
	}
	
	printf("\nGhant Chart\n");
	for(i=0;i<n;i++)
		printf("-------");
	printf("\n");
	for(i=0;i<n;i++){
		if (pid[i]!=-1)
			printf("  P%d  |", pid[i]);
		else
			printf(" IDLE |");
	}
	printf("\n");
	for(i=0;i<n;i++)
		printf("-------");
	printf("\n");
	printf("0      ");
	for(i=0;i<n;i++)
		printf("%d      ", ct[i]);
	printf("\n\n");
	
	printf("Avg. Turnaround Time: %.2f\n", (float)tottt/n);
	printf("Avg. Waiting Time: %.2f\n", (float)totwt/n);
}











