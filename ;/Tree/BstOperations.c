#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        root = (struct Node*)malloc(sizeof(struct Node));
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    if (data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
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

void LevelOrder(struct Node* root, int level) {
    if (root == NULL) {
        return;
    }
    if (level == 1) {
        printf("%d ", root->data);
    } else if (level > 1) {
        LevelOrder(root->left, level-1);
        LevelOrder(root->right, level-1);
    }
}

int height(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    if (left > right) {
        return left + 1;
    } else {
        return right + 1;
    }
}

void printLevelOrder(struct Node* root) {
    int h = height(root);
    for (int i = 1; i <= h; i++) {
        LevelOrder(root, i);
    }
}

void mirror(struct Node* root) {
    if (root == NULL) {
        return;
    }
    mirror(root->left);
    mirror(root->right);
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
}

void inOrder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}


int main()
{
    struct Node* root = NULL;
    int h;
    int choice, value;
    while (1) {
        printf("1. Insert a node\n2. Delete a node\n3. Print level-wise\n4. Create mirror image of tree\n5. Find the height of the tree\n6. Print the tree\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
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
                h = height(root);
                printf("The height of the tree is: %d\n", h);
                break;
            case 6:
                inOrder(root);
                printf("\n");
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice. Please try again\n");
        }
    }
    return 0;
}

