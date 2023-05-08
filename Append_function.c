#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void append(struct Node** a_ref, struct Node** b_ref) {
    if (*a_ref == NULL) {
        *a_ref = *b_ref;
    } else {
        struct Node* temp = *a_ref;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = *b_ref;
    }
    *b_ref = NULL;
}

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

int main() {
    struct Node* a = NULL;
    struct Node* b = NULL;
    push(&a, 1);
    push(&a, 2);
    push(&a, 3);
    push(&b, 4);
    push(&b, 5);
    push(&b, 6);
    printf("List a: ");
    printList(a);
    printf("List b: ");
    printList(b);
    append(&a, &b);
    printf("List a after appending b: ");
    printList(a);
    printf("List b after appending to a: ");
    printList(b);
    return 0;
}