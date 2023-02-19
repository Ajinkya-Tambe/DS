#include<stdio.h>
#include<conio.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;
struct Node *newNode;

void enqueue()
{
    int num;
    printf("Enter the number to be inserted: ");
    scanf("%d", &num);

    newNode = (struct Node *)malloc(sizeof(struct Node));
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

void dequeue()
{
    if(front == NULL)
    {
        printf("Queue is empty!");
    }
    else
    {
        struct Node *temp;
        temp = front;
        front = front -> next;
        free(temp);
    }
}

void display()
{
    if(front == NULL)
      printf("\nQueue is Empty!!!\n");
    else
    {
        struct Node *temp;
        temp = front;
        printf("Queue: ");
        while(temp -> next != NULL)
        {
            printf("%d -> ", temp -> data);
            temp = temp -> next;
        }
        printf("%d -> NULL", temp -> data);
    }

}
void main()
{
    int choice;
    printf("This program is an implementation of Queue using Linked List.\n");

    while(1)
    {
        printf("\n\nYou can perform following task: \n");
        printf("1. Enqueue an element \n2. Dequeue an element \n3. Display queue \n4. Exit");
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
                printf("\nInvalid choice! Try again");
        }
    }
}
