#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

int binaryToDecimal(char *bin) {
    struct Stack s;
    s.top = -1;
    int i, dec = 0;
    for (i = 0; bin[i] != '\0'; i++) {
        push(&s, bin[i] - '0');
    }
    for (i = 0; s.top != -1; i++) {
        dec += pop(&s) * pow(2, i);
    }
    return dec;
}

int main() {
    char bin[MAX_SIZE];
    printf("Enter a binary number: ");
    scanf("%s", bin);
    printf("Decimal equivalent: %d\n", binaryToDecimal(bin));
    return 0;
}