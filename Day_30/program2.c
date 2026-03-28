/*You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]
Example 2:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]
Example 3:

Input: l1 = [0], l2 = [0]
Output: [0]
 

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
    while(temp->next)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

struct Node* addLists(struct Node* l1, struct Node* l2){

    int s1[100], s2[100];
    int top1=-1, top2=-1;

    while(l1){
        s1[++top1] = l1->data;
        l1 = l1->next;
    }

    while(l2){
        s2[++top2] = l2->data;
        l2 = l2->next;
    }

    int carry = 0;
    struct Node* result = NULL;

    while(top1>=0 || top2>=0 || carry){

        int sum = carry;

        if(top1>=0) sum += s1[top1--];
        if(top2>=0) sum += s2[top2--];

        struct Node* newNode = createNode(sum%10);

        newNode->next = result;
        result = newNode;

        carry = sum/10;
    }

    return result;
}

void printList(struct Node* head){
    while(head){
        printf("%d ",head->data);
        head = head->next;
    }
}

int main(){

    int n,m,x;
    struct Node* l1=NULL;
    struct Node* l2=NULL;

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