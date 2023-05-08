#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int top;
    char data[MAX_SIZE][MAX_SIZE];
} Stack;

void push(Stack *s, char str[]) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack overflow");
        exit(1);
    }
    s->top++;
    strcpy(s->data[s->top], str);
}

char *pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow");
        exit(1);
    }
    char *str = s->data[s->top];
    s->top--;
    return str;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void reverse(char str[]) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void prefixToInfix(char prefix[], char infix[]) {
    Stack s;
    s.top = -1;
    int i = strlen(prefix) - 1;
    while (i >= 0) {
        char c = prefix[i];
        if (isalnum(c)) {
            char str[MAX_SIZE];
            str[0] = c;
            str[1] = '\0';
            push(&s, str);
        }
        else if (isOperator(c)) {
            char str[MAX_SIZE], str1[MAX_SIZE], str2[MAX_SIZE];
            strcpy(str1, pop(&s));
            strcpy(str2, pop(&s));
            sprintf(str, "(%s%c%s)", str1, c, str2);
            push(&s, str);
        }
        i--;
    }
    strcpy(infix, pop(&s));
}

int main() {
    char prefix[MAX_SIZE], infix[MAX_SIZE];
    printf("Enter prefix expression: ");
    fgets(prefix, MAX_SIZE, stdin);
    reverse(prefix);
    prefixToInfix(prefix, infix);
    printf("Infix expression: %s\n", infix);
    return 0;
}
