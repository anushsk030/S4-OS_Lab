#include<stdio.h>

void main() {
    int n, quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    int bt[n], rem_bt[n], wt[n], tat[n];
    int tot_wt = 0, tot_tat = 0;

    for (int i = 0; i < n; i++) {
        printf("Enter the burst time of process %d: ", i);
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i]; // Copy burst times into remaining times array
    }

    int t = 0; // Current time
    while (1) {
        int done = 1; // To check if all processes are done

        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = 0; // There is a pending process

                if (rem_bt[i] > quantum) {
                    t += quantum;
                    rem_bt[i] -= quantum;
                } else {
                    // Last cycle for this process
                    t += rem_bt[i];
                    wt[i] = t - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }

        // If all processes are done
        if (done == 1) {
            break;
        }
    }

    // Calculate Turnaround Time and total wait time
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        tot_wt += wt[i];
        tot_tat += tat[i];
    }

    // Calculating average times
    float avg_wt = (float)tot_wt / n;
    float avg_tat = (float)tot_tat / n;

    printf("\nProcess\tBurst Time\tWaiting Time\tTurn-Around Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", i, bt[i], wt[i], tat[i]);
    }

    printf("Total Waiting Time: %d\nAverage Waiting Time: %f\n", tot_wt, avg_wt);
    printf("Total Turn-Around Time: %d\nAverage Turn-Around Time: %f\n", tot_tat, avg_tat);
}
