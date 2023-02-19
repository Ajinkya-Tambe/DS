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

void PrefixToInfix()
{
    int n, i;
    char a, b, op;
    printf("\nEnter the prefix expression: ");
    fflush(stdin);
    gets(str);
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
            op = pop();
            a = str[i];
            printf("%c%c", a, op);
        }
    }
    printf("%c\n", str[top--]);
}

void main()
{
    printf("This program will convert Prefix expression to Infix expression: \n");
    PrefixToInfix();
}