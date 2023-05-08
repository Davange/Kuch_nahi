#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    char items[MAX_SIZE];
};

void push(struct Stack *s, char c) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->items[++s->top] = c;
}

char pop(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->items[s->top--];
}

int isOperand(char c) {
    return isalnum(c);
}

void postfixToInfix(char *postfix, char *infix) {
    struct Stack s;
    s.top = -1;
    int i, j;
    for (i = 0, j = 0; postfix[i] != '\0'; i++) {
        if (isOperand(postfix[i])) {
            infix[j++] = postfix[i];
        } else {
            char op1 = pop(&s);
            char op2 = pop(&s);
            infix[j++] = '(';
            infix[j++] = op2;
            infix[j++] = postfix[i];
            infix[j++] = op1;
            infix[j++] = ')';
            push(&s, infix[j - 2]);
        }
    }
    infix[j] = '\0';
}

int main() {
    char postfix[MAX_SIZE], infix[MAX_SIZE];
    printf("Enter postfix expression: ");
    scanf("%s", postfix);
    postfixToInfix(postfix, infix);
    printf("Infix expression: %s\n", infix);
    return 0;
}