#include <stdio.h>
#include <stdlib.h>

// Node for adjacency list
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
int dfs(int node, struct Node* adj[], int visited[], int recStack[]) {
    visited[node] = 1;
    recStack[node] = 1;

    struct Node* temp = adj[node];
    while (temp != NULL) {
        int neighbor = temp->vertex;

        if (!visited[neighbor]) {
            if (dfs(neighbor, adj, visited, recStack))
                return 1;
        }
        else if (recStack[neighbor]) {
            return 1; // cycle found
        }

        temp = temp->next;
    }

    recStack[node] = 0; // backtrack
    return 0;
}

int main() {
    int n, m;
    printf("Enter vertices and edges: ");
    scanf("%d %d", &n, &m);

    struct Node* adj[n];

    // Initialize adjacency list
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
    }

    printf("Enter directed edges (u v):\n");

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        // Directed graph (only one direction)
        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;
    }

    int visited[n];
    int recStack[n];

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }

    int hasCycle = 0;

    // Handle multiple components
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, visited, recStack)) {
                hasCycle = 1;
                break;
            }
        }
    }

    if (hasCycle)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}