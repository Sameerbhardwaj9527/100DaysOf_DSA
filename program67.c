#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int vertex;
    struct Node* next;
};

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// DFS function
void dfs(int node, struct Node* adj[], int visited[], int stack[], int* top) {
    visited[node] = 1;

    struct Node* temp = adj[node];
    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            dfs(temp->vertex, adj, visited, stack, top);
        }
        temp = temp->next;
    }

    // Push after visiting all neighbors
    stack[++(*top)] = node;
}

int main() {
    int n, m;
    printf("Enter vertices and edges: ");
    scanf("%d %d", &n, &m);

    struct Node* adj[n];

    // Initialize
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
    }

    printf("Enter directed edges (u v):\n");

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;
    }

    int visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    int stack[n];
    int top = -1;

    // Call DFS for all components
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, stack, &top);
        }
    }

    // Print topological order
    printf("Topological Order: ");
    while (top >= 0) {
        printf("%d ", stack[top--]);
    }

    return 0;
}