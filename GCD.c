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

int gcd(int a, int b) {
    struct Stack s;
    s.top = -1;
    int temp;
    while (b != 0) {
        push(&s, a % b);
        temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}

int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    int res = n;
    int i;
    for (i = n - 1; i >= 2; i--) {
        res = gcd(res, i);
        if (res == 1) {
            break;
        }
    }
    printf("GCD of %d is %d\n", n, res);
    return 0;
}