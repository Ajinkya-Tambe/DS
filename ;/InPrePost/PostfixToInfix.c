#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 20
char str[MAX], stack[MAX];
int top = -1;

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    return stack[top--];
}

void PostfixToInfix()
{
    int n, i, j = 0;
    char a, b, op, x[20];
    printf("Enter the postfix expression: ");
    fflush(stdin);
    gets(str);
    strrev(str);
    n = strlen(str);
    for (i = 0; i < MAX; i++)
        stack[i] = '\0';
    printf("Infix expression is:\t");
    for (i = 0; i < n; i++)
    {
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            push(str[i]);
        }
        else
        {
            x[j] = str[i];
            j++;
            x[j] = pop();
            j++;
        }
    }
    x[j] = str[top--];
    strrev(x);
    printf("%s\n", x);
}

void main()
{
    printf("This program will convert postfix expression to infix expression \n\n");
    PostfixToInfix();
}