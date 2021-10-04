#include <stdio.h>
#define MAX 20
int main()
{
    int noProcess, totResources, maxRes[MAX], allRes[MAX], tempremRes[MAX], remRes[MAX], totAll = 0, remAll, maximumRes;
    int res[MAX];
    printf("Enter the number of process : ");
    scanf("%d", &noProcess);

    printf("Enter the Maximum Number of resources : ");
    scanf("%d", &maximumRes);
    for (int i = 0; i < noProcess; i++)
    {
        printf("Enter the Process %d Max Required Resouces : ", i + 1);
        scanf("%d", &maxRes[i]);

        printf("Enter the Process %d Allocated Resouces : ", i + 1);
        scanf("%d", &allRes[i]);

        tempremRes[i] = maxRes[i] - allRes[i];
        remRes[i] = maxRes[i] - allRes[i];
        totAll += allRes[i];
    }

    remAll = maximumRes - totAll;
    int k = 0;
    for (int j = 0; j < noProcess; j++)
    {
        for (int i = 0; i < noProcess; i++)
        {
            if (remAll >= remRes[i] && remRes[i] != -1)
            {
                res[k++] = i + 1;
                remAll -= remRes[i];
                remRes[i] = -1;
                remAll += maxRes[i];
            }
        }
    }
    printf("\n--------------------------------------------------\n");
    printf("Entered Constraints Are\n");
    printf("--------------------------------------------------\n");
    printf("PROCESS NO|\tMAX RES|\tALLOCATED RES|\tREMAINING RES\t\n");
    for (int i = 0; i < noProcess; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\n", i + 1, maxRes[i], allRes[i], tempremRes[i]);
    }

    if (noProcess == k)
    {
        printf("Process is in SAFE STATE!!!\n");
        printf("The Process is executed in : ");
        for (int i = 0; i < k; i++)
        {
            printf(" P%d ", res[i]);
        }
    }
    else
    {
        printf("Process is in Deadlock!!!");
    }
}