
#include <stdio.h>

int main() {
    int n;
    printf("1BF24CS334\n");

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], pr[n];
    int ct[n], tat[n], wt[n], rt[n];

    int current_time = 0, completed = 0;

    for(int i = 0; i < n; i++) {
        printf("\nEnter Process ID: ");
        scanf("%d", &pid[i]);

        printf("Enter Arrival Time: ");
        scanf("%d", &at[i]);

        printf("Enter Burst Time: ");
        scanf("%d", &bt[i]);

        printf("Enter Priority (smaller number = higher priority): ");
        scanf("%d", &pr[i]);

        rt[i] = bt[i]; // remaining time initially = burst time
    }

    while(completed < n) {
        int highest_priority = 9999;
        int selected = -1;

        for(int i = 0; i < n; i++) {
            if(at[i] <= current_time && rt[i] > 0) {
                if(pr[i] < highest_priority) {
                    highest_priority = pr[i];
                    selected = i;
                }
            }
        }

        if(selected == -1) {
            current_time++;
        }
        else {
            rt[selected]--;   // execute for 1 unit
            current_time++;

            if(rt[selected] == 0) {
                completed++;

                ct[selected] = current_time;
                tat[selected] = ct[selected] - at[selected];
                wt[selected] = tat[selected] - bt[selected];
            }
        }
    }

    float avg_wt = 0, avg_tat = 0;

    printf("\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n");

    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        pid[i], at[i], bt[i], pr[i], ct[i], tat[i], wt[i]);

        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    avg_wt /= n;
    avg_tat /= n;

    printf("\nAverage Waiting Time = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f", avg_tat);

    return 0;
}
