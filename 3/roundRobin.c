/*INPUT:
PID	AT	BT
1 0 5
2 0 4
3 1 2
4 3 1
Time Quantum: 2
*/
//Not working for some test cases

#include <stdio.h>
#include <stdlib.h>

struct process{
	int pid,at,bt,tt,wt,ct;
};

void main(){
	int n,i,quant;
	printf("No. of processes: ");
	scanf("%d",&n);
	struct process p[n];
	int br[n];
	
	printf("\nPID\tAT\tBT\n");
	for(i=0;i<n;i++){
		scanf("%d\t%d\t%d", &p[i].pid, &p[i].at, &p[i].bt);
		br[i] = p[i].bt;
	}
	
	printf("Time Quantum: ");
	scanf("%d",&quant);
	
	int ct=0, counter=n, tottt=0, totwt=0;
	
	int cta[40], pid[40], j=0, len=0; //for ghant chart
	
	for(i=0;counter!=0;){
		if (br[i] <= quant && br[i]>0){
			ct = ct + br[i];
			br[i] = 0;
			counter--;
			
			p[i].ct = ct;
			p[i].tt = p[i].ct - p[i].at;
			p[i].wt = p[i].tt - p[i].bt;
			
			tottt+=p[i].tt;
			totwt+=p[i].wt;
			
			if (pid[j-1]==p[i].pid){
				cta[j-1]=ct;
			}
			else{
				cta[j]=ct;
				pid[j]=p[i].pid;
				j++;
				len++;
			}
		}
		else if (br[i] > 0){
			br[i] = br[i] - quant;
			ct = ct+quant;
			cta[j]=ct;
			pid[j]=p[i].pid;
			j++;
			len++;
		}
		if (i == n-1){
			i = 0;
		}
		else if (p[i+1].at <= ct){
			i++;
		}
		else{
			i = 0;
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
		printf("%d      ", cta[i]);
	printf("\n\n");
	
	
	printf("Avg. Turnaround Time: %.2f\n", (float)tottt/n);
	printf("Avg. Waiting Time: %.2f\n", (float)totwt/n);
}
