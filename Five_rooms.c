/*A person is living in house having five rooms. These rooms are
adjacent to each other. There is a treasure which is electronically
locked and to unlock it we need a code. In fifth room there is a
box in which decimal number is written. We need to convert
that number into binary to open treasure which is kept in first
room. We need to move from room no. 1 to 2 to 3 and so on and
follow the reverse way to come back i.e. from 5 to 4 to 3 etc.
Apply suitable logic to implement this scenario using stack.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

struct Stack {
    int top;
    int items[MAX_SIZE];
};

void push(struct Stack* stack, int item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack Overflow!\n");
        exit(1);
    }
    stack->items[++stack->top] = item;
}

int pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack Underflow!\n");
        exit(1);
    }
    return stack->items[stack->top--];
}

int main() {
    struct Stack stack;
    stack.top = -1;
    int decimal_number, binary_number = 0, base = 1;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal_number);
    while (decimal_number > 0) {
        int rem = decimal_number % 2;
        binary_number += rem * base;
        decimal_number /= 2;
        base *= 10;
    }
    printf("Binary representation of the decimal number: %d\n", binary_number);
    int code = binary_number;
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);
    while (stack.top != -1) {
        int room = pop(&stack);
        printf("Entered Room %d\n", room);
        if (room == 1) {
            printf("Treasure unlocked!\n");
            break;
        }
        if (room == 5) {
            printf("Converted decimal code to binary: %d\n", code);
            continue;
        }
        push(&stack, room - 1);
    }
    while (stack.top != -1) {
        int room = pop(&stack);
        printf("Exited Room %d\n", room);
    }
    return 0;
}
