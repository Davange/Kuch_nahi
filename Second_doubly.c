#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = (*head_ref);
    if ((*head_ref) != NULL) {
        (*head_ref)->prev = new_node;
    }
    (*head_ref) = new_node;
}

void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = (*head_ref);
    new_node->data = new_data;
    new_node->next = NULL;
    if ((*head_ref) == NULL) {
        new_node->prev = NULL;
        (*head_ref) = new_node;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
    new_node->prev = last;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void appendStart(struct Node** head1_ref, struct Node** head2_ref) {
    if ((*head1_ref) == NULL) {
        (*head1_ref) = (*head2_ref);
        return;
    }
    if ((*head2_ref) == NULL) {
        return;
    }
    struct Node* last1 = (*head1_ref);
    while (last1->next != NULL) {
        last1 = last1->next;
    }
    last1->next = (*head2_ref);
    (*head2_ref)->prev = last1;
}

void appendEnd(struct Node** head1_ref, struct Node** head2_ref) {
    if ((*head1_ref) == NULL) {
        (*head1_ref) = (*head2_ref);
        return;
    }
    if ((*head2_ref) == NULL) {
        return;
    }
    struct Node* last2 = (*head2_ref);
    while (last2->next != NULL) {
        last2 = last2->next;
    }
    last2->next = (*head1_ref);
    (*head1_ref)->prev = last2;
    (*head1_ref) = (*head2_ref);
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    push(&list1, 1);
    push(&list1, 2);
    push(&list1, 3);
    push(&list2, 4);
    push(&list2, 5);
    push(&list2, 6);
    printf("List 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);
    appendStart(&list2, &list1);
    printf("List 1 after appending List 2 at the start: ");
    printList(list1);
    appendEnd(&list1, &list2);
    printf("List 1 after appending List 2 at the end: ");
    printList(list1);
    return 0;
}