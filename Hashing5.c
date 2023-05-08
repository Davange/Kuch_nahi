/*WAP to simulate employee database as a hash table. Search a
perticular faculty by using Mid suquare method as a hash
function for linear probing method of collision handling
technique. Assume suitable data for faculty record.*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Employee structure
struct employee {
    int id;
    char name[50];
    int salary;
};

// Hash table node
struct hash_node {
    int key; // hash key
    struct employee emp; // employee data
};

// Mid-Square hash function
int mid_square(int key, int size) {
    int square = key * key;
    int mid = (square / 100) % 10000; // get 4 middle digits
    return mid % size;
}

// Insert employee into hash table using linear probing
void insert_lp(struct hash_node *hash_table[], struct employee emp, int size) {
    int i, key, index;
    key = emp.id;
    index = mid_square(key, size);
    for (i = 0; i < size; i++) {
        if (hash_table[index] == NULL) {
            // insert employee if slot is empty
            hash_table[index] = malloc(sizeof(struct hash_node));
            hash_table[index]->key = key;
            hash_table[index]->emp = emp;
            printf("Employee with ID %d inserted at index %d\n", key, index);
            return;
        } else if (hash_table[index]->key == key) {
            // update employee if already exists
            hash_table[index]->emp = emp;
            printf("Employee with ID %d updated at index %d\n", key, index);
            return;
        } else {
            // move to next slot using linear probing
            index = (index + 1) % size;
        }
    }
    printf("Error: Hash table is full\n");
}

// Search for employee in hash table using linear probing
struct employee search_lp(struct hash_node *hash_table[], int key, int size) {
    int i, index;
    index = mid_square(key, size);
    for (i = 0; i < size; i++) {
        if (hash_table[index] == NULL) {
            // employee not found
            break;
        } else if (hash_table[index]->key == key) {
            // employee found
            return hash_table[index]->emp;
        } else {
            // move to next slot using linear probing
            index = (index + 1) % size;
        }
    }
    // employee not found
    struct employee emp_not_found = {-1, "Not Found", -1};
    return emp_not_found;
}

// Main function
int main() {
    int size, k, i, id;
    struct employee emp;
    printf("Enter size of hash table: ");
    scanf("%d", &size);
    struct hash_node *hash_table[MAX_SIZE] = {NULL}; // initialize hash table to NULL
    printf("Enter number of employees to insert: ");
    scanf("%d", &k);
    printf("Enter employee data (ID, Name, Salary):\n");
    for (i = 0; i < k; i++) {
        scanf("%d %s %d", &emp.id, emp.name, &emp.salary);
        insert_lp(hash_table, emp, size);
    }
    printf("Enter employee ID to search: ");
    scanf("%d", &id);
    emp = search_lp(hash_table, id, size);
    if (emp.id == -1) {
        printf("Employee not found\n");
    } else {
        printf("Employee with ID %d:\nName: %s\nSalary: %d\n", emp.id, emp.name, emp.salary);
    }
    return 0;
}
