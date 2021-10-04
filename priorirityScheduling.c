#include <stdio.h>
#include <stdlib.h>
#define MAX 10
//priority scheduling
//find the minimum value in the array
int minimum(int a[], int n)
{
    int min = 0, pos;
    for (int i = 0; i < n; i++)
    {
        if (min > a[i])
        {
            min = a[i];
            pos = i;
        }
    }
    return pos;
}
//find maximum in the array
int maximum(int a[], int n)
{
    int max = 0, pos;
    for (int i = 0; i < n; i++)
    {
        if (max < a[i])
        {
            max = a[i];
            pos = i;
        }
    }
    return pos;
}



int main()
{
    int noProcess, arrivalTime[MAX], burstTime[MAX], priority[MAX],tempPriority[MAX], finishTime[MAX], TurnATime[MAX], waitingTime[MAX], processID[MAX], temp1;
    int i, j, minArrival, totArrival, totBurst, maxPriority;
    float wtAverage, tatAverage, wtTotal = 0, tatTotal = 0;

    printf("Enter the Number of PROCESSES : ");
    scanf("%d", &noProcess);

    for (i = 0; i < noProcess; i++)
    {
        //taking inputs of the arrival, burst and pririoty
        processID[i] = i + 1;
        printf("Enter the ARRIVAL TIME of %d process : ", i + 1);
        scanf("%d", &arrivalTime[i]);
        printf("Enter the BURST TIME of %d process : ", i + 1);
        scanf("%d", &burstTime[i]);
        printf("Enter the PRIORITY of %d process : ", i + 1);
        scanf("%d", &tempPriority[i]);
        priority[i] = tempPriority[i];
    }
    minArrival = minimum(arrivalTime, noProcess);
    priority[minArrival] = 0;
    finishTime[minArrival] = arrivalTime[minArrival] + burstTime[minArrival];
    totArrival = burstTime[minArrival];
    totBurst = finishTime[minArrival];
    int count = 1;
    while (count < noProcess)
    {
        for (i = 0; i < noProcess; i++)
        {
            if (priority[i] != 0 && totArrival >= arrivalTime[i])
            {
                if(totArrival > noProcess)
                {
                    maxPriority = maximum(priority,noProcess);
                }
                else
                    maxPriority = maximum(priority,totArrival);
                finishTime[maxPriority] = totBurst + burstTime[maxPriority];
                priority[maxPriority] = 0;
                totBurst = finishTime[maxPriority];
                totArrival = totBurst;
            }
        }
        count++;
    }

    for(i=0;i<noProcess;i++)
    {
        TurnATime[i] = finishTime[i] - arrivalTime[i];
        tatTotal += TurnATime[i];
        waitingTime[i] = TurnATime[i] - burstTime[i];
        wtTotal += waitingTime[i];
    }





    printf("PID\tP\tAT\tBT\tFT\tWT\tTAT\n");
    printf("____________________________________________________________________________\n");
    for (i = 0; i < noProcess; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", processID[i], tempPriority[i], arrivalTime[i], burstTime[i], finishTime[i], waitingTime[i], TurnATime[i]);
    }

    wtAverage = wtTotal / noProcess;
    tatAverage = tatTotal / noProcess;
    printf("\n\n");
    printf("The AVERAGE TIME for WAITING TIME is          : %f\n", wtAverage);
    printf("The AVERAGE TIME for TURN AROUND  TIME is     : %f", tatAverage);
}