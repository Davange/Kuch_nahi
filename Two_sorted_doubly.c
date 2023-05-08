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

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

struct Node* merge(struct Node* list1, struct Node* list2) {
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }
    if (list1->data < list2->data) {
        list1->next = merge(list1->next, list2);
        list1->next->prev = list1;
        list1->prev = NULL;
        return list1;
    } else {
        list2->next = merge(list1, list2->next);
        list2->next->prev = list2;
        list2->prev = NULL;
        return list2;
    }
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    push(&list1, 1);
    push(&list1, 3);
    push(&list1, 5);
    push(&list2, 2);
    push(&list2, 4);
    push(&list2, 6);
    printf("List 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);
    struct Node* mergedList = merge(list1, list2);
    printf("Merged List: ");
    printList(mergedList);
    return 0;
}