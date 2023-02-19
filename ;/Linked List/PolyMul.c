#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coef;
    int exp;
    struct Node *next;
};

struct Node *p1Head = NULL;
struct Node *p2Head = NULL;
struct Node *finalHead = NULL;

void insert(struct Node **head, int coef, int exp)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->coef = coef;
    newNode->exp = exp;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void create(struct Node **head)
{
    int i, num, coef, exp;
    printf("\nEnter number of nodes: ");
    scanf("%d", &num);
    for (i = 0; i < num; i++)
    {
        printf("\nEnter coef: ");
        scanf("%d", &coef);
        printf("Enter exp: ");
        scanf("%d", &exp);
        insert(head, coef, exp);
    }
}

void display(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%dx^%d -> ", temp->coef, temp->exp);
        temp = temp->next;
    }
    printf(" NULL");
}

void mulPoly(struct Node *p1Head, struct Node *p2Head, struct Node **finalHead)
{
    struct Node *p1 = p1Head;
    struct Node *p2 = p2Head;

    while (p1 != NULL)
    {
        p2 = p2Head;
        while (p2 != NULL)
        {
            int coef = p1->coef * p2->coef;
            int exp = p1->exp + p2->exp;

            struct Node *temp = *finalHead;
            if (*finalHead == NULL || exp > temp->exp)
            {
                struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
                newNode->coef = coef;
                newNode->exp = exp;
                newNode->next = *finalHead;
                *finalHead = newNode;
            }
            else
            {
                while (temp->next != NULL && temp->next->exp >= exp)
                {
                    temp = temp->next;
                }

                if (temp->exp == exp)
                {
                    temp->coef += coef;
                }
                else
                {
                    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
                    newNode->coef = coef;
                    newNode->exp = exp;
                    newNode->next = temp->next;
                    temp->next = newNode;
                }
            }

            p2 = p2->next;
        }
        p1 = p1->next;
    }
}

int main()
{
    printf("This program will multiply two polynomials using linked list.");
    printf("\nEnter data for polynomial 1: ");
    create(&p1Head);

    printf("\nPolynomial 1: ");
    display(p1Head);

    printf("\n\nEnter data for polynomial 2: ");
    create(&p2Head);

    printf("\nPolynomial 2: ");
    display(p2Head);

    mulPoly(p1Head, p2Head, &finalHead);

    printf("\n\nFinal Polynomial: ");
    display(finalHead);

    return 0;
}
