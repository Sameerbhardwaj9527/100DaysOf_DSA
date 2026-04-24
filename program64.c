#include <stdio.h>
#include <stdlib.h>

// Node for adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n, m;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    struct Node* adj[n];

    // Initialize adjacency list
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
    }

    printf("Enter edges (u v):\n");

    // Undirected graph
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        newNode = createNode(u);
        newNode->next = adj[v];
        adj[v] = newNode;
    }

    int s;
    printf("Enter starting vertex: ");
    scanf("%d", &s);

    int visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Queue implementation
    int queue[n];
    int front = 0, rear = 0;

    // Start BFS
    visited[s] = 1;
    queue[rear++] = s;

    printf("BFS Traversal: ");

    while (front < rear) {
        int curr = queue[front++];
        printf("%d ", curr);

        struct Node* temp = adj[curr];
        while (temp != NULL) {
            if (!visited[temp->vertex]) {
                visited[temp->vertex] = 1;
                queue[rear++] = temp->vertex;
            }
            temp = temp->next;
        }
    }

    return 0;
}