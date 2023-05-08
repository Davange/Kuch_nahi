/*Consider two sets of integers, S = {s1, s2, ..., sm} and T = {t1, t2,
..., tn}, m ≤ n. Implement an algorithm that uses a hash table of
size m to test whether S is a subset of T.*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10

typedef struct DataItem {
    int data;
    int key;
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

    int hashIndex = hashCode(key);
    while (hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) {
        ++hashIndex;
        hashIndex %= SIZE;
    }

    hashArray[hashIndex] = item;
}

DataItem* search(int key) {
    int hashIndex = hashCode(key);

    while (hashArray[hashIndex] != NULL) {
        if (hashArray[hashIndex]->key == key) {
            return hashArray[hashIndex];
        }
        ++hashIndex;
        hashIndex %= SIZE;
    }

    return NULL;
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        if (hashArray[i] != NULL) {
            printf("(%d,%d)", hashArray[i]->key, hashArray[i]->data);
        } else {
            printf("~~");
        }
    }
    printf("\n");
}

int main() {
    // Initialize hash table
    for (int i = 0; i < SIZE; i++) {
        hashArray[i] = NULL;
    }
    dummyItem = (DataItem*) malloc(sizeof(DataItem));
    dummyItem->data = -1;
    dummyItem->key = -1;

    // Get input for sets S and T
    int m, n;
    printf("Enter size of set S: ");
    scanf("%d", &m);
    int S[m];
    printf("Enter elements of set S: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &S[i]);
        insert(S[i], 1);
    }
    printf("Enter size of set T: ");
    scanf("%d", &n);
    int T[n];
    printf("Enter elements of set T: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &T[i]);
    }

    // Test if S is a subset of T
    bool isSubset = true;
    for (int i = 0; i < n; i++) {
        if (search(T[i]) == NULL) {
            isSubset = false;
            break;
        }
    }

    // Print result
    if (isSubset) {
        printf("S is a subset of T.\n");
    } else {
        printf("S is not a subset of T.\n");
    }

    return 0;
}