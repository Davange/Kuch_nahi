/*WAP to store k keys into an array of size n at the location
computed using a hash function, loc = key / n, where k<=n and k
takes values from [1 to m], m>n. To handle the collisions use the
following collision resolution techniques, a. Linear probing with
chaining with replacement b. Quadratic probing technique.*/


#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct DataItem {
    int data;
    int key;
    struct DataItem* next;
} DataItem;

DataItem* hashArray[SIZE];
DataItem* dummyItem;

int hashCode(int key) {
    return key % SIZE;
}

void insert(int key, int data) {
    DataItem* item = (DataItem*) malloc(sizeof(DataItem));
    item->data = data;
    item->key = key;
    item->next = NULL;

    int hashIndex = hashCode(key);
    if (hashArray[hashIndex] == NULL) {
        hashArray[hashIndex] = item;
    } else {
        DataItem* curr = hashArray[hashIndex];
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = item;
    }
}

DataItem* search(int key) {
    int hashIndex = hashCode(key);

    DataItem* curr = hashArray[hashIndex];
    while (curr != NULL) {
        if (curr->key == key) {
            return curr;
        }
        curr = curr->next;
    }

    return NULL;
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        printf("%d: ", i);
        DataItem* curr = hashArray[i];
        while (curr != NULL) {
            printf("(%d,%d) ", curr->key, curr->data);
            curr = curr->next;
        }
        printf("\n");
    }
}

int main() {
    // Initialize hash table
    for (int i = 0; i < SIZE; i++) {
        hashArray[i] = NULL;
    }
    dummyItem = (DataItem*) malloc(sizeof(DataItem));
    dummyItem->data = -1;
    dummyItem->key = -1;
    dummyItem->next = NULL;

    // Get input for k and n
    int k, n;
    printf("Enter value of k (number of keys to insert): ");
    scanf("%d", &k);
    printf("Enter value of n (size of array): ");
    scanf("%d", &n);

    // Get input for keys
    int keys[k];
    printf("Enter %d keys: ", k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &keys[i]);
    }

    // Insert keys into hash table
    for (int i = 0; i < k; i++) {
        int loc = keys[i] / n;
        insert(loc, keys[i]);
    }

    // Display hash table
    display();

    return 0;
}