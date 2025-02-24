#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* next = NULL;

    while (curr) {
        next = curr->next;  
        curr->next = prev;  
        prev = curr;       
        curr = next;        
    }

    return prev;  
}

struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void printList(struct ListNode* head) {
    struct ListNode* temp = head;
    while (temp) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

void freeList(struct ListNode* head) {
    struct ListNode* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    printf("Example 1:\n");
    struct ListNode* head1 = createNode(1);
    head1->next = createNode(2);
    head1->next->next = createNode(3);
    head1->next->next->next = createNode(4);
    head1->next->next->next->next = createNode(5);

    printf("Input: ");
    printList(head1);
    head1 = reverseList(head1);
    printf("Output: ");
    printList(head1);
    freeList(head1);

    printf("\nExample 2:\n");
    struct ListNode* head2 = createNode(1);
    head2->next = createNode(2);

    printf("Input: ");
    printList(head2);
    head2 = reverseList(head2);
    printf("Output: ");
    printList(head2);
    freeList(head2);

    printf("\nExample 3:\n");
    struct ListNode* head3 = NULL;

    printf("Input: []\n");
    head3 = reverseList(head3);
    printf("Output: []\n");

    return 0;
}
