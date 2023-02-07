#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;
struct node *newNode;
void enqueue()
{
    int num;
    printf("\nEnter the value you want to insert: ");
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

void dequeue()
{
    if(front == NULL)
        printf("\nQueue is empty!");
    else
    {
        struct node *temp = front;

       // if(front == NULL)
         //   rear = NULL;

        front = front -> next;
	free(temp);
	printf("\Deleted successfully!");
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
}

void main()
{
    int choice;
    clrscr();
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
    getch();
}
