#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

struct Node* CopyList(struct Node* head) {
    struct Node* new_head = NULL;
    struct Node* tail = NULL;
    while (head != NULL) {
        if (new_head == NULL) {
            new_head = (struct Node*)malloc(sizeof(struct Node));
            new_head->data = head->data;
            new_head->next = NULL;
            tail = new_head;
        } else {
            tail->next = (struct Node*)malloc(sizeof(struct Node));
            tail = tail->next;
            tail->data = head->data;
            tail->next = NULL;
        }
        head = head->next;
    }
    return new_head;
}

int main() {
    struct Node* head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    printf("Original List: ");
    printList(head);
    struct Node* new_head = CopyList(head);
    printf("Copied List: ");
    printList(new_head);
    return 0;
}