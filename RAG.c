#include<stdio.h>
#define MAX 10

int check(int arr[], int l)
{
    int i;
    printf("-------------------------------------------------------\n");
    printf("WFG:\t");
    for(i=0;i<l;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    if(arr[0] == arr[l-1])
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int no_process,no_res,i,j,pos,flag_w = 0,flag_p = 0,arr[MAX],l=0;
    printf("Enter the number of the Process : ");
    scanf("%d",&no_process);

    printf("Enter the number of Resources : ");
    scanf("%d",&no_res);

    int all_matrix[no_process][no_res],wait_matrix[no_process][no_res];

    printf("Enter 1 show the which process holds the resource else Enter 0 : \n");
    for(i=0;i<no_process;i++)
    {
        for(j=0;j<no_res;j++)
        {
            printf("Is Process %d is holding %d resource : ",i+1,j+1);
            scanf("%d",&all_matrix[i][j]);
        }
    }

    printf("Enter 1 show the which process is waiting for the resource else Enter 0 : \n");
    for(i=0;i<no_process;i++)
    {
        for(j=0;j<no_res;j++)
        {
            printf("Is Process %d is waiting for %d resource : ",i+1,j+1);
            scanf("%d",&wait_matrix[i][j]);
        }
    }
    int first,k=0,flag = 0;
    for(i=0;i<no_process;i++)
    {
        for(j=0;j<no_res;j++)
        {
            if(wait_matrix[i][j] == 1)
            {
                first = i;
                pos = j;
                flag_w = 1;
                arr[l++] = i;
                break;
            }
        }
        if(flag_w == 1)
        {
            for(k=0;k<no_process;k++)
            {
                if(all_matrix[k][pos] == 1)
                {
                    if(arr[0] == k)
                    {
                        arr[l++] = k;
                        flag = 1;
                        break;
                    }
                    arr[l++] = k;
                    break;
                }
                if (flag == 1)
                {
                    break;
                }
                
            }
            if (flag == 1)
            {
                break;
            }
            
            flag_w = 0;
        }
        if (flag == 1)
        {
            break;
        }
        
    }
    
    printf("-------------------------------------------------------\n");
    printf("--------------------ALLOCATION MATRIX------------------\n");
    printf("\tR1\tR2\tR3\n");
    for(i=0;i<no_process;i++)
    {
        printf("P%d:\t",i+1);
        for(j=0;j<no_process;j++)
        {
            printf("%d\t",all_matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("-----------------------WAIT MATRIX--------------------\n");
    printf("\tR1\tR2\tR3\n");
    for(i=0;i<no_process;i++)
    {
        printf("P%d:\t",i+1);
        for(j=0;j<no_process;j++)
        {
            printf("%d\t",all_matrix[i][j]);
        }
        printf("\n");
    }
    printf("-------------------------------------------------------\n");
    
    int c = check(arr,l);
    if(c == 1)
    {
        printf("System is in DEADLOCK!!!!!!\n");
    }
    else
    {
        printf("System is not in DEADLOCK.\n");
    }
    
}