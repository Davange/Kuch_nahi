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

void printTable(int n) {
    struct Stack s;
    s.top = -1;
    int i, j;
    for (i = 10; i >= 1; i--) {
        push(&s, n * i);
    }
    printf("Multiplication table of %d:\n", n);
    for (i = 1; i <= 10; i++) {
        for (j = 1; j <= 3; j++) {
            printf("%d x %d = %d\t", i, pop(&s) / i, pop(&s));
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    printTable(n);
    return 0;
}