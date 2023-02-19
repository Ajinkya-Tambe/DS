#include <stdio.h>
#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int item) {
    if (top >= MAX_SIZE - 1) {
        printf("\nStack Overflow\n");
        return;
    }
    top++;
    stack[top] = item;
    printf("\nPushed %d to the stack\n", item);
}

int pop() {
    if (top < 0) {
        printf("\nStack Underflow\n");
        return -1;
    }
    int item = stack[top];
    top--;
    printf("\nPopped %d from the stack\n", item);
    return item;
}

void display() {
    if (top < 0) {
        printf("\nStack is empty\n");
        return;
    }
    int i;
    printf("\nStack: ");
    for (i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int choice, item;
    while (1) {
        printf("\nYou can perform following task\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the item to push: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}
