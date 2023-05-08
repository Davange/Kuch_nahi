/*Write a program to implement following operations using stack.
A. Factorial of a given number B. Generation of Fibonacci series.
C. Decimal to binary conversion*/

//factorial
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

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    int result = 1;
    for (int i = 1; i <= n; i++) {
        push(i);
    }
    while (top != -1) {
        result *= pop();
    }
    return result;
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("%d! = %d", n, factorial(n));
    return 0;
}
