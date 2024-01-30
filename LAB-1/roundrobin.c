// Round Robin Algorithm
#include <stdio.h>

int main()
{

    int cnt, j, n, t, remain, flag = 0, tq;
    int wt = 0, tat = 0, at[10], bt[10], rt[10];
    printf("Enter number of Process : ");
    scanf("%d", &n);
    remain = n;
    for (cnt = 0; cnt < n; cnt++)
    {
        printf("Enter Arrival Time and Burst Time for Process-%d :", cnt + 1);
        scanf("%d", &at[cnt]);
        scanf("%d", &bt[cnt]);
        rt[cnt] = bt[cnt];
    }
    printf("Enter Time Quantum:\t");
    scanf("%d", &tq);

    printf("\n------------------------------------------------------------");
    printf("\nProcess  \t Turnaround Time\t Waiting Time");
    printf("\n------------------------------------------------------------\n");
    for (t = 0, cnt = 0; remain != 0;)
    {
        if (rt[cnt] <= tq && rt[cnt] > 0)
        {
            t += rt[cnt];
            rt[cnt] = 0;
            flag = 1;
        }
        else if (rt[cnt] > 0)
        {
            rt[cnt] -= tq;
            t += tq;
        }
        if (rt[cnt] == 0 && flag == 1)
        {
            remain--;
            printf("P[%d]\t\t\t %d\t\t\t %d\n", cnt + 1, t - at[cnt], t - at[cnt] - bt[cnt]);
            wt += t - at[cnt] - bt[cnt];
            tat += t - at[cnt];
            flag = 0;
        }
        if (cnt == n - 1)
            cnt = 0;
        else if (at[cnt + 1] <= t)
            cnt++;
        else
            cnt = 0;
    }
    printf("\n------------------------------------------------------------\n");
    printf("\nAverage Waiting Time= %f\n", wt * 1.0 / n);
    printf("Avg Turnaround Time = %f\n", tat * 1.0 / n);

    return 0;
}
