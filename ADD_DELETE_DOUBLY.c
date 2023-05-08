#include <stdio.h>
#include <stdlib.h>

// Doubly Linked List node
typedef struct Node {
  int data;
  struct Node* prev;
  struct Node* next;
} Node;

// Queue implemented using a Doubly Linked List
typedef struct Queue {
  Node* front;
  Node* rear;
} Queue;

// Add operation
void Add(Queue* queue) {
  int data;
  printf("Enter value to add: ");
  scanf("%d", &data);

  // Create a new node
  Node* newNode = (Node*) malloc(sizeof(Node));
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = NULL;

  // If queue is empty, set newNode as both front and rear
  if (queue->front == NULL) {
    queue->front = newNode;
    queue->rear = newNode;
  }
  // Otherwise, insert newNode at the rear and update rear pointer
  else {
    newNode->prev = queue->rear;
    queue->rear->next = newNode;
    queue->rear = newNode;
  }

  printf("%d has been added to the queue.\n", data);
}

// Delete operation
void Delete(Queue* queue) {
  if (queue->front == NULL) {
    printf("Queue is empty.\n");
    return;
  }

  int data = queue->front->data;
  Node* temp = queue->front;

  // If there is only one node in the queue, set both front and rear to NULL
  if (queue->front == queue->rear) {
    queue->front = NULL;
    queue->rear = NULL;
  }
  // Otherwise, update the front pointer
  else {
    queue->front = queue->front->next;
    queue->front->prev = NULL;
  }

  free(temp);
  printf("%d has been deleted from the queue.\n", data);
}

// Main function
int main() {
  Queue queue = { NULL, NULL };
  int choice;

  do {
    printf("\nQUEUE MENU\n");
    printf("1. Add\n");
    printf("2. Delete\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        Add(&queue);
        break;
      case 2:
        Delete(&queue);
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
