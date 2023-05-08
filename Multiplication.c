#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

void push(struct Node** head_ref, int coeff, int exp) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->coeff = coeff;
    new_node->exp = exp;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%dx^%d ", node->coeff, node->exp);
        node = node->next;
        if (node != NULL) {
            printf("+ ");
        }
    }
    printf("\n");
}

void multiply(struct Node* poly1, struct Node* poly2, struct Node** result) {
    struct Node* temp1 = poly1;
    while (temp1 != NULL) {
        struct Node* temp2 = poly2;
        while (temp2 != NULL) {
            int coeff = temp1->coeff * temp2->coeff;
            int exp = temp1->exp + temp2->exp;
            push(result, coeff, exp);
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* result = NULL;
    push(&poly1, 3, 2);
    push(&poly1, 5, 1);
    push(&poly1, 6, 0);
    push(&poly2, 6, 1);
    push(&poly2, 8, 0);
    printf("Polynomial 1: ");
    printList(poly1);
    printf("Polynomial 2: ");
    printList(poly2);
    multiply(poly1, poly2, &result);
    printf("Resultant Polynomial: ");
    printList(result);
    return 0;
}