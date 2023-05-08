#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct TwoStacks {
    int top1;
    int top2;
    int items[MAX_SIZE];
};

void push(struct TwoStacks *s, int stackNum, int x) {
    if (s->top1 == s->top2 - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    if (stackNum == 1) {
        s->items[++s->top1] = x;
    } else if (stackNum == 2) {
        s->items[--s->top2] = x;
    } else {
        printf("Invalid stack number\n");
        exit(1);
    }
}

int pop(struct TwoStacks *s, int stackNum) {
    if (stackNum == 1) {
        if (s->top1 == -1) {
            printf("Stack underflow\n");
            exit(1);
        }
        return s->items[s->top1--];
    } else if (stackNum == 2) {
        if (s->top2 == MAX_SIZE) {
            printf("Stack underflow\n");
            exit(1);
        }
        return s->items[s->top2++];
    } else {
        printf("Invalid stack number\n");
        exit(1);
    }
}

int isStackFull(struct TwoStacks *s) {
    return s->top1 == s->top2 - 1;
}

int isStackEmpty(struct TwoStacks *s, int stackNum) {
    if (stackNum == 1) {
        return s->top1 == -1;
    } else if (stackNum == 2) {
        return s->top2 == MAX_SIZE;
    } else {
        printf("Invalid stack number\n");
        exit(1);
    }
}

void display(struct TwoStacks *s) {
    int i;
    printf("Stack 1: ");
    for (i = s->top1; i >= 0; i--) {
        printf("%d ", s->items[i]);
    }
    printf("\nStack 2: ");
    for (i = s->top2; i < MAX_SIZE; i++) {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}

void displayStack(struct TwoStacks *s, int stackNum) {
    int i;
    if (stackNum == 1) {
        printf("Stack 1: ");
        for (i = s->top1; i >= 0; i--) {
            printf("%d ", s->items[i]);
        }
        printf("\n");
    } else if (stackNum == 2) {
        printf("Stack 2: ");
        for (i = s->top2; i < MAX_SIZE; i++) {
            printf("%d ", s->items[i]);
        }
        printf("\n");
    } else {
        printf("Invalid stack number\n");
        exit(1);
    }
}

int main() {
    struct TwoStacks s;
    s.top1 = -1;
    s.top2 = MAX_SIZE;
    int stackNum, choice, x;
    while (1) {
        printf("1. Push\n2. Pop\n3. StackFull\n4. StackEmpty\n5. Display full stack\n6. Display selected stack\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter stack number (1 or 2): ");
                scanf("%d", &stackNum);
                printf("Enter element to push: ");
                scanf("%d", &x);
                push(&s, stackNum, x);
                break;
            case 2:
                printf("Enter stack number (1 or 2): ");
                scanf("%d", &stackNum);
                printf("Popped element: %d\n", pop(&s, stackNum));
                break;
            case 3:
                printf("Stack is %s\n", isStackFull(&s) ? "full" : "not full");
                break;
            case 4:
                printf("Enter stack number (1 or 2): ");
                scanf("%d", &stackNum);
                printf("Stack is %s\n", isStackEmpty(&s, stackNum) ? "empty" : "not empty");
                break;
            case 5:
                display(&s);
                break;
            case 6:
                printf("Enter stack  number (1 or 2): ");
                scanf("%d", &stackNum);
                displayStack(&s, stackNum);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}