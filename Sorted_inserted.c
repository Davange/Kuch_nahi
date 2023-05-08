#include <stdio.h>
#include <stdlib.h>

// Node structure for a singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node into a sorted singly linked list
void SortedInsert(struct Node** headRef, struct Node* newNode) {
    struct Node* current;

    // Special case for an empty list or if the new node should be inserted at the head
    if (*headRef == NULL || (*headRef)->data >= newNode->data) {
        newNode->next = *headRef;
        *headRef = newNode;
    }
    else {
        current = *headRef;
        // Traverse the list to find the correct position to insert the new node
        while (current->next != NULL && current->next->data < newNode->data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to display a singly linked list
void DisplayList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Main function to test SortedInsert() function
int main() {
    struct Node* head = NULL;

    // Create a sorted singly linked list
    SortedInsert(&head, (struct Node*)malloc(sizeof(struct Node)));
    head->data = 10;
    SortedInsert(&head, (struct Node*)malloc(sizeof(struct Node)));
    head->next->data = 20;
    SortedInsert(&head, (struct Node*)malloc(sizeof(struct Node)));
    head->next->next->data = 30;
    SortedInsert(&head, (struct Node*)malloc(sizeof(struct Node)));
    head->next->next->next->data = 40;
    SortedInsert(&head, (struct Node*)malloc(sizeof(struct Node)));
    head->next->next->next->next->data = 50;

    printf("Initial sorted list: ");
    DisplayList(head);

    // Insert a new node with data value 25 into the sorted list
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = 25;
    SortedInsert(&head, newNode);

    printf("List after inserting 25: ");
    DisplayList(head);

    return 0;
}
