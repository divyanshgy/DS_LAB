#include <stdio.h>
#include <stdlib.h>

// Structure for a polynomial term
struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
};

// Function to create a new polynomial term
struct Term* createTerm(int coefficient, int exponent) {
    struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL;
    return newTerm;
}

// Function to add two polynomials
struct Term* addPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = NULL;
    struct Term* current = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exponent == poly2->exponent) {
            int sumCoefficient = poly1->coefficient + poly2->coefficient;
            if (sumCoefficient != 0) {
                struct Term* newTerm = createTerm(sumCoefficient, poly1->exponent);
                if (result == NULL) {
                    result = newTerm;
                    current = newTerm;
                } else {
                    current->next = newTerm;
                    current = newTerm;
                }
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        } else if (poly1->exponent > poly2->exponent) {
            struct Term* newTerm = createTerm(poly1->coefficient, poly1->exponent);
            if (result == NULL) {
                result = newTerm;
                current = newTerm;
            } else {
                current->next = newTerm;
                current = newTerm;
            }
            poly1 = poly1->next;
        } else {
            struct Term* newTerm = createTerm(poly2->coefficient, poly2->exponent);
            if (result == NULL) {
                result = newTerm;
                current = newTerm;
            } else {
                current->next = newTerm;
                current = newTerm;
            }
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL) {
        struct Term* newTerm = createTerm(poly1->coefficient, poly1->exponent);
        if (result == NULL) {
            result = newTerm;
            current = newTerm;
        } else {
            current->next = newTerm;
            current = newTerm;
        }
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        struct Term* newTerm = createTerm(poly2->coefficient, poly2->exponent);
        if (result == NULL) {
            result = newTerm;
            current = newTerm;
        } else {
            current->next = newTerm;
            current = newTerm;
        }
        poly2 = poly2->next;
    }

    return result;
}

// Function to display a polynomial
void displayPolynomial(struct Term* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }

    while (poly != NULL) {
        if (poly->coefficient > 0) {
            printf("+%dx^%d", poly->coefficient, poly->exponent);
        } else {
            printf("%dx^%d", poly->coefficient, poly->exponent);
        }
        poly = poly->next;
    }
    printf("\n");
}

// Function to free the memory used by a polynomial
void freePolynomial(struct Term* poly) {
    struct Term* temp;
    while (poly != NULL) {
        temp = poly;
        poly = poly->next;
        free(temp);
    }
}

int main() {
    struct Term* poly1 = NULL;
    struct Term* poly2 = NULL;

    int coefficient, exponent;

    // Input polynomial 1
    printf("Enter Polynomial 1 (Enter 0 0 to finish):\n");
    while (1) {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coefficient, &exponent);
        if (coefficient == 0 && exponent == 0) {
            break;
        }
        struct Term* term = createTerm(coefficient, exponent);
        if (poly1 == NULL) {
            poly1 = term;
        } else {
            term->next = poly1;
            poly1 = term;
        }
    }

    // Input polynomial 2
    printf("Enter Polynomial 2 (Enter 0 0 to finish):\n");
    while (1) {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coefficient, &exponent);
        if (coefficient == 0 && exponent == 0) {
            break;
        }
        struct Term* term = createTerm(coefficient, exponent);
        if (poly2 == NULL) {
            poly2 = term;
        } else {
            term->next = poly2;
            poly2 = term;
        }
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
