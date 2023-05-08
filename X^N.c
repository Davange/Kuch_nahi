#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    double items[MAX_SIZE];
};

void push(struct Stack *s, double x) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->items[++s->top] = x;
}

double pop(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->items[s->top--];
}

double power(double x, int n) {
    struct Stack s;
    s.top = -1;
    double res = 1.0;
    int i;
    if (n < 0) {
        x = 1.0 / x;
        n = -n;
    }
    for (i = n; i > 0; i /= 2) {
        if (i % 2 == 1) {
            push(&s, x);
        }
        x *= x;
    }
    while (s.top != -1) {
        res *= pop(&s);
    }
    return res;
}

int main() {
    double x;
    int n;
    printf("Enter the base (x): ");
    scanf("%lf", &x);
    printf("Enter the exponent (n): ");
    scanf("%d", &n);
    printf("%.6f\n", power(x, n));
    return 0;
}