 #include<stdio.h>
#include<stdlib.h>

 struct Node
 {
    int data;
    struct Node *ptr;
 };

struct Node *head = NULL;

 struct Node * create()
 {
    struct Node *head = NULL, *temp = NULL, *prev = NULL;
    char ch;
    do
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        printf("\nEnter the data: ");
        scanf("%d", &temp -> data);
        temp -> ptr = NULL;

        if(prev != NULL)
        {
            prev -> ptr = temp;
            prev = prev -> ptr;
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
 }

void insert(struct Node *head) //**head
{
    struct Node *temp, *prev;
    int data, position, i;
    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the position at which you want to insert the element: ");
    scanf("%d", &position);
    printf("Enter the data: ");
    scanf("%d", &temp -> data);
    temp -> ptr = NULL;

    if(position == 1)
    {
        temp -> ptr = head;  //*head
        head = temp;        //*head
    }
    else
    {
        prev = *head;  //*head
        for(i = 1; i < position-1; i++)
            prev = prev -> ptr;
        temp -> ptr = prev -> ptr;
        prev -> ptr = temp;
    }
}

void delete(struct Node *head)
{
    struct Node *temp, *prev;
    int position ,i;
    printf("\nEnter position you want to delete: ");
    scanf("%d", &position);
    if(position == 1)
    {
        temp = head;
        head = head -> ptr;
        free(temp);
    }
    else
    {
        prev = head;
        for(i = 1; i < position-1; i++)
        {
            prev = prev -> ptr;
        }
        temp = prev -> ptr;
        prev -> ptr = temp -> ptr;
        free(temp);
    }
}

 void display(struct Node *head)
 {
    struct Node *temp;
    if(head == NULL)
        printf("\nLinked list is empty!");
    else
    {
        printf("\nLinked list: ");
        temp = head;
        do
        {
            printf("%d -> ", temp -> data);
            temp = temp -> ptr;
        } while (temp != NULL);
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
            head = create();
            break;

        case 2:
            insert(head); //&head
            break;
            // printf("at insert");

        case 3:
            delete(head);
            break;

        case 4:
            display(head);
            break;

        default:
            break;
        }

        printf("\n\nDo you want to continue? [y/n] ");
        scanf(" %c", &respo);
   } while (respo == 'y');
 }
