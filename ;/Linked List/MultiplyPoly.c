#include<stdio.h>
#include<stdlib.h>

struct Node{
    int coef;
    int expo;
    struct Node *ptr;
};

struct Node * insertInNode(struct Node *first, int coe, int ex){
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    struct Node *temp;

    newNode->coef = coe;
    newNode->expo = ex;
    newNode->ptr= NULL;

    int key = ex;
    if (first == NULL || first->expo<key)
    {
        newNode->ptr = first;
        first = newNode;
    }else{
        temp = first;
        while (temp->ptr!=NULL && temp->ptr->expo>=key)
        {
            temp = temp->ptr;
        }
        newNode->ptr = temp->ptr;
        temp->ptr = newNode;
    }

    return first;
}


struct Node * createPolynomial(struct Node *head){
    int n,coe,exp;

    printf("Enter the number of elements in polynomial: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter the coefficient for element%d: ", i+1);
        scanf("%d", &coe);
        
        printf("Enter the exponent for element%d: ", i+1);
        scanf("%d" ,&exp);

        head = insertInNode(head, coe, exp);
    }
    
    return head;
}

void displayPolynomial(struct Node *head)
{
    if (head == NULL)
    {
        printf("Polynomial is empty.\n");
    }
    else
    {
        struct Node *temp = head;
        while (temp != NULL)
        {
            printf("%dx^%d", temp->coef, temp->expo);
            temp = temp->ptr;

            if (temp != NULL)
            {
                printf(" + ");
            }
            else
            {
                printf("\n");
            }
        }
    }
}

void multiplyPolynomials(struct Node *head1, struct Node *head2){
    struct Node *h1 = head1;
    struct Node *h2 = head2;
    struct Node *h3 = NULL;

    while (h1 != NULL)
    {
        while (h2 != NULL)
        {
            h3 = insertInNode(h3, h1->coef*h2->coef, h1->expo+h2->expo);
            h2 = h2->ptr;
        }
        h2 = head2;
        h1 = h1->ptr;
    }

    displayPolynomial(h3);

    struct Node *temph3 = h3;
    struct Node *temp = NULL;

    while (temph3->ptr != NULL) {
        if (temph3->expo == temph3->ptr->expo)
        {
            temph3->coef = temph3->coef+temph3->ptr->coef;
            temp = temph3->ptr;
            temph3->ptr = temp->ptr;
            free(temp);
            temp = NULL;
        }else{
            temph3 = temph3->ptr;
        }
    }
    
    displayPolynomial(h3);

}

void main(){
    
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;

    printf("\n********************************************************\n");
    printf("Polynomial 1\n");
    head1 = createPolynomial(head1);
    printf("********************************************************\n");

    printf("Polynomial 2\n");
    head2 = createPolynomial(head2);
    printf("********************************************************\n");

    displayPolynomial(head1);
    displayPolynomial(head2);

    printf("Multiplying above 2 polynomials gives: ");
    multiplyPolynomials(head1, head2);
    printf("********************************************************\n");

}