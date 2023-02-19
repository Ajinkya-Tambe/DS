#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node
{
    int data;
    struct Node* next;
};

struct Node* adj[MAX];
int visited[MAX];
int n;

void addEdge(int u, int v)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

void BFS(int start)
{
    int queue[MAX], rear = -1, front = 0;
    int i, u;

    queue[++rear] = start;
    visited[start] = 1;

    while (rear >= front)
    {
        u = queue[front++];
        printf("%d ", u);
        struct Node* temp = adj[u];
        while (temp)
        {
            i = temp->data;
            if (!visited[i])
            {
                queue[++rear] = i;
                visited[i] = 1;
            }
            temp = temp->next;
        }
    }
}

void DFS(int u)
{
    int i;

    visited[u] = 1;
    printf("%d ", u);
    struct Node* temp = adj[u];
    while (temp)
    {
        i = temp->data;
        if (!visited[i])
        {
            DFS(i);
        }
        temp = temp->next;
    }
}

int main()
{
    int i, start, edges;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (i = 1; i <= edges; i++)
    {
        int x, y;
        printf("Enter edge %d (x y): ", i);
        scanf("%d %d", &x, &y);
        addEdge(x, y);
        addEdge(y, x);
    }

    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &start);
    printf("BFS: ");
    BFS(start);
    printf("\n");

    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &start);
    printf("DFS: ");
    DFS(start);
    printf("\n");

    return 0;
}