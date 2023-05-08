/*WAP to store k keys into an array of size n at the location
computed using a hash function, loc = key % n, where k<=n and k
takes values from [1 to m], m>n. To handle the collisions use the
following collision resolution techniques, a. Linear probing with
chaining b. Rehashing technique.*/


#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// structure to store key-value pairs
struct hash_node {
    int key;
    int value;
    struct hash_node *next;
};

// function to calculate hash index
int hash(int key, int size) {
    return key % size;
}

// function to insert a key-value pair using linear probing with chaining
void insert_lp(struct hash_node **hash_table, int key, int value, int size) {
    int index = hash(key, size);
    if (hash_table[index] == NULL) {
        // if bucket is empty, create new node
        hash_table[index] = (struct hash_node *)malloc(sizeof(struct hash_node));
        hash_table[index]->key = key;
        hash_table[index]->value = value;
        hash_table[index]->next = NULL;
    } else {
        // if bucket is not empty, add new node to the end of the chain
        struct hash_node *temp = hash_table[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = (struct hash_node *)malloc(sizeof(struct hash_node));
        temp->next->key = key;
        temp->next->value = value;
        temp->next->next = NULL;
    }
}

// function to search for a key in the hash table using linear probing with chaining
int search_lp(struct hash_node **hash_table, int key, int size) {
    int index = hash(key, size);
    struct hash_node *temp = hash_table[index];
    while (temp != NULL) {
        if (temp->key == key) {
            return temp->value;
        }
        temp = temp->next;
    }
    return -1;
}

// function to insert a key-value pair using rehashing
void insert_rehash(struct hash_node **hash_table, int key, int value, int size) {
    int index = hash(key, size);
    if (hash_table[index] == NULL) {
        // if bucket is empty, create new node
        hash_table[index] = (struct hash_node *)malloc(sizeof(struct hash_node));
        hash_table[index]->key = key;
        hash_table[index]->value = value;
        hash_table[index]->next = NULL;
    } else {
        // if bucket is not empty, calculate new index using rehashing
        int i = 1;
        while (1) {
            int new_index = (index + i) % size;
            if (hash_table[new_index] == NULL) {
                // if new bucket is empty, create new node
                hash_table[new_index] = (struct hash_node *)malloc(sizeof(struct hash_node));
                hash_table[new_index]->key = key;
                hash_table[new_index]->value = value;
                hash_table[new_index]->next = NULL;
                break;
            } else {
                // if new bucket is not empty, continue rehashing
                i++;
            }
        }
    }
}

// function to search for a key in the hash table using rehashing
int search_rehash(struct hash_node **hash_table, int key, int size) {
    int index = hash(key, size);
    int i = 1;
    while (1) {
        int new_index = (index + i) % size;
        if (hash_table[new_index] == NULL) {
            return -1;
        } else if (hash_table[new_index]->key == key) {
            return hash_table[new_index]->value;
        } else {
            i++;
        }
    }
}

int main() {
    int size, k, i, key, value;
    printf("Enter size of hash table: ");
    scanf("%d", &size);
    struct hash_node *hash_table[MAX_SIZE] = {NULL}; // initialize hash table to NULL
    printf("Enter number of keys to insert (<= %d): ", size);
    scanf("%d", &k);
    printf("Enter keys and values:\n");
    for (i = 0; i < k; i++) {
        scanf("%d %d", &key, &value);
        // insert key-value pair using linear probing with chaining
        //insert_lp(hash_table, key, value, size);
        
        // insert key-value pair using rehashing
        insert_rehash(hash_table, key, value, size);
    }
    printf("Enter key to search: ");
    scanf("%d", &key);
    // search for key using linear probing with chaining
    //int result = search_lp(hash_table, key, size);
    
    // search for key using rehashing
    int result = search_rehash(hash_table, key, size);
    if (result == -1) {
        printf("Key not found\n");
    } else {
        printf("Value for key %d is %d\n", key, result);
    }
    return 0;
}

   
