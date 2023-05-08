#include <stdio.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int x) {
    if (top == MAX_SIZE - 1) {
        printf("Stack overflow");
        return;
    }
    stack[++top] = x;
}

int pop() {
    if (top == -1) {
        printf("Stack underflow");
        return -1;
    }
    return stack[top--];
}

void fibonacci(int n) {
    int a = 0, b = 1;
    push(a);
    push(b);
    for (int i = 2; i <= n; i++) {
        int c = a + b;
        push(c);
        a = b;
        b = c;
    }
    while (top != -1) {
        printf("%d ", pop());
    }
}

int main() {
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Fibonacci series: ");
    fibonacci(n);
    return 0;
}
