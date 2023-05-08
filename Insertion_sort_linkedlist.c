#include <stdio.h>
#include <stdlib.h>

// Singly Linked List node
typedef struct Node {
  int data;
  struct Node* next;
} Node;

// Insertion Sort function
void InsertionSort(Node** head) {
  // If list is empty or only contains one node, it is already sorted
  if (*head == NULL || (*head)->next == NULL) {
    return;
  }

  Node* sortedList = NULL;  // Start with an empty sorted list
  Node* curr = *head;       // Traverse the original list

  while (curr != NULL) {
    Node* nextNode = curr->next;   // Store the next node of the original list

    // Insert the current node into the sorted list in ascending order
    if (sortedList == NULL || curr->data < sortedList->data) {
      curr->next = sortedList;
      sortedList = curr;
    }
    else {
      Node* temp = sortedList;
      while (temp->next != NULL && curr->data > temp->next->data) {
        temp = temp->next;
      }
      curr->next = temp->next;
      temp->next = curr;
    }

    curr = nextNode;    // Move to the next node of the original list
  }

  *head = sortedList;   // Update the head pointer to point to the sorted list
}

// Insert operation
void Insert(Node** head, int data) {
  // Create a new node
  Node* newNode = (Node*) malloc(sizeof(Node));
  newNode->data = data;
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
        InsertionSort(&head);
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
