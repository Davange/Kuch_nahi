/*WAP to store k keys into an array of size n at the location
computed using a hash function, loc = key / n, where k<=n and k
takes values from [1 to m], m>n. To handle the collisions use the
following collision resolution techniques, a. Linear probing with
chaining with replacement b. Quadratic probing technique.*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_KEYS 100

typedef struct Node {
    int key;
    int value;
    struct Node *next;
} Node;

Node *hash_table[MAX_KEYS];

int hash(int key, int n) {
    return key / n;
}

void insert_linear_chaining_replacement(int key, int value, int n) {
    int index = hash(key, n);
    Node *node = (Node *) malloc(sizeof(Node));
    node->key = key;
    node->value = value;
    node->next = NULL;

    if (hash_table[index] == NULL) {
        hash_table[index] = node;
    } else {
        Node *temp = hash_table[index];
        Node *prev = NULL;
        while (temp != NULL) {
            if (temp->key == key) {
                temp->value = value;
                free(node);
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        prev->next = node;
    }
}

void insert_quadratic_probing(int key, int value, int n) {
    int index = hash(key, n);
    int i = 1;
    while (hash_table[index] != NULL && hash_table[index]->key != key) {
        index = (index + i * i) % n;
        i++;
    }
    if (hash_table[index] == NULL) {
        Node *node = (Node *) malloc(sizeof(Node));
        node->key = key;
        node->value = value;
        node->next = NULL;
        hash_table[index] = node;
    } else {
        hash_table[index]->value = value;
    }
}

void print_hash_table(int n) {
    printf("Hash Table:\n");
    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        if (hash_table[i] != NULL) {
            Node *temp = hash_table[i];
            while (temp != NULL) {
                printf("(%d, %d) -> ", temp->key, temp->value);
                temp = temp->next;
            }
        }
        printf("NULL\n");
    }
}

int main() {
    int n, m, choice;
    printf("Enter the size of the hash table: ");
    scanf("%d", &n);
    printf("Enter the number of keys to insert (<= %d): ", n);
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        int key, value;
        printf("Enter key and value for element %d: ", i + 1);
        scanf("%d %d", &key, &value);
        printf("Choose collision resolution technique:\n");
        printf("1. Linear probing with chaining with replacement\n");
        printf("2. Quadratic probing\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            insert_linear_chaining_replacement(key, value, n);
        } else if (choice == 2) {
            insert_quadratic_probing(key, value, n);
        } else {
            printf("Invalid choice. Element not inserted.\n");
        }
    }

    print_hash_table(n);

    return 0;
}
