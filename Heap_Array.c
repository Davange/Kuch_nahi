#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    int items[MAX_SIZE];
};

void push(struct Stack *s, int x) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->items[++s->top] = x;
}

int pop(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->items[s->top--];
}

void printHeap(int *arr, int n) {
    struct Stack s;
    s.top = -1;
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
        if (i == 0 || i == 2 || i == 6 || i == 14) {
            printf("\n");
        }
        if (2 * i + 1 < n) {
            push(&s, 2 * i + 1);
        }
        if (2 * i + 2 < n) {
            push(&s, 2 * i + 2);
        }
    }
    printf("\n");
}

int main() {
    int arr[MAX_SIZE], n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Heap in level order:\n");
    printHeap(arr, n);
    return 0;
}