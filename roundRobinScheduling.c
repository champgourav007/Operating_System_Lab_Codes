#include <stdio.h>
#include <stdlib.h>
#define MAX 10
//round robin
int main()
{
    int noProcess, arrivalTime[MAX], burstTime[MAX], finishTime[MAX], TurnATime[MAX], waitingTime[MAX], processID[MAX], tempArrivaltime[MAX], remBurst[MAX];
    int i, j, minArrival, totArrival, totBurst = 0, tq, temp;
    float wtAverage, tatAverage, wtTotal = 0, tatTotal = 0;

    printf("Enter the Number of PROCESSES : ");
    scanf("%d", &noProcess);
    printf("Enter the Time Quanta : ");
    scanf("%d", &tq);
    for (i = 0; i < noProcess; i++)
    {
        processID[i] = i + 1;
        printf("Enter the ARRIVAL TIME of %d process : ", i + 1);
        scanf("%d", &arrivalTime[i]);
        tempArrivaltime[i] = arrivalTime[i];
        printf("Enter the BURST TIME of %d process : ", i + 1);
        scanf("%d", &burstTime[i]);
        remBurst[i] = burstTime[i];
    }
    // This program is only for sorted arrival time
    while (1)
    {

        int done = 1;
        for (i = 0; i < noProcess; i++)
        {
            if (remBurst[i] > 0)
            {
                done = 0;
                if (remBurst[i] > tq)
                {
                    totBurst += tq;
                    remBurst[i] -= tq;
                }
                else
                {
                    totBurst += remBurst[i];
                    finishTime[i] = totBurst;
                    remBurst[i] = 0;
                }
            }
        }
        if (done == 1)
        {
            break;
        }
    }

    for (i = 0; i < noProcess; i++)
    {
        TurnATime[i] = finishTime[i] - arrivalTime[i];
        waitingTime[i] = TurnATime[i] - burstTime[i];
        tatTotal += TurnATime[i];
        wtTotal += waitingTime[i];
    }

    printf("PROCESS ID\tTIME QUANTA\tARRIVAL TIME\tBURST TIME\tFINISH TIME\tWAITING TIME\tTAT\n");
    printf("______________________________________________________________________________________________\n");
    for (i = 0; i < noProcess; i++)
    {
        printf("\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t%d\n", processID[i], tq, arrivalTime[i], burstTime[i], finishTime[i], waitingTime[i], TurnATime[i]);
    }

    wtAverage = wtTotal / noProcess;
    tatAverage = tatTotal / noProcess;
    printf("\n\n");
    printf("The AVERAGE TIME for WAITING TIME is          : %f\n", wtAverage);
    printf("The AVERAGE TIME for TOUR AROUND  TIME is     : %f", tatAverage);
}