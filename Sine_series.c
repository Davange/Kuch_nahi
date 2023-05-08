#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

int factorial(int n);

double sine(double x, int n) {
    struct Stack s;
    s.top = -1;
    int i;
    for (i = n; i >= 1; i--) {
        push(&s, pow(-1, i-1) * pow(x, 2*i-1) / factorial(2*i-1));
    }
    double res = 0;
    while (s.top != -1) {
        res += pop(&s);
    }
    return res;
}

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n-1);
}

int main() {
    double x;
    int n;
    printf("Enter the angle in degrees: ");
    scanf("%lf", &x);
    printf("Enter the number of terms in the series: ");
    scanf("%d", &n);
    double res = sine(x * M_PI / 180, n);
    printf("Sine of %lf degrees is %lf\n", x, res);
    return 0;
}
