#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

// to create new node 
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val  = val;
    node->next = NULL;
    return node;
}

// converting array into linked list
struct Node* buildList(int arr[], int size) {
    struct Node* dummy = newNode(0);
    struct Node* curr  = dummy;
    for (int i = 0; i < size; i++) {
        curr->next = newNode(arr[i]);
        curr       = curr->next;
    }
    return dummy->next;
}

// print  linked list 
void printList(struct Node* start) {
    while (start != NULL) {
        printf("%d", start->val);
        if (start->next != NULL) printf(" -> ");
        start = start->next;
    }
    printf("\n");
}

//main sol
struct Node* addTwoNumbers(struct Node* l1, struct Node* l2) {

    struct Node* dummy = (struct Node*)malloc(sizeof(struct Node));
    dummy->val  = 0;
    dummy->next = NULL;

    struct Node* current = dummy;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;

        if (l1 != NULL) {
            sum += l1->val;
            l1   = l1->next;
        }

        if (l2 != NULL) {
            sum += l2->val;
            l2   = l2->next;
        }

        carry = sum / 10;
        sum   = sum % 10;

        struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->val  = sum;
        newnode->next = NULL;

        current->next = newnode;
        current       = current->next;
    }

    return dummy->next;
}

// ── Main: test cases ──────────────────────────────────────────
int main() {

    // Test 1: [2,4,3] + [5,6,4] = 342 + 465 = 807 → [7,0,8]
    int a1[] = {2, 4, 3};
    int b1[] = {5, 6, 4};
    struct Node* l1 = buildList(a1, 3);
    struct Node* l2 = buildList(b1, 3);
    printf("Test 1: ");
    printList(addTwoNumbers(l1, l2));   // Expected: 7 -> 0 -> 8

    // Test 2: [0] + [0] = 0 → [0]
    int a2[] = {0};
    int b2[] = {0};
    l1 = buildList(a2, 1);
    l2 = buildList(b2, 1);
    printf("Test 2: ");
    printList(addTwoNumbers(l1, l2));   // Expected: 0

    // Test 3: [9,9,9,9,9,9,9] + [9,9,9,9] = carry chain test
    int a3[] = {9, 9, 9, 9, 9, 9, 9};
    int b3[] = {9, 9, 9, 9};
    l1 = buildList(a3, 7);
    l2 = buildList(b3, 4);
    printf("Test 3: ");
    printList(addTwoNumbers(l1, l2));   // Expected: 8->9->9->9->0->0->0->1

    return 0;
}