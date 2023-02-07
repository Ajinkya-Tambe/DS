#include<stdio.h>
#include<conio.h>

#define MAX_SIZE 20

int queue[MAX_SIZE];
int front = -1;
int rear = -1;
int size;

void enqueue()
{
    int data;
    if(front == -1)
            front = 0;

    scanf("%d", &data);
    rear++;
    queue[rear] = data;
}

void replaceElement(int orgNo, int newNum)
{
    int flag = 0;
    int i;
    for(i=front; i<=rear; i++)
    {
        if(queue[i] == orgNo)
        {
            flag = 1;
            queue[i] = newNum;
            break;
        }
    }

    if(flag == 1)
    {
        printf("\nElement replaced successfully!");
        printf("\nQueue after replacement : ");
        for(i=front; i<=rear; i++)
            printf("%d ", queue[i]);
    }

    else
    {
        printf("\n%d is not in the queue.", orgNo);
    }

}


void main()
{
    int i, num;
    int orgNo, newNum;
    //clrscr();
    printf("This program will take a queue and two item. If the first item is in the queue, replace it with the second item.");
    printf("\nEnter the size of the queue: ");
    scanf("%d", &size);

    printf("\n");
    for(i=0; i<size; i++)
    {
        printf("Enter the element no-%d: ", i+1);
        enqueue();
    }
     printf("\nQueue elements: ");
        for(i=front; i<=rear; i++)
            printf("%d ", queue[i]);

    printf("\n\nEnter the number which you want to replace: ");
    scanf("%d", &orgNo);

    printf("Enter the new number(to replace the original one): ");
    scanf("%d", &newNum);

    replaceElement(orgNo, newNum);
    //getch();
}

