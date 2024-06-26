#include <stdio.h>
#include <stdlib.h>

// Structure for a polynomial term
struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
    struct Term* prev;
};

// Function to create a new polynomial term
struct Term* createTerm(int coefficient, int exponent) {
    struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = newTerm;
    newTerm->prev = newTerm;
    return newTerm;
}

// Function to insert a new term after a given term
void insertAfter(struct Term* term, struct Term* newTerm) {
    newTerm->next = term->next;
    newTerm->prev = term;
    term->next->prev = newTerm;
    term->next = newTerm;
}

// Function to add two polynomials
struct Term* addPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = createTerm(0, 0);

    struct Term* current1 = poly1->next;
    struct Term* current2 = poly2->next;

    while (current1 != poly1 && current2 != poly2) {
        if (current1->exponent == current2->exponent) {
            int sumCoeff = current1->coefficient + current2->coefficient;
            if (sumCoeff != 0) {
                struct Term* newTerm = createTerm(sumCoeff, current1->exponent);
                insertAfter(result->prev, newTerm);
            }
            current1 = current1->next;
            current2 = current2->next;
        } else if (current1->exponent < current2->exponent) {
            struct Term* newTerm = createTerm(current1->coefficient, current1->exponent);
            insertAfter(result->prev, newTerm);
            current1 = current1->next;
        } else {
            struct Term* newTerm = createTerm(current2->coefficient, current2->exponent);
            insertAfter(result->prev, newTerm);
            current2 = current2->next;
        }
    }

    while (current1 != poly1) {
        struct Term* newTerm = createTerm(current1->coefficient, current1->exponent);
        insertAfter(result->prev, newTerm);
        current1 = current1->next;
    }

    while (current2 != poly2) {
        struct Term* newTerm = createTerm(current2->coefficient, current2->exponent);
        insertAfter(result->prev, newTerm);
        current2 = current2->next;
    }

    return result;
}

// Function to display a polynomial
void displayPolynomial(struct Term* poly) {
    struct Term* current = poly->next;
    int firstTerm = 1;
    while (current != poly) {
        if (current->coefficient != 0) {
            if (firstTerm) {
                firstTerm = 0;
                if (current->coefficient < 0) {
                    printf("-");
                }
            } else {
                if (current->coefficient > 0) {
                    printf("+");
                }
            }
            printf("%d", abs(current->coefficient));
            if (current->exponent > 0) {
                printf("x");
                if (current->exponent > 1) {
                    printf("^%d", current->exponent);
                }
            }
        }
        current = current->next;
    }
    printf("\n");
}

// Function to free the memory used by a polynomial
void freePolynomial(struct Term* poly) {
    struct Term* current = poly->next;
    while (current != poly) {
        struct Term* temp = current;
        current = current->next;
        free(temp);
    }
    free(poly);
}

int main() {
    struct Term* poly1 = createTerm(0, 0); // Create a dummy header node
    struct Term* poly2 = createTerm(0, 0);

    int coefficient, exponent;
    int numTerms;

    // Input polynomial 1
    printf("Enter the number of terms in Polynomial 1: ");
    scanf("%d", &numTerms);
    for (int i = 0; i < numTerms; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coefficient, &exponent);
        struct Term* newTerm = createTerm(coefficient, exponent);
        insertAfter(poly1->prev, newTerm);
    }

    // Input polynomial 2
    printf("Enter the number of terms in Polynomial 2: ");
    scanf("%d", &numTerms);
    for (int i = 0; i < numTerms; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coefficient, &exponent);
        struct Term* newTerm = createTerm(coefficient, exponent);
        insertAfter(poly2->prev, newTerm);
    }

    // Add and display the result
    struct Term* result = addPolynomials(poly1, poly2);
    printf("Resultant Polynomial: ");
    displayPolynomial(result);

    // Free memory
    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(result);

    return 0;
}
