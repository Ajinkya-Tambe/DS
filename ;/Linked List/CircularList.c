#include<stdio.h>
#include<stdlib.h>
 
 struct Node
 {
    int data;
    struct Node *link;
 };

struct Node *head = NULL, *tail = NULL;
int nodeCnt = 0;

void create()
{
    struct Node *newNode, *temp;
    char ch;
    do
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("\nEnter the data: ");
        scanf("%d", &newNode -> data);
        newNode -> link = NULL;

        if(head ==NULL)
        {
            head = temp = newNode;
            tail = newNode;
            nodeCnt++;
        }
        else
        {
            temp -> link = newNode;
            temp = newNode;
            tail = newNode;
            nodeCnt++;
        }

        temp -> link = head;

        printf("Do you want to add one more node? [y/n] ");
        scanf(" %c", &ch);
    } while (ch != 'n');
    // printf("%d", temp -> link -> data);
}

void insertAtBeginning()
{
    struct Node *newNode = NULL;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter the data: ");
    scanf("%d", &newNode -> data);
    newNode -> link = NULL;

    if(tail == NULL)
    {
        head = tail = newNode;
        tail -> link = newNode;
        nodeCnt++;
    }
    else
    {
        newNode -> link = tail -> link;
        tail -> link = newNode;
        head = newNode;

        nodeCnt++;
    }
}

void insertAtEnd()
{
    struct Node *newNode = NULL;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter the data: ");
    scanf("%d", &newNode -> data);
    newNode -> link = NULL;

    if(tail == NULL)
    {
        head = tail = newNode;
        tail -> link = newNode;
        nodeCnt++;
    }
    else
    {
        newNode -> link = tail -> link;
        tail -> link = newNode;
        tail = newNode;

        nodeCnt++;
    }
}

void insertAtPosition()
{
    int position;
    printf("\nEnter the position where you want to data: ");
    scanf("%d", &position);

    if(head == NULL)
    {
        insertAtBeginning();
    }   
    else if(position > nodeCnt)
    {
        printf("\nInvalid position!");
    }
    else if(position == 1)
    {
        insertAtBeginning();
    }
    else if(position == nodeCnt)
    {
        insertAtEnd();
    }
    else
    {
        struct Node *newNode = NULL, *temp; 
        temp = tail -> link;
        int i = 1;
        newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("\nEnter the data: ");
        scanf("%d", &newNode -> data);
        newNode -> link = NULL; 
        while (i < position -1)
        {
            temp = temp -> link;
            i++;
        }

        newNode -> link = temp -> link;
        temp -> link = newNode;
        
        nodeCnt++;
    }
}

void display()
{
    struct Node *temp;
    if(head == NULL)
    {
        printf("\nList is empty!");
    }
    else
    {
        temp = head;
        while(temp -> link != head)
        {
            printf("%d -> ", temp -> data);
            temp = temp -> link;
        }
        printf("%d -> ", temp -> data);
        printf(" NULL");
    }
}

void main()
 {
   char respo;
   int task;
   do
   {
        printf("\nYou have following choices: \n 1. Create linked list\n 2. Insert an element\n 3. Delete an element\n 4. Display the linked list.");
        printf("\nEnter your choice: ");
        scanf("%d", &task);
        switch (task)
        {
        case 1:
            create();
            break;

        case 2:
            insertAtPosition();
            break;
        
        case 3:
            // delete();
            break;

        case 4:
            display();
            break;

        default:
            break;
        }

        printf("\n\nDo you want to continue? [y/n] ");
        scanf(" %c", &respo);
   } while (respo == 'y');
 }
