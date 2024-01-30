// C Program to Implement FCFS Algorithm.

#include <stdio.h>

int main()
{
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n], burstTime[n], waitingTime[n], turn[n];

    printf("Enter the burstTime time of each process:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &burstTime[i]);
        processes[i] = i + 1;
    }

    int totalWaitingTime = 0, totalTurnaroundTime = 0;

    waitingTime[0] = 0;

    for (int i = 1; i < n; i++)
    {
        waitingTime[i] = burstTime[i - 1] + waitingTime[i - 1];
        totalWaitingTime += waitingTime[i];
    }

    for (int i = 0; i < n; i++)
    {
        turn[i] = burstTime[i] + waitingTime[i];
        totalTurnaroundTime += turn[i];
    }

    // Printing the Tasks
    printf("\n------------------------------------------------------------------");
    printf("\nProcess \t Burst Time \t Waiting Time \t Turn Around Time");
    printf("\n------------------------------------------------------------------");
    for (int i = 0; i < n; i++)
    {
        printf("\nP[%d] \t\t %d \t\t %d \t\t %d", i + 1, burstTime[i], waitingTime[i], turn[i]);
    }

    printf("\n\nTotal Waiting time = %d\n", totalWaitingTime);
    printf("Total turnaround time = %d\n", totalTurnaroundTime);
    printf("Average Waiting time = %.2f\n", (float)totalWaitingTime / n);

    return 0;
}