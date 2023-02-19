#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;
struct node *newNode;

void enqueueAtFront()
{
    int num;
    printf("Enter the element you want to insert: ");
    scanf("%d", &num);

    newNode = (struct node *)malloc(sizeof(struct node));
    newNode -> data = num;
    newNode -> next = NULL;

    if(front == NULL)
        front = rear = newNode;
    else
    {
        newNode -> next = front;
        front = newNode;
    }

}

void enqueueAtRear()
{
    int num;
    printf("Enter the element you want to insert: ");
    scanf("%d", &num);

    newNode = (struct node *)malloc(sizeof(struct node));
    newNode -> data = num;
    newNode -> next = NULL;

    if(front == NULL)
        front = rear = newNode;
    else
    {
        rear -> next = newNode;
        rear = newNode;
    }
}

void dequeueAtFront()
{
    if(front == NULL)
        printf("\nQueue is empty!");
    else
    {
        struct node *temp = front;

        front = front -> next;
        free(temp);
    }
}

void dequeueAtRear()
{
    if(rear == NULL)
        printf("\nQueue is empty!");
    else if(front == rear)
    {
        struct node *temp = front;
        front = rear = NULL;
        free(temp);
    }
    else
    {
        struct node *tempF = front;
        struct node *tempR = rear;
        while(tempF -> next -> next != NULL)
        {
            tempF = tempF -> next;
        }

        tempR = tempF -> next;
        rear = tempF;
        rear -> next = NULL;

        free(tempR);
    }
}

void display()
{
    if(front == NULL)
      printf("\nQueue is Empty!!!\n");

    else
    {
        struct node *temp = front;

        while(temp -> next != NULL)
        {
            printf("%d -> ", temp -> data);
            temp = temp -> next;
        }
        printf("%d -> NULL", temp -> data);
    }
    printf("\n");
}

void main()
{
    int ch;
    //clrscr();
    printf("Double ended queue(user can add and remove the elements from both front and rear of the queue)");
    printf("\n\nYou can perform following operations:");
    printf("\n1. Insert at start.");
    printf("\n2. Insert at end.");
    printf("\n3. Delete at start.");
    printf("\n4. Delete at end.");
    printf("\n5. Display Queue.");
    printf("\n6. Exit.");

    while(1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
        case 1:
            enqueueAtFront();
            break;

        case 2:
            enqueueAtRear();
            break;

        case 3:
            dequeueAtFront();
            break;

        case 4:
            dequeueAtRear();
            break;

        case 5:
            display();
            break;

        case 6:
            exit(0);

        default:
            printf("Invalid choice! Try again");
        }
    }
    //getch();
}









