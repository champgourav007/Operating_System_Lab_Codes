printf("PROCESS ID | PRIORITY | ARRIVAL TIME | BURST TIME | FINISH TIME | WAITING TIME | TAT\n");
    printf("__________________________________________________________________________\n");
    for (i = 0; i < noProcess; i++)
    {
        printf("    %d              %d            %d           %d             %d            %d            %d\n", processID[i], priority[i], arrivalTime[i], burstTime[i], finishTime[i], waitingTime[i], TurnATime[i]);
    }

    wtAverage = wtTotal / noProcess;
    tatAverage = tatTotal / noProcess;
    printf("\n\n");
    printf("The AVERAGE TIME for WAITING TIME is          : %f\n", wtAverage);
    printf("The AVERAGE TIME for TOUR AROUND  TIME is     : %f", tatAverage);