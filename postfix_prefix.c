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

int precedence(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}

void postfixToPrefix(char *postfix, char *prefix) {
    struct Stack s;
    s.top = -1;
    int i, j;
    for (i = strlen(postfix) - 1, j = 0; i >= 0; i--) {
        if (isOperand(postfix[i])) {
            prefix[j++] = postfix[i];
        } else if (postfix[i] == ')') {
            push(&s, postfix[i]);
        } else if (postfix[i] == '(') {
            while (s.items[s.top] != ')') {
                prefix[j++] = pop(&s);
            }
            pop(&s);
        } else {
            while (s.top != -1 && precedence(postfix[i]) < precedence(s.items[s.top])) {
                prefix[j++] = pop(&s);
            }
            push(&s, postfix[i]);
        }
    }
    while (s.top != -1) {
        prefix[j++] = pop(&s);
    }
    prefix[j] = '\0';
    strrev(prefix);
}

int main() {
    char postfix[MAX_SIZE], prefix[MAX_SIZE];
    printf("Enter postfix expression: ");
    scanf("%s", postfix);
    postfixToPrefix(postfix, prefix);
    printf("Prefix expression: %s\n", prefix);
    return 0;
}