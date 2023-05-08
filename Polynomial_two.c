#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff;
    int exp;
    struct node *next;
};

void insert_term(struct node **head, int coeff, int exp) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->coeff = coeff;
    new_node->exp = exp;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
    } else {
        struct node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void add_polynomials(struct node *p1, struct node *p2, struct node **sum) {
    while (p1 != NULL && p2 != NULL) {
        if (p1->exp == p2->exp) {
            insert_term(sum, p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->exp > p2->exp) {
            insert_term(sum, p1->coeff, p1->exp);
            p1 = p1->next;
        } else {
            insert_term(sum, p2->coeff, p2->exp);
            p2 = p2->next;
        }
    }
    while (p1 != NULL) {
        insert_term(sum, p1->coeff, p1->exp);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        insert_term(sum, p2->coeff, p2->exp);
        p2 = p2->next;
    }
}

void display(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%dx^%d ", temp->coeff, temp->exp);
        if (temp->next != NULL) {
            printf("+ ");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node *poly1 = NULL;
    struct node *poly2 = NULL;
    struct node *sum = NULL;
    int n, i, coeff, exp;

    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n);
    printf("Enter the coefficients and exponents of each term in the first polynomial:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        insert_term(&poly1, coeff, exp);
    }

    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n);
    printf("Enter the coefficients and exponents of each term in the second polynomial:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        insert_term(&poly2, coeff, exp);
    }

    printf("The first polynomial is: ");
    display(poly1);

    printf("The second polynomial is: ");
    display(poly2);

    add_polynomials(poly1, poly2, &sum);

    printf("The sum of the polynomials is: ");
    display(sum);

    return 0;
}
