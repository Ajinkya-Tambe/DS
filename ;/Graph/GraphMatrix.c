#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int n;

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
        for (i = 0; i < n; i++)
        {
            if (adj[u][i] == 1 && !visited[i])
            {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

void DFS(int u)
{
    int i;

    visited[u] = 1;
    printf("%d ", u);
    for (i = 0; i < n; i++)
    {
        if (adj[u][i] == 1 && !visited[i])
        {
            DFS(i);
        }
    }
}

int main()
{
    int i, j, start, edges;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (i = 1; i <= edges; i++)
    {
        int x, y;
        printf("Enter edge %d (x y): ", i);
        scanf("%d %d", &x, &y);
        adj[x][y] = adj[y][x] = 1;
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