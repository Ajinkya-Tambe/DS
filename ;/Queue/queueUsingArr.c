#include<stdio.h>
#include<conio.h>

#define MAX_SIZE 100
int q[MAX_SIZE];
int front = -1; rear = -1;
int size;

void enqueue()
{
    int data;
    if(rear >= size-1)
        printf("\nOverflow!");
    else
    {
        if(front == -1)
            front = 0;
        printf("\nEnter the element: ");
        scanf("%d", &data);
        rear++;
        q[rear] = data;
    }
}

void dequeue()
{
    if(front == -1)
        printf("\nUnderflow!");
    else
    {
        printf("\nDequeued: %d", q[front]);
        front++;
    }
}

void display()
{
    int i;
    if(front == -1)
        printf("\nQueue is empty!");
    else
    {
        printf("\nElements: ");
        for(i=front; i<=rear; i++)
            printf("%d ", q[i]);
        front++;
    }
}

void main()
{
    int choice;
    printf("Enter the size of the queue: ");
    scanf("%d", &size);
    printf("You can perform following tasks: ");
    printf("\n1. Enqueue");
    printf("\n2. Dequeue");
    printf("\n3. Display");
    printf("\n4. Exit");


    while(1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!");
        }
    }

}
