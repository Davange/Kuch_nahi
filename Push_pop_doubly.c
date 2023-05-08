#include <stdio.h>
#include <stdlib.h>

// Doubly Linked List node
typedef struct Node {
  int data;
  struct Node* prev;
  struct Node* next;
} Node;

// Stack implemented using a Doubly Linked List
typedef struct Stack {
  Node* top;
} Stack;

// Push operation
void Push(Stack* stack) {
  int data;
  printf("Enter value to push: ");
  scanf("%d", &data);

  // Create a new node
  Node* newNode = (Node*) malloc(sizeof(Node));
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = NULL;

  // If stack is empty, set newNode as top
  if (stack->top == NULL) {
    stack->top = newNode;
  }
  // Otherwise, insert newNode at the top and update top pointer
  else {
    newNode->next = stack->top;
    stack->top->prev = newNode;
    stack->top = newNode;
  }

  printf("%d has been pushed onto the stack.\n", data);
}

// Pop operation
void Pop(Stack* stack) {
  if (stack->top == NULL) {
    printf("Stack is empty.\n");
    return;
  }

  int data = stack->top->data;
  Node* temp = stack->top;

  // If there is only one node in the stack, set top to NULL
  if (stack->top->next == NULL) {
    stack->top = NULL;
  }
  // Otherwise, update the top pointer
  else {
    stack->top = stack->top->next;
    stack->top->prev = NULL;
  }

  free(temp);
  printf("%d has been popped from the stack.\n", data);
}

// Main function
int main() {
  Stack stack = { NULL };
  int choice;

  do {
    printf("\nSTACK MENU\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        Push(&stack);
        break;
      case 2:
        Pop(&stack);
        break;
      case 3:
        printf("Exiting program...\n");
        break;
      default:
        printf("Invalid choice. Please try again.\n");
    }
  } while(choice != 3);

  return 0;
}
