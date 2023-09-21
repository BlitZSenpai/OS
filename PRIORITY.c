#include <stdio.h>
int main()
{
  int p[20], bt[20], wt[20], tat[20], pri[20], i, n, k, temp;
  float avgwt, avgtat;
  printf("\n Enter the number of processes:");
  scanf("d", &n);
  for (i = 0; i < n; i++)
  {
    p[i] = i;
    printf("Enter the Burst Time and Priority of processes: %d", i);
    scanf("%d %d", &bt[i], &pri[i]);
  }
  for (i = 0; i < n; i++)
    for (k = i + 1; k < n; k++)
      if (pri[i] > pri[k])
      {
        temp = p[i];
        p[i] = p[k];
        p[k] = temp;
        temp = bt[i];
        bt[i] = bt[k];
        bt[k] = temp;
        temp = pri[i];
        pri[i] = pri[k];
        pri[k] = temp;
      }
  wt[0] = avgwt = 0;
  tat[0] = avgtat = bt[0];
  for (i = 0; i < n; i++)
  {
    wt[i] = wt[i - 1] + bt[i - 1];
    tat[i] = tat[i - 1] + bt[i];
    avgwt = avgwt + wt[i];
    avgtat = avgtat + tat[i];
  }
  printf("\n \tPROCESS \tPRIORITY \tBURST TIME \tWAITING TIME \tTURNAROUND TIME");
  for (i = 0; i < n; i++)
    printf("\n\t P%d \t\t %d \t\t %d \t\t %d \t\t %d", p[i], pri[i], bt[i], wt[i], tat[i]);
  printf("\n Average Waiting Time: %f", avgwt / n);
  printf("\n Average Turnaround Time: %f", avgtat / n);
}