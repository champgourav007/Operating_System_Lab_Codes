#include<stdio.h>
#define MAX 10

int main()
{
    int ran, arr[MAX], i;

    printf("Enter the Number of Process : ");
    scanf("%d",&ran);

    for(i=0;i<ran;i++)
    {
        printf("Enter the %d Data into the Array : ",i+1);
        scanf("%d",&arr[i]);
    }

    for(i=0;i<ran;i++)
    {
        printf("Data in %d index is : %d and its Addresss is : %d\n",i+1,arr[i],&arr[i]);
    }
}