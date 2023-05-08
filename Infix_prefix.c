#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int top;
    char data[MAX_SIZE];
} Stack;

void push(Stack *s, char c) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack overflow");
        exit(1);
    }
    s->top++;
    s->data[s->top] = c;
}

char pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow");
        exit(1);
    }
    char c = s->data[s->top];
    s->top--;
    return c;
}

int precedence(char c) {
    if (c == '(' || c == ')')
        return 0;
    else if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else
        return -1;
}

void reverse(char s[]) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

void infixToPrefix(char infix[], char prefix[]) {
    Stack s;
    s.top = -1;
    int i = 0, j = 0;
    reverse(infix);
    while (infix[i] != '\0') {
        char c = infix[i];
        if (isalnum(c)) {
            prefix[j++] = c;
        }
        else if (c == ')') {
            push(&s, c);
        }
        else if (c == '(') {
            while (s.data[s.top] != ')') {
                prefix[j++] = pop(&s);
            }
            pop(&s); // discard the ')'
        }
        else {
            while (s.top != -1 && precedence(c) < precedence(s.data[s.top])) {
                prefix[j++] = pop(&s);
            }
            push(&s, c);
        }
        i++;
    }
    while (s.top != -1) {
        prefix[j++] = pop(&s);
    }
    prefix[j] = '\0';
    reverse(prefix);
}

int main() {
    char infix[MAX_SIZE], prefix[MAX_SIZE];
    printf("Enter infix expression: ");
    fgets(infix, MAX_SIZE, stdin);
    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);
    return 0;
}
