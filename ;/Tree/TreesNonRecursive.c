#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *CreateNewNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node *insert(struct Node *root, int data)
{
    if (root == NULL)
    {
        return CreateNewNode(data);
    }

    struct Node *current = root;

    while (1)
    {
        if (data < current->data)
        {
            if (current->left == NULL)
            {
                current->left = CreateNewNode(data);
                break;
            }
            else
            {
                current = current->left;
            }
        }

        else if (data > current->data)
        {
            if (current->right == NULL)
            {
                current->right = CreateNewNode(data);
                break;
            }
            else
            {
                current = current->right;
            }
        }

        else
        {
            break;
        }
    }
    return root;
}

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

    struct Node* deleteNode(struct Node* root, int key) {
        if (root == NULL) {
            return root;
        }
        if (key < root->data) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->data) {
            root->right = deleteNode(root->right, key);
        } else {
            if (root->left == NULL) {
                struct Node* temp = root->right;
                free(root);
                return temp;
            } else if (root->right == NULL) {
                struct Node* temp = root->left;
                free(root);
                return temp;
            }
            struct Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

int height(struct Node *root)
{

    struct Node *temp;
    int height = 0;
    struct Node *stack[100];
    int top = -1;
    stack[++top] = root;

    while (top >= 0)
    {
        temp = stack[top--];

        if (temp->right != NULL)
        {
            stack[++top] = temp->right;
        }

        if (temp->left != NULL)
        {
            stack[++top] = temp->left;
        }

        if (top + 1 > height)
        {
            height = top + 1;
        }
    }

    return height;
}

int findMax(struct Node *root)
{

    int max = root->data;
    struct Node *stack[100];

    int top = -1;
    stack[++top] = root;

    struct Node *temp;
    while (top >= 0)
    {
        temp = stack[top--];

        if (temp->data > max)
        {
            max = temp->data;
        }

        if (temp->right != NULL)
        {
            stack[++top] = temp->right;
        }

        if (temp->left != NULL)
        {
            stack[++top] = temp->left;
        }
    }
    return max;
}

void printLevelOrder(struct Node *root)
{
    struct Node *Queue[100];
    int front = 0;
    int rear = -1;
    struct Node *temp;

    Queue[++rear] = root;

    while (front <= rear)
    {
        temp = Queue[front++];
        printf("%d -> ", temp->data);

        if (temp->left)
        {
            Queue[++rear] = temp->left;
        }

        if (temp->right)
        {
            Queue[++rear] = temp->right;
        }
    }
}

void inorder(struct Node *root)
{

    if (root == NULL)
    {
        return;
    }

    struct Node *stack[100];
    int top = -1;

    struct Node *current = root;

    while (current != NULL || top >= 0)
    {
        while (current != NULL)
        {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];
        printf("%d -> ", current->data);
        current = current->right;
    }
}

void preorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    struct Node *stack[100];
    int top = -1;

    stack[++top] = root;

    while (top >= 0)
    {
        struct Node *current = stack[top--];
        printf("%d -> ", current->data);

        if (current->right != NULL)
        {
            stack[++top] = current->right;
        }
        if (current->left != NULL)
        {
            stack[++top] = current->left;
        }
    }
}

// void postorder(struct Node* root) {
//     if (root == NULL) {
//         return;
//     }
    
//     struct Node* stack[100];
//     int top = -1;
//     struct Node* prev = NULL;
    
//     do {
//         while (root != NULL) {
//             if (root->right != NULL) {
//                 stack[++top] = root->right;
//             }
//             stack[++top] = root;
//             root = root->left;
//         }
        
//         root = stack[top--];
        
//         if (root->right != NULL && root->right == stack[top]) {
//             stack[top--] = root;
//             stack[++top] = root->right;
//             root = NULL;
//         } else {
//             printf("%d -> ", root->data);
//             prev = root;
//             root = NULL;
//         }
//     } while (top >= 0);
// } dosent work

void mirror(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }

    struct Node *stack[100];
    int top = -1;
    struct Node *temp;
    struct Node *current;
    stack[++top] = root;

    while (top >= 0)
    {
        current = stack[top--];
        temp = current->left;
        current->left = current->right;
        current->right = temp;

        if (current->left)
        {
            stack[++top] = current->left;
        }

        if (current->right)
        {
            stack[++top] = current->right;
        }
    }

    inorder(root);
}

int main()
{
    struct Node *root = NULL;
    int choice, value;
    while (1)
    {
        printf("1. Insert a node\n2. Delete a node\n3. Print level-wise\n4. Create mirror image of tree\n5. Find the height of the tree\n6. Print the tree\n7. Max\n8. Exit\n9. Print the tree(pre)\n10. Print the tree(post)\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d", &value);
            root = insert(root, value);
            break;
        case 2:
            printf("Enter the value to be deleted: ");
            scanf("%d", &value);
            root = deleteNode(root, value);
            break;
        case 3:
            printLevelOrder(root);
            break;
        case 4:
            mirror(root);
            break;
        case 5:
            int h = height(root);
            printf("The height of the tree is: %d\n", h);
            break;
        case 6:
            inorder(root);
            printf("\n");
            break;
        case 7:
            int m = findMax(root);
            printf("The max element of the tree is: %d\n", m);
            break;
        case 8:
            exit(0);
        

        case 9:
            preorder(root);
            printf("\n");
            break;

        case 10:
            // postorder(root);
            printf("\n");
            break;
            
            default:
            printf("Invalid choice. Please try again\n");
        }
    }
    return 0;
}