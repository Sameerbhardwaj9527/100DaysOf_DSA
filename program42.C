#include <stdio.h>

#define MAX 100

int main() {
    int n;
    int queue[MAX], stack[MAX];
    int front = 0, rear = -1, top = -1;

    scanf("%d", &n);

    // enqueue elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &queue[++rear]);
    }

    // push queue elements into stack
    while(front <= rear) {
        stack[++top] = queue[front++];
    }

    // reset queue
    front = 0;
    rear = -1;

    // pop stack back into queue
    while(top >= 0) {
        queue[++rear] = stack[top--];
    }

    // print reversed queue
    for(int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}