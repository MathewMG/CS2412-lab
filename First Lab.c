#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* prev = dummy;
    struct ListNode* curr = head;

    while (curr) {
        if (curr->val == val) {
            prev->next = curr->next; 
            free(curr); 
        } else {
            prev = curr;
        }
        curr = prev->next; 
    }
    
    struct ListNode* newHead = dummy->next;
    free(dummy); 
    return newHead;
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
    head1->next->next = createNode(6);
    head1->next->next->next = createNode(3);
    head1->next->next->next->next = createNode(4);
    head1->next->next->next->next->next = createNode(5);
    head1->next->next->next->next->next->next = createNode(6);

    printf("Input: ");
    printList(head1);
    head1 = removeElements(head1, 6);
    printf("Output: ");
    printList(head1);
    freeList(head1);
    
    printf("\n");
    
    printf("Example 2:\n");
    struct ListNode* head2 = NULL;

    printf("Input: []\n");
    head2 = removeElements(head2, 1);
    printf("Output: []\n");
    
    printf("\n");

    printf("Example 3:\n");
    struct ListNode* head3 = createNode(7);
    head3->next = createNode(7);
    head3->next->next = createNode(7);
    head3->next->next->next = createNode(7);

    printf("Input: ");
    printList(head3);
    head3 = removeElements(head3, 7);
    printf("Output: []\n");
    freeList(head3);

    return 0;
}
