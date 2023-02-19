#include<stdio.h>
#include<conio.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head1 = NULL;
struct Node *head2 = NULL;

struct Node * create(struct Node *head)
{
    struct Node *temp = NULL, *prev = NULL;
    char ch;
    do
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        printf("\nEnter the data: ");
        scanf("%d", &temp -> data);
        temp -> next = NULL;

        if(prev != NULL)
        {
            prev -> next = temp;
            prev = prev -> next;
        }

        if(head ==NULL)
        {
            head = temp;
            prev = temp;
        }
        printf("Do you want to add one more node? [y/n] ");
        scanf(" %c", &ch);
    } while (ch != 'n');
    return head;
};

void display(struct Node *head)
{
    while(head != NULL)
    {
        printf("%d -> ", head -> data);
        head = head -> next;
    }
    printf("NULL");

}

void appendList(struct Node *temp)
{
    while(temp -> next != NULL)
        temp = temp -> next;

    temp -> next = head2;
    head2 = NULL;
}

void main()
{
    printf("This program will append second list at the end of first list.");
    printf("\nEnter the nodes in first linked list");
    head1 = create(head1);
    printf("\nLinked list 1: ");
    display(head1);

    printf("\n\nEnter the nodes in second linked list");
    head2 = create(head2);
    printf("\nLinked list 2: ");
    display(head2);

    appendList(head1);

    printf("\n\nFinal list: ");
    display(head1);
}
