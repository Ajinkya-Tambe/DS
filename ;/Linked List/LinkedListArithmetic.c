#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

struct Node * create(struct Node *head)
{
    struct Node *temp = NULL, *prev = NULL;
    char ch;
    int cnt = 0;
    do
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        printf("\nEnter the data: ");
        scanf("%d", &temp -> data);
        temp -> next = NULL;
        cnt ++;

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
    } while (ch != 'n' && cnt < 10);
    return head;
};

void add(struct Node *temp)
{
    int sum = 0;
    while(temp != NULL)
    {
        sum = sum + temp-> data;
        temp = temp -> next;
    }
    printf("\nAddition of the Linked List is: %d", sum);
}

void sub(struct Node *temp)
{
    int sub = temp -> data;
    temp = temp -> next;
    while(temp != NULL)
    {
        sub = sub - temp-> data;
        temp = temp -> next;
    }
    printf("\nSubtraction of the Linked List is: %d", sub);
}

void mul(struct Node *temp)
{
    int mul = temp -> data;
    temp = temp -> next;
    while(temp != NULL)
    {
        mul = mul * temp-> data;
        temp = temp -> next;
    }
    printf("\nMultiplication of the Linked List is: %d", mul);
}

void main()
{
    printf("\nEnter the nodes for linked list");
    head = create(head);
    add(head);
    sub(head);
    mul(head);
}
