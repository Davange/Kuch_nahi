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

int getMax(struct Stack *s) {
    int max = s->items[s->top];
    int i;
    for (i = s->top - 1; i >= 0; i--) {
        if (s->items[i] > max) {
            max = s->items[i];
        }
    }
    return max;
}

int getMin(struct Stack *s) {
    int min = s->items[s->top];
    int i;
    for (i = s->top - 1; i >= 0; i--) {
        if (s->items[i] < min) {
            min = s->items[i];
        }
    }
    return min;
}

int main() {
    struct Stack s;
    s.top = -1;
    int n, i, x;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        push(&s, x);
    }
    printf("Maximum element: %d\n", getMax(&s));
    printf("Minimum element: %d\n", getMin(&s));
    return 0;
}