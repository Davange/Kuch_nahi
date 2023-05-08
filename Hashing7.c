/*WAP to simulate employee database as a hash table. Search a
perticular faculty by using Mid square Method as a hash function
for linear probing with chaining with replacement method of
collision handling technique. Assume suitable data for faculty
record.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct Employee {
    int id;
    char name;
    float salary;
} Employee;

typedef struct Node {
    Employee emp;
    struct Node* next;
} Node;

Node* hashTable[TABLE_SIZE];

int hash(int key) {
    int square = key * key;
    int digits = 0;
    int temp = square;
    while (temp != 0) {
        digits++;
        temp /= 10;
    }
    int start = (digits - 2) / 2;
    int end = start + 2;
    int hash = 0;
    for (int i = start; i <= end; i++) {
        int digit = (square / (int)pow(10, i)) % 10;
        hash = hash * 10 + digit;
    }
    return hash % TABLE_SIZE;
}

void insert(Employee emp) {
    int index = hash(emp.id);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->emp = emp;
    newNode->next = NULL;
    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        Node* curr = hashTable[index];
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

void search(int id) {
    int index = hash(id);
    Node* curr = hashTable[index];
    while (curr != NULL) {
        if (curr->emp.id == id) {
            printf("Employee found:\n");
            printf("ID: %d\n", curr->emp.id);
            printf("Name: %s\n", curr->emp.name);
            printf("Salary: %.2f\n", curr->emp.salary);
            return;
        }
        curr = curr->next;
    }
    printf("Employee not found.\n");
}

int main() {
    // Initialize hash table
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }

    // Insert employees from user input
    int numEmployees;
    printf("Enter number of employees to insert: ");
    scanf("%d", &numEmployees);
    for (int i = 0; i < numEmployees; i++) {
        Employee emp;
        printf("Enter employee ID: ");
        scanf("%d", &emp.id);
        printf("Enter employee name: ");
        scanf("%s", emp.name);
        printf("Enter employee salary: ");
        scanf("%f", &emp.salary);
        insert(emp);
    }

    // Search for an employee by ID
    int searchId;
    printf("Enter employee ID to search for: ");
    scanf("%d", &searchId);
    search(searchId);

    return 0;
}