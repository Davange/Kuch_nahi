/*Write a Program to create a Binary Tree and perform following
nonrecursive operations on it. a. Levelwise display b. Mirror
image c. Display height of a tree.*/

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct queue {
    struct node* arr[100];
    int front;
    int rear;
};

void enqueue(struct queue* q, struct node* newNode) {
    q->arr[++q->rear] = newNode;
}

struct node* dequeue(struct queue* q) {
    return q->arr[++q->front];
}

int isEmpty(struct queue* q) {
    if(q->front == q->rear) {
        return 1;
    }
    return 0;
}

void levelwiseDisplay(struct node* root) {
    if(root == NULL) {
        return;
    }
    struct queue q;
    q.front = -1;
    q.rear = -1;
    enqueue(&q, root);
    while(!isEmpty(&q)) {
        struct node* curr = dequeue(&q);
        printf("%d ", curr->data);
        if(curr->left != NULL) {
            enqueue(&q, curr->left);
        }
        if(curr->right != NULL) {
            enqueue(&q, curr->right);
        }
    }
}

void mirrorImage(struct node* root) {
    if(root == NULL) {
        return;
    }
    mirrorImage(root->left);
    mirrorImage(root->right);
    struct node* temp = root->left;
    root->left = root->right;
    root->right = temp;
}

int height(struct node* root) {
    if(root == NULL) {
        return -1;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    if(leftHeight > rightHeight) {
        return leftHeight + 1;
    }
    else {
        return rightHeight + 1;
    }
}

int main() {
    struct node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    printf("Level-wise display of the tree: ");
    levelwiseDisplay(root);
    printf("\n");
    printf("Mirror image of the tree: ");
    mirrorImage(root);
    levelwiseDisplay(root);
    printf("\n");
    printf("Height of the tree: %d\n", height(root));
    return 0;
}
