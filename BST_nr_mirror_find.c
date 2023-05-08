/*Here's a program in C to illustrate operations on a binary search tree holding numeric keys. The menu includes:
• Insert
• Mirror Image
• Find
• Post order (nonrecursive)*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *left, *right;
};

struct node *newNode(int item) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void insert(struct node **root, int key) {
    if (*root == NULL) {
        *root = newNode(key);
        return;
    }
    if (key < (*root)->key) {
        insert(&(*root)->left, key);
    } else if (key > (*root)->key) {
        insert(&(*root)->right, key);
    }
}

void mirror(struct node *root) {
    if (root == NULL) {
        return;
    }
    mirror(root->left);
    mirror(root->right);
    struct node *temp = root->left;
    root->left = root->right;
    root->right = temp;
}

struct node *find(struct node *root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }
    if (key < root->key) {
        return find(root->left, key);
    }
    return find(root->right, key);
}

void postorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    struct node **stack;
    stack = (struct node **)malloc(100 * sizeof(struct node *));

    int top = -1;
    do {
        while (root != NULL) {
            if (root->right != NULL) {
                stack[++top] = root->right;
            }
            stack[++top] = root;
            root = root->left;
        }
        root = stack[top--];
        if (root->right != NULL && stack[top] == root->right) {
            stack[top--] = root;
            root = root->right;
        } else {
            printf("%d ", root->key);
            root = NULL;
        }
    } while (top != -1);
}

void printMenu() {
    printf("\nMenu:\n");
    printf("1. Insert\n");
    printf("2. Mirror Image\n");
    printf("3. Find\n");
    printf("4. Post order (nonrecursive)\n");
    printf("5. Exit\n");
}

int main() {
    struct node *root = NULL;
    int choice, key;
    while (1) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(&root, key);
                break;
            case 2:
                mirror(root);
                break;
            case 3:
                printf("Enter key to find: ");
                scanf("%d", &key);
                if (find(root, key) != NULL) {
                    printf("Key found\n");
                } else {
                    printf("Key not found\n");
                }
                break;
            case 4:
                printf("Post order traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}