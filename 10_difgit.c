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
        printf("%d", node->data);
        node = node->next;
    }
    printf("\n");
}

struct Node* add(struct Node* num1, struct Node* num2) {
    struct Node* result = NULL;
    int carry = 0;
    while (num1 != NULL || num2 != NULL) {
        int sum = carry;
        if (num1 != NULL) {
            sum += num1->data;
            num1 = num1->next;
        }
        if (num2 != NULL) {
            sum += num2->data;
            num2 = num2->next;
        }
        carry = sum / 10;
        sum = sum % 10;
        push(&result, sum);
    }
    if (carry > 0) {
        push(&result, carry);
    }
    return result;
}

int main() {
    struct Node* num1 = NULL;
    struct Node* num2 = NULL;
    push(&num1, 1);
    push(&num1, 2);
    push(&num1, 3);
    push(&num2, 4);
    push(&num2, 5);
    push(&num2, 6);
    printf("Number 1: ");
    printList(num1);
    printf("Number 2: ");
    printList(num2);
    struct Node* sum = add(num1, num2);
    printf("Sum: ");
    printList(sum);
    return 0;
}