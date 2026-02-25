/*Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

 

Example 1:


Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
Example 2:


Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.
Example 3:


Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.
 

Constraints:

The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.
 

Follow up: Can you solve it using O(1) (i.e. constant) memory?*/
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

// Create linked list
struct ListNode* createList(int n) {
    if (n == 0) return NULL;

    struct ListNode *head = NULL, *temp = NULL, *newNode;
    int x;

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);

        newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = x;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

// Create cycle at position pos
void createCycle(struct ListNode *head, int pos) {
    if (pos == -1 || head == NULL) return;

    struct ListNode *temp = head, *cycleNode = NULL;
    int idx = 0;

    while (temp->next != NULL) {
        if (idx == pos)
            cycleNode = temp;
        temp = temp->next;
        idx++;
    }

    temp->next = cycleNode;
}

// Detect cycle start
struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode *slow = head, *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}

int main() {
    int n, pos;
    scanf("%d", &n);

    struct ListNode *head = createList(n);

    scanf("%d", &pos);

    createCycle(head, pos);

    struct ListNode *cycleStart = detectCycle(head);

    if (cycleStart)
        printf("tail connects to node with value %d\n", cycleStart->val);
    else
        printf("no cycle\n");

    return 0;
}