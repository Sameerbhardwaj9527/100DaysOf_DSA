/*You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.*/
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertEnd(struct Node* head,int val){
    struct Node* newNode = createNode(val);

    if(head == NULL)
        return newNode;

    struct Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

struct Node* addLists(struct Node* l1, struct Node* l2){
    
    struct Node* result = NULL;
    struct Node* temp = NULL;
    int carry = 0;

    while(l1 != NULL || l2 != NULL || carry){

        int sum = carry;

        if(l1){
            sum += l1->data;
            l1 = l1->next;
        }

        if(l2){
            sum += l2->data;
            l2 = l2->next;
        }

        carry = sum / 10;

        struct Node* newNode = createNode(sum % 10);

        if(result == NULL){
            result = newNode;
            temp = result;
        }
        else{
            temp->next = newNode;
            temp = temp->next;
        }
    }

    return result;
}

void printList(struct Node* head){
    while(head){
        printf("%d ", head->data);
        head = head->next;
    }
}

int main(){

    int n,m,x;
    struct Node* l1 = NULL;
    struct Node* l2 = NULL;

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        l1 = insertEnd(l1,x);
    }

    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d",&x);
        l2 = insertEnd(l2,x);
    }

    struct Node* result = addLists(l1,l2);

    printList(result);

    return 0;
}