#include <stdio.h>
#include <stdlib.h>

// Doubly Linked List node
typedef struct Node {
  int data;
  struct Node* prev;
  struct Node* next;
} Node;

// Bubble Sort function
void BubbleSort(Node** head) {
  // If list is empty or only contains one node, it is already sorted
  if (*head == NULL || (*head)->next == NULL) {
    return;
  }

  int swapped;
  Node* temp;
  Node* curr = *head;

  do {
    swapped = 0;
    curr = *head;

    while (curr->next != NULL) {
      // Compare adjacent nodes and swap them if they are in the wrong order
      if (curr->data > curr->next->data) {
        // Swap nodes
        temp = curr->next;
        curr->next = temp->next;
        temp->prev = curr->prev;

        if (curr->prev != NULL) {
          curr->prev->next = temp;
        }
        else {
          *head = temp;
        }

        temp->next = curr;
        curr->prev = temp;

        swapped = 1;
      }
      else {
        curr = curr->next;
      }
    }
  } while (swapped);
}

// Insert operation
void Insert(Node** head, int data) {
  // Create a new node
  Node* newNode = (Node*) malloc(sizeof(Node));
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = NULL;

  // If list is empty, set the new node as the head
  if (*head == NULL) {
    *head = newNode;
  }
  // Otherwise, insert the new node at the end of the list
  else {
    Node* temp = *head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
  }
}

// Display operation
void Display(Node* head) {
  if (head == NULL) {
    printf("List is empty.\n");
    return;
  }

  Node* temp = head;
  printf("List: ");
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

// Main function
int main() {
  Node* head = NULL;
  int choice, data;

  do {
    printf("\nMENU\n");
    printf("1. Insert\n");
    printf("2. Sort\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("Enter value to insert: ");
        scanf("%d", &data);
        Insert(&head, data);
        break;
      case 2:
        BubbleSort(&head);
        printf("List has been sorted.\n");
        break;
      case 3:
        Display(head);
        break;
      case 4:
        printf("Exiting program...\n");
        break;
      default:
        printf("Invalid choice. Please try again.\n");
    }
  } while(choice != 4);

  return 0;
}
