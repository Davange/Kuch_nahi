/*WAP to simulate faculty database as a hash table. Search a
perticular faculty by using MOD as a hash function for linear
probing with chaining with replacement method of collision
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
};

// hash table node structure
struct hash_node {
    int key;
    struct faculty *record; // pointer to faculty record in the bucket
};

// hash function (using mod)
int hash(int key) {
    return key % MAX_SIZE;
}

// insert a faculty record into hash table
void insert(struct hash_node hash_table[], int key, struct faculty f) {
    int index = hash(key);
    if (hash_table[index].record == NULL) {
        hash_table[index].key = key;
        hash_table[index].record = (struct faculty *) malloc(sizeof(struct faculty));
        if (hash_table[index].record == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }
        strcpy(hash_table[index].record->name, f.name);
        hash_table[index].record->age = f.age;
        strcpy(hash_table[index].record->department, f.department);
    } else {
        while (hash_table[index].record != NULL) {
            index = (index + 1) % MAX_SIZE;
        }
        hash_table[index].key = key;
        hash_table[index].record = (struct faculty *) malloc(sizeof(struct faculty));
        if (hash_table[index].record == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }
        strcpy(hash_table[index].record->name, f.name);
        hash_table[index].record->age = f.age;
        strcpy(hash_table[index].record->department, f.department);
    }
}

// search for a faculty record in hash table
void search(struct hash_node hash_table[], int key) {
    int index = hash(key);
    while (hash_table[index].record != NULL) {
        if (hash_table[index].key == key) {
            printf("Name: %s\n", hash_table[index].record->name);
            printf("Age: %d\n", hash_table[index].record->age);
            printf("Department: %s\n", hash_table[index].record->department);
            return;
        }
        index = (index + 1) % MAX_SIZE;
    }
    printf("Faculty not found.\n");
}

int main() {
    struct hash_node hash_table[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) {
        hash_table[i].key = -1; // initialize hash table
        hash_table[i].record = NULL;
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
            break;
    }
} while (choice != 3);
// free memory allocated for faculty records
for (int i = 0; i < MAX_SIZE; i++) {
    if (hash_table[i].record != NULL) {
        free(hash_table[i].record);
    }
}
return 0;
}
               
