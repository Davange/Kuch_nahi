/*WAP to simulate faculty database as a hash table. Search a
particular faculty by using MOD as a hash function for linear
probing method of collision handling technique. Assume
suitable data for faculty record.*/
#include <stdio.h>
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
    struct faculty f;
};

// hash function (using mod)
int hash(int key) {
    return key % MAX_SIZE;
}

// insert a faculty record into hash table
void insert(struct hash_node hash_table[], int key, struct faculty f) {
    int index = hash(key);
    while (hash_table[index].key != -1) { // linear probing
        index = (index + 1) % MAX_SIZE;
    }
    hash_table[index].key = key;
    hash_table[index].f = f;
}

// search for a faculty record in hash table
void search(struct hash_node hash_table[], int key) {
    int index = hash(key);
    while (hash_table[index].key != -1) { // linear probing
        if (hash_table[index].key == key) {
            printf("Name: %s\n", hash_table[index].f.name);
            printf("Age: %d\n", hash_table[index].f.age);
            printf("Department: %s\n", hash_table[index].f.department);
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
