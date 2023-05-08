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

int sum(int n) {
    struct Stack s;
    s.top = -1;
    int i;
    for (i = 1; i <= n; i++) {
        push(&s, i);
    }
    int res = 0;
    while (s.top != -1) {
        res += pop(&s);
    }
    return res;
}

int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    printf("Sum of the first %d natural numbers is %d\n", n, sum(n));
    return 0;
}