//Works for all test cases

#include<stdio.h>
#include<stdlib.h>

struct pcb{
    int pid, at, bt, ct, tt, wt;
};
int n;
int Q[20], f = -1, r = -1;

void enq(int index){
    if ( f == -1)
        ++f;
    r = (r+1)%n;
    Q[r] = index;
}

int deq(){
    if (f==r){
        int a = f;
        f = r = -1;
        return Q[a];
    }
    else{
        int a = f;
        f = (f+1)%n;
        return Q[a];
    }
}

int isEmpty(){
    if ( f==r && r == -1)
        return 1;
    else
        return 0;
}

void main(){
    printf("Enter num. of processes >> ");
    scanf("%d", &n);

    struct pcb p[n];
    int bt[n], qt;
    printf("PID  AT  BT\n");
    for(int i = 0; i<n; ++i){
        scanf("%d%d%d", &p[i].pid, &p[i].at, &p[i].bt);
        bt[i] = p[i].bt;
    }
    printf("Enter time quantum >> ");
    scanf("%d", &qt);

    // Initializling inqueue array to 0
    int * inqueue = (int *)calloc(sizeof(int), n);

    int completed = 0, curtime = 0, index, tottt = 0, totwt = 0, pid[20], ct[20], len = 0, j = 0;

    // Sorting based on arrival time
    for(int i = 0; i<n-1; ++i){
        for(int j = 0; j<n-i-1; ++j){
            if ( p[j].at > p[j+1].at ){
                struct pcb temp = p[j+1];
                p[j+1] = p[j];
                p[j] = temp;

                int t = bt[j+1];
                bt[j+1] = bt[j];
                bt[j] = t;
            }
        }
    }

    if ( p[0].at != 0 ){
        pid[j] = -1;
        ct[j] = p[0].at;
        ++j;
        ++len;
    }

    // Putting first arrived process in queue
    enq(0);
    inqueue[0] = 1;

    while ( completed != n ){
        if ( !isEmpty() ){
            index = deq();
        
            if ( p[index].bt > qt ){
                p[index].bt -= qt;
                curtime += qt;
            }
            else{
                curtime += p[index].bt;
                p[index].bt = 0;

                p[index].ct = curtime;
                p[index].tt = p[index].ct - p[index].at;
                p[index].wt = p[index].tt - bt[index];

                tottt += p[index].tt;
                totwt += p[index].wt;

                ++completed;
            }
        }
        else{
            ++curtime;
        }

        if ( p[index].pid == pid[j - 1]){
            ct[j-1] = curtime;
        }
        else{
            ct[j] = curtime;
            pid[j] = p[index].pid;
            ++j;
            ++len;
        }
        // Selecting process which is not in queue and arrived at curtime and putting it to ready queue
        for(int i= 0; i<n && p[i].at <= curtime; ++i){
            if ( p[i].bt == 0 || p[i].pid == p[index].pid || inqueue[i] )
                continue;
            enq(i);
            inqueue[i] = 1;
        }
        // If bt remain of current process , put it to last in queue
        if ( p[index].bt > 0 )
            enq(index);
    }

    printf("\nPID\tAT\tBT\tCT\tTT\tWT\n");
    for(int i = 0; i<n; ++i)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, bt[i], p[i].ct, p[i].tt, p[i].wt);

    printf("\n\nGantt chart >> \n");
    for(int i=0; i<len; ++i)
        printf("-------");
    printf("\n");
    for(int i = 0; i<len; ++i){
        if ( pid[i] != -1 )
            printf("  P%d  |", pid[i]);
        else
            printf(" IDLE |");
    }
    printf("\n");
    for(int i =0; i<len; ++i)
        printf("-------");
    printf("\n0     ");
    for(int i = 0; i<len; ++i){
        if ( ct[i] < 10 )
            printf("%d      ", ct[i]);
        else    
            printf("%d     ", ct[i]);
    }

    printf("\n\nAvg turn around time >> %.2f\n", (float)tottt/n);
    printf("Avg waiting time >> %.2f\n", (float)totwt/n);
}
