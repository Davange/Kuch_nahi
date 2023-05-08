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

void decimalToBinary(int n) {
    while (n > 0) {
        int remainder = n % 2;
        push(remainder);
        n /= 2;
    }
    printf("Binary equivalent: ");
    while (top != -1) {
        printf("%d", pop());
    }
}

int main() {
    int n;
    printf("Enter a decimal number: ");
    scanf("%d", &n);
    decimalToBinary(n);
    return 0;
}
