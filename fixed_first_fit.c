#include<stdio.h>
#define MAX 10
//first fit
int main()
{
    int no_process,no_partition,i,j,tempProcess,externalFragmentation=0,internalFragmentation=0;
    int process[MAX],partition[MAX],tempPartition[MAX],remPartition[MAX];

    printf("Enter the Number of Partition : ");
    scanf("%d",&no_partition);
    for(i=0;i<no_partition;i++)
    {
        printf("Enter the %d partition Size : ",i+1);
        scanf("%d",&partition[i]);
        tempPartition[i] = partition[i];
    }

    printf("Enter the Number of process : ");
    scanf("%d",&no_process);
    for(i=0;i<no_process;i++)
    {
        printf("Enter the %d process Size : ",i+1);
        scanf("%d",&process[i]);
    }

    for(i=0;i<no_process;i++)
    {
        tempProcess = process[i];
        for(j=0;j<no_partition;j++)
        {
            if(tempPartition[j] >= tempProcess && tempPartition[j] != 0)
            {
                partition[j] = i+1;
                remPartition[j] = tempPartition[j] - tempProcess;
                tempPartition[j] = 0;
                process[i] = 0;
                break;
            }
        }
    }
    for(i=0;i<no_partition;i++)
    {
        if(partition[i] == tempPartition[i])
        {
            remPartition[i] = 0;
            partition[i] = 0;
            continue;
        }
        internalFragmentation += remPartition[i];
    }
    printf("\n----------------------------------------------------------------------------\n");
    for(j=0;j<no_partition;j++)
        printf("Partition %d contains %d Process and Internal Fragmentation is %d\n",j+1,partition[j],remPartition[j]);
    

    for(i=0;i<no_partition;i++)
    {
        if(tempPartition[i] != 0)
        {
            externalFragmentation += tempPartition[i];
        }
    }
    printf("\n----------------------------------------------------------------------------\n");
    printf("Total External Fragmentation is : %d\n",externalFragmentation);
    printf("Total Internal Fragmentation is : %d\n",internalFragmentation);
    printf("Total Compaction is : %d",internalFragmentation+externalFragmentation);

}