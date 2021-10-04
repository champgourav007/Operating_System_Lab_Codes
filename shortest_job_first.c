#include <stdio.h>
#define MAX 10
//shortest job first
int main()
{
    int noProcess, arrivalTime[MAX], burstTime[MAX], finishTime[MAX], TurnATime[MAX], waitingTime[MAX], processID[MAX], temp1;
    int i, j, minArrival, posArrival, minBurst, posBurst, temp, temp2;
    float wtAverage, tatAverage, wtTotal = 0, tatTotal = 0;

    printf("Enter the Number of PROCESSES : ");
    scanf("%d", &noProcess);

    for (i = 0; i < noProcess; i++)
    {
        processID[i] = i + 1;
        printf("Enter the ARRIVAL TIME of %d process : ", i + 1);
        scanf("%d", &arrivalTime[i]);
        printf("Enter the BURST TIME of %d process : ", i + 1);
        scanf("%d", &burstTime[i]);
        finishTime[i] = 1;
    }
    minArrival = arrivalTime[0];
    for (i = 0; i < noProcess; i++)
    {
        if (minArrival > arrivalTime[i])
        {
            minArrival = arrivalTime[i];
            posArrival = i;
        }
    }

    temp = arrivalTime[posArrival];
    arrivalTime[posArrival] = arrivalTime[0];
    arrivalTime[0] = temp;
    temp1 = processID[posArrival];
    processID[posArrival] = processID[0];
    processID[0] = temp1;
    temp2 = burstTime[posArrival];
    burstTime[posArrival] = burstTime[0];
    burstTime[0] = temp2;

    for (i = 1; i < noProcess; i++)
    {
        minBurst = burstTime[i];
        for (j = i + 1; j < noProcess; j++)
        {
            if (minBurst > burstTime[j])
            {
                minBurst = burstTime[j];
                temp = burstTime[j];
                burstTime[j] = burstTime[i];
                burstTime[i] = temp;
                temp1 = processID[j];
                processID[j] = processID[i];
                processID[i] = temp1;
                temp2 = arrivalTime[j];
                arrivalTime[j] = arrivalTime[i];
                arrivalTime[i] = temp2;
            }
        }
    }

    finishTime[0] = arrivalTime[0] + burstTime[0];
    TurnATime[0] = finishTime[0] - arrivalTime[0];
    waitingTime[0] = finishTime[0] - arrivalTime[0];
    tatTotal += TurnATime[0];
    wtTotal += waitingTime[0];
    for (i = 1; i < noProcess; i++)
    {
        finishTime[i] = finishTime[i - 1] + burstTime[i];
        TurnATime[i] = finishTime[i] - arrivalTime[i];
        waitingTime[i] = TurnATime[i] - burstTime[i];
        tatTotal += TurnATime[i];
        wtTotal += waitingTime[i];
    }

    printf("PROCESS ID | ARRIVAL TIME | BURST TIME | FINISH TIME | WAITING TIME | TAT\n");
    printf("__________________________________________________________________________\n");
    for (i = 0; i < noProcess; i++)
    {
        printf("    %d              %d            %d           %d             %d            %d\n", processID[i], arrivalTime[i], burstTime[i], finishTime[i], waitingTime[i], TurnATime[i]);
    }

    wtAverage = wtTotal / noProcess;
    tatAverage = tatTotal / noProcess;
    printf("\n\n");
    printf("The AVERAGE TIME for WAITING TIME is          : %f\n", wtAverage);
    printf("The AVERAGE TIME for TOUR AROUND  TIME is     : %f", tatAverage);
}