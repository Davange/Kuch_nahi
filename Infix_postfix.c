#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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

void infixToPostfix(char infix[], char postfix[]) {
    Stack s;
    s.top = -1;
    int i = 0, j = 0;
    while (infix[i] != '\0') {
        char c = infix[i];
        if (isalnum(c)) {
            postfix[j++] = c;
        }
        else if (c == '(') {
            push(&s, c);
        }
        else if (c == ')') {
            while (s.data[s.top] != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s); // discard the '('
        }
        else {
            while (s.top != -1 && precedence(c) <= precedence(s.data[s.top])) {
                postfix[j++] = pop(&s);
            }
            push(&s, c);
        }
        i++;
    }
    while (s.top != -1) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}

int evaluatePostfix(char postfix[]) {
    Stack s;
    s.top = -1;
    int i = 0;
    while (postfix[i] != '\0') {
        char c = postfix[i];
        if (isdigit(c)) {
            push(&s, c - '0');
        }
        else {
            int op2 = pop(&s);
            int op1 = pop(&s);
            switch (c) {
                case '+': push(&s, op1 + op2); break;
                case '-': push(&s, op1 - op2); break;
                case '*': push(&s, op1 * op2); break;
                case '/': push(&s, op1 / op2); break;
                default: printf("Invalid operator"); exit(1);
            }
        }
        i++;
    }
    return pop(&s);
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    printf("Enter infix expression: ");
    fgets(infix, MAX_SIZE, stdin);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);
    return 0;
}
