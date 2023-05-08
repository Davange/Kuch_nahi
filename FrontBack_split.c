#include <stdio.h>
#include <stdlib.h>

// Node structure for a singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to split a singly linked list into two sublists
void FrontBackSplit(struct Node* source, struct Node** frontRef, struct Node** backRef) {
    struct Node* slow = source;
    struct Node* fast = source->next;

    // Advance 'fast' two nodes and 'slow' one node in each iteration until 'fast' reaches the end of the list
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    // 'slow' is at the midpoint of the list, so split it into two sublists
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

// Function to display a singly linked list
void DisplayList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Main function to test FrontBackSplit() function
int main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 2;
    head->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->data = 3;
    head->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->data = 5;
    head->next->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->next->data = 7;
    head->next->next->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->next->next->data = 11;
    head->next->next->next->next->next = NULL;

    printf("Initial list: ");
    DisplayList(head);

    struct Node* front;
    struct Node* back;
    FrontBackSplit(head, &front, &back);

    printf("Front half of list: ");
    DisplayList(front);
    printf("Back half of list: ");
    DisplayList(back);

    return 0;
}
