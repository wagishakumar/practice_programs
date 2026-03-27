
#include <stdio.h>
#include <math.h>

#define MAX 10

// Function to find GCD
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Function to find LCM of two numbers
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

// Function to find LCM of all periods
int find_lcm(int arr[], int n) {
    int res = arr[0];
    for (int i = 1; i < n; i++) {
        res = lcm(res, arr[i]);
    }
    return res;
}

int main() {
    int n, burst[MAX], period[MAX];
    int remaining[MAX] = {0};
    float utilization = 0;
    printf("usn:1BF24CS334\n");

    printf("Enter the number of processes:");
    scanf("%d", &n);

    printf("Enter the CPU burst times:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &burst[i]);
    }

    printf("Enter the time periods:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &period[i]);
    }

    // Calculate LCM (hyperperiod)
    int hyper = find_lcm(period, n);
    printf("LCM=%d\n\n", hyper);

    // Display task table
    printf("Rate Monotone Scheduling:\n");
    printf("ID\tBurst\tPeriod\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\n", i + 1, burst[i], period[i]);
        utilization += (float)burst[i] / period[i];
    }

    // RMS Utilization Bound
    float bound = n * (pow(2, 1.0 / n) - 1);

    printf("\n%f <= %f =>%s\n", utilization, bound,
           (utilization <= bound) ? "true" : "false");

    printf("Scheduling occurs for %d ms\n\n", hyper);

    int last = -2; // to track context switch

    // RMS Scheduling Simulation
    for (int t = 0; t < hyper; t++) {

        // Release tasks
        for (int i = 0; i < n; i++) {
            if (t % period[i] == 0) {
                remaining[i] = burst[i];
            }
        }

        int selected = -1;

        // Select highest priority (smallest period)
        for (int i = 0; i < n; i++) {
            if (remaining[i] > 0) {
                if (selected == -1 || period[i] < period[selected]) {
                    selected = i;
                }
            }
        }

        // Print only when task changes
        if (selected != last) {
            if (selected != -1)
                printf("%dms onwards: Process %d running\n", t, selected + 1);
            else
                printf("%dms onwards: CPU is idle\n", t);

            last = selected;
        }

        // Execute selected task
        if (selected != -1) {
            remaining[selected]--;
        }
    }

    return 0;
}


