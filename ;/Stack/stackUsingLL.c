#include<stdio.h>
#include<conio.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *top = NULL;
struct Node *newNode;

void push()
{
    int num;
    printf("Enter the number you want to push: ");
    scanf("%d", &num);

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode -> data = num;
    newNode -> next = NULL;

    if(front == NULL)
    {
        front = top = newNode;
    }
    else
    {
        top -> next = newNode;
        top = newNode;
    }
}

void pop()
{
    if(top == NULL)
        printf("Stack is empty!!");
    else if(front == top)
    {
        struct Node *temp = front;
        front = top = NULL;
        free(temp);
    }
    else
    {
        struct Node *temp;
        temp = front;
        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }

        top = temp;
        temp = temp -> next;
        top -> next = NULL;
        free(temp);
    }
}

void display()
{
        if(top == NULL)
            printf("Stack is empty!");
        else
        {
            struct Node *temp;
            temp = front;

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
    printf("This program is an implementation of Stack using Linked List.\n");

    while(1)
    {
        printf("\n\nYou can perform following task: \n");
        printf("1. Push \n2. Pop \n3. Display stack \n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
               push();
               break;

           case 2:
               pop();
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
