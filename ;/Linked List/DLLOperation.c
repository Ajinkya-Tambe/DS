#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node {
    int data;
    int next;
    int prev;
};

struct node *head;

void insertAtBeginning()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    int item;
    scanf("%d",&item);

    temp -> data = item;
    temp -> next = NULL;
    temp -> prev = NULL;

    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
}

void insertAtMiddle()
{
    int item, pos, i;
    printf("Enter data: ");
    scanf("%d", &item);
    printf("\nEnter position: ");
    scanf("%d", &pos);

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->next = NULL;
    temp->prev = NULL;

    struct node *ptr = head;
    for (int i = 1; i < pos - 1 && ptr != NULL; i++) {
        ptr = ptr->next;
    }
    struct node *pos_ptr = temp;

    if (ptr == NULL) {
        printf("Invalid position\n");
        return;
    }

    temp->prev = ptr;
    temp->next = ptr->next;
    if (ptr->next != NULL) {
        pos_ptr = temp;
    }
    ptr->next = temp;
}

void insertAtLast()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    int item;
    scanf("%d",&item);

    temp -> data = item;
    temp -> next = NULL;
    temp -> prev = NULL;

    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        struct node *ptr = head;
        while(ptr -> next != NULL) // Move the pointer to the last node in the list
        {
            ptr = ptr -> next;
        }
        ptr -> next = temp;
        temp -> prev = ptr;
    }
}

void deleteAtBeginning()
{
    if(head == NULL)
    {
        printf("Linked List is empty!\n");
    }
    else
    {
        struct node *temp = head;
        head = head -> next;
        head -> prev = NULL;
        free(temp);
    }
}

void deleteAtMiddle()
{
    int pos, i;
    printf("Enter position: ");
    scanf("%d", &pos);

    struct node *ptr = head;
    for (i = 1; i < pos   && ptr != NULL; i++) //stop at the node just before the one to be deleted
        ptr = ptr->next;

    if (ptr == NULL) {
        printf("Invalid position\n");
        return;
    }

    struct node *p = ptr->prev;
    struct node *q = ptr->next;
    p->next = q;
    if (q != NULL) {
        q->prev = p;
    }
    free(ptr);

}
void deleteAtEnd()
{
    if(head == NULL)
    {
        printf("Linked List is empty!\n");
    }
    else
    {
        struct node *temp = head;
        while(temp -> next != NULL)
            temp = temp -> next;

        if (temp == head)
        {
            head = NULL;
        }
        else
        {
            printf("here");
            struct node * temp_prev = temp -> prev;
            temp_prev -> next = NULL;
            temp -> prev = NULL;
        }
        free(temp);
    }
}

void display()
{
    struct node *temp = head;
    if(temp == NULL)
        printf("\nLinked List empty!");
    while (temp != NULL)
    {
        printf("%d -> ",temp -> data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void main()
{
    int choice;
    printf("Doubly Linked List Operations");
    printf("\nYou can perform following operations: ");
    while(1)
    {
        printf("\n1. Insertion at beginning \n2. Insertion at middle \n3. Insertion at last \n4. Deletion at start \n5. Deletion at middle \n6. Deletion at last \n7. Display \n8. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                insertAtBeginning();
                break;

            case 2:
                insertAtMiddle();
                break;

            case 3:
                insertAtLast();
                break;

            case 4:
                deleteAtBeginning();
                break;

            case 5:
                deleteAtMiddle();
                break;

            case 6:
                deleteAtEnd();
                break;

            case 7:
                display();
                break;

            case 8:
                exit(0);

            default:
                printf("Invalid choice!");
        }
    }
}
