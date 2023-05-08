#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

char stack[MAX_SIZE][MAX_SIZE];
int top = -1;

void push(char str[]) {
    if (top == MAX_SIZE - 1) {
        printf("Stack overflow");
        return;
    }
    top++;
    strcpy(stack[top], str);
}

char* pop() {
    if (top == -1) {
        printf("Stack underflow");
        return NULL;
    }
    return stack[top--];
}

void rearrangeName(char name[]) {
    int len = strlen(name);
    int i = 0;
    char str[MAX_SIZE];
    while (i < len) {
        int j = 0;
        while (name[i] != ' ' && i < len) {
            str[j++] = name[i++];
        }
        str[j] = '\0';
        push(str);
        i++;
    }
    printf("Surname: %s\n", pop());
    printf("First name: %s\n", pop());
    printf("Middle name: %s\n", pop());
}

int main() {
    char name[MAX_SIZE];
    printf("Enter name (in format Surname Firstname Middlename): ");
    fgets(name, MAX_SIZE, stdin);
    rearrangeName(name);
    return 0;
}
