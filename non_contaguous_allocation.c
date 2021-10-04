#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}n;
n* start = NULL;
n* ptr;
n* temp;

void create()
{
    int ch, data;
    do
    {
        printf("Enter the data : ");
        scanf("%d",&data);
        temp = (n*)malloc(sizeof(n));
        temp->data = data;
        if(start == NULL)
        {
            start = temp;
            ptr = temp;
        }
        else
        {
            ptr->next = temp;
            ptr = temp;
        }
        ptr->next = NULL;
        printf("PRESS 1 TO ENTER THE DATA ELSE PRESS 0 : ");
        scanf("%d",&ch);

    } while (ch != 0);

    
    
}

void print_ll()
{
    ptr = start;
    printf("\n----------------------------------------------------------\n");
    while(ptr != NULL)
    {
        printf("Data into the Linked List is : %d\n",ptr->data);
        ptr = ptr->next;
    }
    printf("\n----------------------------------------------------------\n");
}

int main()
{
    create();
    print_ll();
}