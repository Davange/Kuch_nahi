/*WAP to simulate faculty database as a hash table. Search a
perticular faculty by using 'divide' as a hash function for linear
probing with chaining without replcament method of collision
handling technique. Assume suitable data for faculty record.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10
#define MAX_NAME_LENGTH 20

// define the faculty structure
typedef struct faculty {
    int id;
    char name[MAX_NAME_LENGTH];
    struct faculty* next;
} faculty_t;

// initialize the hash table
void initialize_table(faculty_t* table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = NULL;
    }
}

// hash function using 'divide' method
int hash_function(int id) {
    return id % TABLE_SIZE;
}

// insert a faculty member into the hash table
void insert(faculty_t* table[], int id, char name[]) {
    // create a new faculty member
    faculty_t* new_faculty = (faculty_t*) malloc(sizeof(faculty_t));
    new_faculty->id = id;
    strncpy(new_faculty->name, name, MAX_NAME_LENGTH);
    new_faculty->next = NULL;

    // calculate the hash value
    int hash_value = hash_function(id);

    // check if the slot is empty
    if (table[hash_value] == NULL) {
        table[hash_value] = new_faculty;
    } else {
        // handle collision with chaining without replacement
        faculty_t* current = table[hash_value];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_faculty;
    }
}

// search for a faculty member in the hash table
faculty_t* search(faculty_t* table[], int id) {
    // calculate the hash value
    int hash_value = hash_function(id);

    // traverse the linked list at the hash value
    faculty_t* current = table[hash_value];
    while (current != NULL && current->id != id) {
        current = current->next;
    }

    return current;
}

// print the hash table
void print_table(faculty_t* table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Slot %d: ", i);
        faculty_t* current = table[i];
        while (current != NULL) {
            printf("(%d, %s) -> ", current->id, current->name);
            current = current->next;
        }
        printf("NULL\n");
    }
}

// main function
int main() {
    // initialize the hash table
    faculty_t* table[TABLE_SIZE];
    initialize_table(table);

    // insert some faculty members
    insert(table, 1001, "John Doe");
    insert(table, 1002, "Jane Smith");
    insert(table, 1003, "Alice Johnson");
    insert(table, 1004, "Bob Williams");
    insert(table, 1005, "Charlie Brown");

    // search for a faculty member
    int id = 1003;
    faculty_t* result = search(table, id);
    if (result == NULL) {
        printf("Faculty member with ID %d not found.\n", id);
    } else {
        printf("Faculty member with ID %d found: (%d, %s)\n", id, result->id, result->name);
    }

    // print the hash table
    print_table(table);

    return 0;
}
