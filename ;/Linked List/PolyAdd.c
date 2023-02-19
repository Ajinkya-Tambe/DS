#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int coef;
    int exp;
    struct Node *next;
};

struct Node *p1Head = NULL;
struct Node *p2Head = NULL;
struct Node *finalHead = NULL;
struct Node *newNode;
int cnt = 0;

struct Node *insert(int coef, int exp)
{
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode -> coef = coef;
    newNode -> exp = exp;
    newNode -> next = NULL;

    if(cnt == 0)
    {
        if(p1Head == NULL)
            p1Head = newNode;
        else
        {
            struct Node *temp;
            temp = p1Head;
            while(temp -> next != NULL)
            {
                temp = temp -> next;
            }
            temp -> next = newNode;
        }
    }
    else
    {
        if(p2Head == NULL)
            p2Head = newNode;
            //p1 = p1Head;
        else
        {
            struct Node *temp;
            temp = p2Head;
            while(temp -> next != NULL)
            {
                temp = temp -> next;
            }
            temp -> next = newNode;
        }
    }
}



void create()
{
    int i, num, coef, exp;
    printf("\nEnter number of nodes: ");
    scanf("%d", &num);
    for(i = 0; i < num; i++)
    {
        printf("\nEnter coef: ");
        scanf("%d", &coef);
        printf("Enter exp: ");
        scanf("%d", &exp);
        insert(coef, exp);
    }
}

void display(struct Node * headNode)
{
    struct Node *temp = headNode;
    while(temp != NULL)
    {
        printf("%dx^%d -> ", temp -> coef, temp -> exp);
        temp = temp -> next;
    }
    printf(" NULL");
}

void addPoly(struct Node *p1Head, struct Node *p2Head, struct Node *finalHead)
{
    while(p1Head != NULL && p2Head != NULL)
    {
        if(p1Head -> exp > p2Head -> exp)
        {
            finalHead -> exp = p1Head -> exp;
            finalHead -> coef = p1Head -> coef;
            p1Head = p1Head -> next;
        }
        else if(p2Head -> exp > p1Head -> exp)
        {
            finalHead -> exp = p2Head -> exp;
            finalHead -> coef = p2Head -> coef;
            p2Head = p2Head -> next;
        }else
        {
            finalHead -> exp = p1Head -> exp;
            finalHead -> coef = p1Head -> coef + p2Head -> coef;
            p1Head = p1Head -> next;
            p2Head = p2Head -> next;
        }

        if(p1Head != NULL || p2Head != NULL) // Check if there are more nodes to add
        {
            finalHead -> next = (struct Node*)malloc(sizeof(struct Node));
            finalHead = finalHead->next;
            finalHead -> next = NULL;
        }
    }

     while (p1Head != NULL)
    {
        finalHead -> exp = p1Head -> exp;
        finalHead -> coef = p1Head -> coef;
        p1Head = p1Head -> next;

        finalHead -> next = (struct Node*)malloc(sizeof(struct Node));
        finalHead = finalHead->next;
        finalHead -> next = NULL;
    }

    while (p2Head != NULL)
    {
        finalHead -> exp = p2Head -> exp;
        finalHead -> coef = p2Head -> coef;
        p2Head = p2Head -> next;

        finalHead -> next = (struct Node*)malloc(sizeof(struct Node));
        finalHead = finalHead->next;
        finalHead -> next = NULL;
    }
}



void main()
{
    printf("This program will add two polynomials using linked list.");
    printf("\nEnter data for polynomial 1: ");
    create();
    cnt++;

    printf("Polynomial 1: ");
    display(p1Head);


    printf("\n\nEnter data for polynomial 2: ");
    create();

    printf("\nPolynomial 2: ");
    display(p2Head);

    finalHead = (struct Node *)malloc(sizeof(struct Node));

    addPoly(p1Head, p2Head, finalHead);
    printf("\n\nFinal Polynomial: ");
    display(finalHead);


}
