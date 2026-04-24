#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 10000

// Structure for adjacency list
typedef struct Node {
    int vertex, weight;
    struct Node* next;
} Node;

// Min Heap Node
typedef struct {
    int vertex, dist;
} HeapNode;

// Min Heap
typedef struct {
    int size;
    HeapNode arr[MAX];
} MinHeap;

// Create new adjacency node
Node* createNode(int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

// Insert edge
void addEdge(Node* adj[], int u, int v, int w) {
    Node* newNode = createNode(v, w);
    newNode->next = adj[u];
    adj[u] = newNode;
}

// Swap heap nodes
void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify
void heapify(MinHeap* heap, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < heap->size && heap->arr[left].dist < heap->arr[smallest].dist)
        smallest = left;

    if (right < heap->size && heap->arr[right].dist < heap->arr[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(&heap->arr[i], &heap->arr[smallest]);
        heapify(heap, smallest);
    }
}

// Push into heap
void push(MinHeap* heap, int v, int dist) {
    int i = heap->size++;
    heap->arr[i].vertex = v;
    heap->arr[i].dist = dist;

    while (i && heap->arr[(i-1)/2].dist > heap->arr[i].dist) {
        swap(&heap->arr[i], &heap->arr[(i-1)/2]);
        i = (i-1)/2;
    }
}

// Pop min
HeapNode pop(MinHeap* heap) {
    HeapNode root = heap->arr[0];
    heap->arr[0] = heap->arr[--heap->size];
    heapify(heap, 0);
    return root;
}

// Dijkstra using Min Heap
void dijkstra(Node* adj[], int n, int src) {
    int dist[n+1];
    
    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    MinHeap heap;
    heap.size = 0;

    dist[src] = 0;
    push(&heap, src, 0);

    while (heap.size > 0) {
        HeapNode node = pop(&heap);
        int u = node.vertex;

        Node* temp = adj[u];
        while (temp) {
            int v = temp->vertex;
            int weight = temp->weight;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                push(&heap, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    // Print result
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX)
            printf("Node %d unreachable\n", i);
        else
            printf("Distance to %d = %d\n", i, dist[i]);
    }
}