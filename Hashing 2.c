/*WAP to simulate faculty database as a hash table. Search a
particular faculty by using 'divide' as a hash function for linear
probing with chaining without replacement method of collision
handling technique. Assume suitable data for faculty record.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10 // maximum size of hash table

// faculty record structure
struct faculty {
    char name[20];
    int age;
    char department[20];
    struct faculty *next; // pointer to next faculty record in the same bucket
};

// hash table node structure
struct hash_node {
    int key;
    struct faculty *head; // pointer to first faculty record in the bucket
};

// hash function (using divide)
int hash(int key) {
    return key % MAX_SIZE;
}

// insert a faculty record into hash table
void insert(struct hash_node hash_table[], int key, struct faculty f) {
    int index = hash(key);
    struct faculty *new_faculty = (struct faculty *) malloc(sizeof(struct faculty));
    if (new_faculty == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    strcpy(new_faculty->name, f.name);
    new_faculty->age = f.age;
    strcpy(new_faculty->department, f.department);
    new_faculty->next = NULL;
    if (hash_table[index].head == NULL) {
        hash_table[index].key = key;
        hash_table[index].head = new_faculty;
    } else {
        struct faculty *current = hash_table[index].head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_faculty;
    }
}

// search for a faculty record in hash table
void search(struct hash_node hash_table[], int key) {
    int index = hash(key);
    struct faculty *current = hash_table[index].head;
    while (current != NULL) {
        if (hash_table[index].key == key) {
            printf("Name: %s\n", current->name);
            printf("Age: %d\n", current->age);
            printf("Department: %s\n", current->department);
            return;
        }
        current = current->next;
    }
    printf("Faculty not found.\n");
}

int main() {
    struct hash_node hash_table[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) {
        hash_table[i].key = -1; // initialize hash table
        hash_table[i].head = NULL;
    }
    int choice, key;
    struct faculty f;
    do {
        printf("\n1. Insert faculty record\n");
        printf("2. Search faculty record\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter faculty name: ");
                scanf("%s", f.name);
                printf("Enter faculty age: ");
                scanf("%d", &f.age);
                printf("Enter faculty department: ");
                scanf("%s", f.department);
                printf("Enter key: ");
                scanf("%d", &key);
                insert(hash_table, key, f);
                break;
            case 2:
                printf("Enter key: ");
                scanf("%d", &key);
                search(hash_table, key);
                break;
            case 3:
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 3);
    return 0;
}
