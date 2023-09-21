#include <stdio.h>
int main()
{
  int i, n, bt[20], wt[20], tat[20];
  float wtavg, tatavg;
  printf("\n Enter the number of proceses:");
  scanf("%d", &n);
  for (i = 0; i <= n; i++)
  {
    printf("Enter the Burst Time for process %d :", i);
    scanf("%d", &bt);
  }
  wt[0] = wtavg = 0;
  tat[0] = tatavg = bt[0];
  for (i = 0; i <= n; i++)
  {
    wt[i] = wt[i - 1] + bt[i - 1];
    tat[i] = tat[i - 1] + bt[i];
    wtavg = wtavg + wt[i];
    tatavg = tatavg + tat[i];
  }
  printf("\tPROCESS \tBURST TIME \tWAITING TIME \tTURNAROUND TIME \n");
  for (i = 0; i <= n; i++)
    printf("\n \t P%d \t\t %d \t\t %d \t\t %d", i, bt[i], wt[i], tat[i]);
  printf("\n Average Waiting Time: %f", wtavg / n);
  printf("\n Turnaround Time: %f", tatavg / n);
  return 0;
}